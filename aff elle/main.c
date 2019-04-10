
#include "aff_elle.h"

int main()
{
    SDL_Surface *screen = NULL, *elle = NULL ;    
    Mix_Music *music;
    
   
//init sdl screen**********************************

   if (SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    screen=SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE| SDL_DOUBLEBUF);
 if (screen == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

 SDL_WM_SetCaption("AWAKE", NULL);
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));

//***********************************************
    aff_elle(screen, elle);
  
    audio(music);   
    SDL_Flip(screen);
    pause();
    
    SDL_FreeSurface(elle); 
    Mix_FreeMusic(music);
    Mix_CloseAudio(); 
    SDL_Quit();

    return EXIT_SUCCESS;
}
 







