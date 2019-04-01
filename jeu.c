
#include "fonction.h"

int main()
{
    SDL_Surface *screen = NULL, *bg_menu = NULL ;
    
    

    SDL_Init(SDL_INIT_VIDEO);

   screen = SDL_SetVideoMode(768, 432, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("AWAKE", NULL);

    bg(screen, bg_menu);

    SDL_Flip(screen);
    pause();

    SDL_FreeSurface(bg_menu); 
    SDL_Quit();

    return EXIT_SUCCESS;
}
 








