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



SDL_Rect init_img(int x, int y, SDL_Surface *source,SDL_Surface *destination)
{
SDL_Rect offset;
offset.x=x;
offset.y=y;
return (offset);}





void bg(SDL_Surface *ecran, SDL_Surface *background)
{SDL_Rect sett;
background= IMG_Load("background.jpg");
sett=init_img(0,0, background,ecran);
SDL_BlitSurface(background , NULL, ecran, &sett );

}
