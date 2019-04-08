#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

typedef struct AABB
{
  int x;
  int y;
  int w;
  int h;
}AABB;

int collision(SDL_Rect box1,SDL_Rect box2);

#endif 
