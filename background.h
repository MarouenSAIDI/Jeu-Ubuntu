#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef FONCTION_H_
#define FONCTION_H_

typedef struct bg
{
SDL_Surface *image;
SDL_Rect pos;
}bg;



void pause ();
SDL_Rect init_img(int x, int y, SDL_Surface *source,SDL_Surface *destination);
void affichage(SDL_Surface *ecran, SDL_Surface *background) ;
void audio(Mix_Music *audio);



#endif


