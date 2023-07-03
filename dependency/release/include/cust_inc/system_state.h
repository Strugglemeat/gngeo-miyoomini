#ifndef _SYSTEM_STATE_H_
#define _SYSTEM_STATE_H_
#include "shmvar.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SYSTEM_DEFAULT_VOLUME 20
#define SYSTEM_DEFAULT_BRIGHTNESS 10

#define BGM_DEFAULT_VOLUME 8
#define BGM_MAX_VOLUME     20

#define MAINUI_KEEP_DEFAULT_KEYMAP

#define KEYMAP_DEFAULT  0
#define KEYMAP_ROTATE90 1
#define KEYMAP_MAX      2
// #define KEYMAP_NINTENDO 1
// #define KEYMAP_SEGA     2
// #define KEYMAP_MAX      3


void loadSystemState(KeyShmInfo *shminfo);
void saveSystemState(KeyShmInfo *shminfo);
int loadContent(const char *filename, FILE *file, char **content);

const char * getSystemLanguage();
void setSystemLanguage(const char *desc);

#ifdef __cplusplus
}
#endif
#endif