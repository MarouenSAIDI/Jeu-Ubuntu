#include "fonction.h"

void pause (){
  int continuer = 1;
  SDL_Event event;
  while(continuer){
    SDL_WaitEvent(&event);
    switch(event.type){
      case SDL_QUIT:
        continuer = 0;
      break;
      default:
      break;
    }
  }
}


void init_img(int x, int y, SDL_Surface *source,SDL_Surface *destination,){
SDL_Rect offset;
offset.x=x;
offset.y=y;
}



void SDL_BlitSurface( source, a, destination, &offset );



void bg(SDL_Surface *ecran=NULL, SDL_Surface *background=NULL)
{
background= SDL_LoadBMP(background.bmp);
background= SDL_BlitSurface( , a, destination, &offset );


