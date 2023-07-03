#ifndef __PROGRESS_BAR__
#define __PROGRESS_BAR__
#include <SDL/SDL.h>

typedef struct _TProgressBar {    
    int (*getmessage)(char *buf, int size);
    int (*getpos)(); 
	int size;
} TProgressBar;

int InitProgressBar(int width, int height);

int ShowProgressBar(TProgressBar *bar, SDL_Surface *screen);
int HideProgressBar(TProgressBar *bar);

int UninitProgressBar();

#endif