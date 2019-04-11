#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>


  



int main(int argc, char *argv[]){
  SDL_Surface *screen = NULL, *AS = NULL;
  SDL_Rect position;

  SDL_Event event;
  int continuer = 1;
  int i = 0;
  int tempPrecedent = 0, tempActuel = 0;

  
  SDL_Init(SDL_INIT_VIDEO);

  screen = SDL_SetVideoMode(732,489,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

AS = IMG_Load("ghost.png");

  position.x = 0;
  position.y = 400;


  
  SDL_SetColorKey(AS,SDL_SRCCOLORKEY, SDL_MapRGB(AS->format, 34, 177, 76));


  SDL_EnableKeyRepeat(10, 10);
  while(continuer){
    SDL_PollEvent(&event);
    switch(event.type){
      case SDL_QUIT:
        continuer = 0;
      break;
      default:
      break;
    }
    tempActuel = SDL_GetTicks();
    if(i == 0){
      if(tempActuel - tempPrecedent > 30){ 
        position.x++;
        tempActuel = tempPrecedent;
        if(position.x == 700){
          i = 1;
        }
      }
      else{
        SDL_Delay(30);
      }
    
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,255,255,255));
      SDL_BlitSurface(AS, NULL, screen, &position);

      SDL_Flip(screen);
    }
    else if(i == 1){
      if(tempActuel - tempPrecedent > 30){ 
        position.x--;
        tempActuel = tempPrecedent;
        if(position.x == 0){
          i = 0;
        }
      }
      else{
        SDL_Delay(30);
      }
    
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,255,255,255));
      SDL_BlitSurface(AS, NULL, screen, &position);

      SDL_Flip(screen);
    }
  }
 

  SDL_FreeSurface(AS);
  SDL_Quit();
  return EXIT_SUCCESS;
}
