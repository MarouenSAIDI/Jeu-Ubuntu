#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include "scrolling.h"


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



void scrolling (SDL_Rect *camera,player p)
{
  camera->x = 36*(p.position).x;
  camera->y = 36*(p.position).y;
  camera->h=595;
  camera->w=595;
}


void set_camera(SDL_Rect *camera)
{
 camera->x=900;
 camera->y=595.2;
 camera->h=595.2;
 camera->w=3371;  
}
