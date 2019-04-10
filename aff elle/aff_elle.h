#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef AFF_ELLE_H_
#define AFF_ELLE_H_


void pause ();
SDL_Rect init_img(int x, int y, SDL_Surface *source,SDL_Surface *destination);
void aff_elle(SDL_Surface *ecran, SDL_Surface *image) ;
void HandleEvent(SDL_Event event);
void audio(Mix_Music *audio);



#endif

