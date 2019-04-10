#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED
//#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct player
{ 
SDL_Rect position;
}player;

void pause ();
void scrolling (SDL_Rect *camera,player p);
void set_camera(SDL_Rect *camera);

#endif 
