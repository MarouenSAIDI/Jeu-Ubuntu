#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#ifndef FONCTION_H_
#define FONCTION_H_

/*typedef struct bg_menu
{ int width= 830;
  int height=350 ;
}bg_menu;*/


/*typedef struct bouton
{

}bouton; */

void pause ();
SDL_Rect init_img(int x, int y, SDL_Surface *source,SDL_Surface *destination);
void bg(SDL_Surface *ecran, SDL_Surface *background) ;


#endif


