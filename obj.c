#include "objet.h"

int main(int argc , char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SD SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
  SDL_Flip(ecran);
  pause(); 
  SDL_Quit();
  return EXIT_SUCCESS;
}
