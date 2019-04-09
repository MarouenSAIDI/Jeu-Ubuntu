#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#ifndef FONCTION_H_
#define FONCTION_H_

typedef struct //main character
{

  SDL_Surface *image;
  SDL_Rect position;
int score;
SDL_Surface *life;

}mainchar; 


void init_elle (mainchar* elle);/*initialisation de elle*/
void aff_elle(mainchar* elle, SDL_Surface *screen);/*affichage de elle*/

#endif 


