#ifndef __SKIN_H__
#define __SKIN_H__
#include "SDL/SDL.h"

#ifndef X86
#ifdef UPDATE_UI
#define PATH_PREFIX "/usr/res/"
#else
#define PATH_PREFIX "/usr/trimui/res/"
#endif
#else
#define PATH_PREFIX "./"
#endif

#define BACKGROUND_PATH     PATH_PREFIX"skin/background.png"
#ifdef THEME_BLUE
#define BACKGROUND2_PATH    PATH_PREFIX"skin/bg-cloud.png"
#else
#define BACKGROUND2_PATH    ""
#endif//THEME_BLUE
#define PROGRESS_LEFT       PATH_PREFIX"skin/loading-progress-left.png"
#define PROGRESS_MIDDLE     PATH_PREFIX"skin/loading-progress-mid.png"
#define PROGRESS_RIGHT      PATH_PREFIX"skin/loading-progress-right.png"
#define PROGRESS_BG         PATH_PREFIX"skin/loading-bg.png"

#ifdef UPDATE_UI

#ifdef THEME_POWKIDDY
#define FONT_PATH           PATH_PREFIX"Exo-Black.otf"
#else
#define FONT_PATH           PATH_PREFIX"BPreplayBold.otf"
#endif //FONT_PATH

#else
#define FONT_PATH           PATH_PREFIX"wqy-microhei.ttc"
//#define FONT_PATH           PATH_PREFIX"NotoSansCJK-Black-7009.TTF"
#endif //THEME_POWKIDDY

#ifdef THEME_POWKIDDY
#define TITLE_FONT_PATH PATH_PREFIX"Exo-Black.otf"
#else
#define TITLE_FONT_PATH PATH_PREFIX"BPreplayBold.otf"
#endif //THEME_POWKIDDY

#define MENUBG_PATH     PATH_PREFIX"skin/menu-5line-bg.png"
#define NAVBG_PATH      PATH_PREFIX"skin/navbg.png"
#define STATBG_PATH     PATH_PREFIX"skin/statbg.png"
//#define BARBG_PATH      PATH_PREFIX"skin/barbg.png"

#ifndef THEME_POWKIDDY
#define SELBG_PATH      PATH_PREFIX"skin/list-item-select-bg-short.png"
#else
#define SELBG_PATH      ""
#endif//THEME_POWKIDDY

#define THUMBBG_PATH    PATH_PREFIX"skin/menu-sub-bg.png"
#define LEFTARROW_PATH  PATH_PREFIX"skin/left-arrow-small.png"
#define RIGHTARROW_PATH PATH_PREFIX"skin/right-arrow-small.png"

#ifdef THEME_BLUE
#define LEFTARROW_NORMAL_PATH  ""
#define RIGHTARROW_NORMAL_PATH ""
#define SUBMENU_TITLE_BG       ""
#else
#define LEFTARROW_NORMAL_PATH  PATH_PREFIX"skin/left-arrow-icon-normal-small.png"
#define RIGHTARROW_NORMAL_PATH PATH_PREFIX"skin/right-arrow-icon-normal-small.png"
#if defined(THEME_DARK) || defined(THEME_DARK_POWKIDDY)
#define SUBMENU_TITLE_BG       PATH_PREFIX"skin/menu-sub-title-bg.png"
#else
#define SUBMENU_TITLE_BG       ""
#endif//defined(THEME_DARK) || defined(THEME_DARK_POWKIDDY)
#endif//THEME_BLUE

#define NOTHUMB_PATH    PATH_PREFIX"skin/save-default.png"
#define EMPTYTIPS_PATH  PATH_PREFIX"skin/tips-empty.png"
#define BAR_NAV_PATH    PATH_PREFIX"skin/stat-nav-icon.png"


#define SKIN_A_ICON     PATH_PREFIX"skin/icon-A-54.png"
#define SKIN_B_ICON     PATH_PREFIX"skin/icon-B-54.png"
#define BAR_ITEMBG_PATH ""

//#define BAR_ITEMBG_PATH PATH_PREFIX"skin/nav-bar-item-bg.png"

extern SDL_Color gProgressTextColor;
extern SDL_Color gMenuTextSelColor;
extern SDL_Color gMenuTextSelShadowColor;
extern SDL_Color gMenuTextColor;
extern SDL_Color gMenuTitleColor;
extern SDL_Color gStatIconTextColor;
extern SDL_Color gStatTextColor;
#endif