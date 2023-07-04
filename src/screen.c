/*
 *  Copyright (C) 2021 Steward Fu
 *  Copyright (C) 2001 Peponas Mathieu
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>

#include "emu.h"
#include "conf.h"
#include "font.h"
#include "video.h"
#include "gnutil.h"
#include "screen.h"

SDL_Surface *buffer = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *fontbuf = NULL;
SDL_Rect visible_area = {0};

static SDL_Rect drt = {0, 0, 320, 224};
static SDL_Rect left_border = {16, 16, 8, 224};
static SDL_Rect right_border = {16 + 312, 16, 8, 224};

void screen_flip(void)
{
  //SDL_FillRect(buffer, &left_border, 0);
  //SDL_FillRect(buffer, &right_border, 0);
  SDL_BlitSurface(buffer, &visible_area, screen, &drt);

  uint16_t *s = buffer->pixels;
  uint16_t *d = screen->pixels;

  //d = (uint16_t*)screen->pixels + 16*240;

  for (int y = 0; y < 240; y++) {
      for (int x = 0; x < 320; x++) {
          d[((239 - y) * 320) + (319 - x)] = s[(y * 352) + x];
      }
  }

  //SDL_SoftStretch(screen, NULL, buffer, NULL);

  SDL_Flip(screen);
}

void sdl_init(void)
{
  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);

  visible_area.x = 16;
  visible_area.y = 16;
  visible_area.w = 320;
  visible_area.h = 224;

  screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE | SDL_DOUBLEBUF);
  SDL_ShowCursor(SDL_DISABLE);

  buffer = SDL_CreateRGBSurface(SDL_SWSURFACE, 352, 256, 16, 0xf800, 0x7e0, 0x1f, 0);
  SDL_FillRect(buffer, NULL, SDL_MapRGB(buffer->format, 0xe5, 0xe5, 0xe5));

  fontbuf = SDL_CreateRGBSurfaceFrom(font_image.pixel_data, font_image.width, font_image.height, 24, font_image.width * 3, 0xff0000, 0xff00, 0xff, 0);
  fontbuf = SDL_DisplayFormat(fontbuf);
}

