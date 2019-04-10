#include "deplacement_souris.h"


int main ()
   {
      SDL_WaitEvent(*event);
      SDL_FillRect(ecran, NULL, SDL_MapRGB);
      SDL_Flip(ecran);
      SDL_QUIT();

     return EXIT_SUCCESS;
   }
