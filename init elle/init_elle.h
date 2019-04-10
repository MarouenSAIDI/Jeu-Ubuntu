#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#ifndef ELLE_FONCTION_H_DEFINED
#define ELLE_FONCTION_H_INCLUDED

typedef struct //main character
{

  SDL_Surface *image;
  SDL_Rect position;
int score;
SDL_Surface *life;

}mainchar; 


void init_elle (mainchar* elle);/*initialisation de elle*/

#endif 

