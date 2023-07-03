#ifndef _TRIMUS_UTILS_H_
#define _TRIMUS_UTILS_H_
#include <SDL/SDL.h>
#include "SDL/SDL_ttf.h"

#define ALIGN_LEFT 0
#define ALIGN_CENTER 1
#define ALIGN_RIGHT 2

int draw_menu_string(SDL_Surface *dst, TTF_Font *font, SDL_Rect rect, const char *str, SDL_Color color, int align, int shadow);

#endif