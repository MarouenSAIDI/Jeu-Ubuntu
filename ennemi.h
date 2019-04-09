#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#include <time.h>



#ifndef ENNEMI_H_
#define ENNEMI_H_

typedef struct {
 SDL_Surface * spriteleft ;
 SDL_Surface * spriteright;
}ennemi ;
typedef struct{
  SDL_Rect pmax_ennemi;
  SDL_Rect pmin_ennemi;
  SDL_Rect position_ennemi;
}ennemiPos;
ennemi initEnm();
int rand_pos(int pmax,int pmin);
void moveEnemy(ennemiPos * e, SDL_Surface *screen);
void showEnm(ennemiPos *enm, ennemi e, SDL_Surface * screen);
void animEnm (ennemi * e, ennemiPos ep, SDL_Surface *screen);
#endif
