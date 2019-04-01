#include "fonction.h"

int main(int argc , char *argv[]){
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetVideoMode(768,432,32,SDL_HWSURFACE);
  SDL_WM_SetCaption("AWAKE",NULL);
  pause();
  SDL_Quit();
  return EXIT_SUCCESS;
}
