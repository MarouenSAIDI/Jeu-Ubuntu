#include "elle_fonctions.h"

int main(int argv, char *argc[])
{
	SDL_Surface 
*screen = NULL;

	SDL_Event 
event;
	mainchar
*elle;

int continuer = 1;

/*initialisation de sdl et screen*/
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

 // Coloration de la surface ecran en bleu-vert
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));

//***********************************


while(continuer)
{
    SDL_WaitEvent(&event);
    switch(event.type)
	{
      case SDL_QUIT:
        continuer = 0;
break;
 default:
      break;}

}
init_elle(elle);/*initialisation de elle*/
aff_elle(elle,screen);/*affichage de elle(just un blit)*/
SDL_Flip(screen);
SDL_FreeSurface(elle->image);

SDL_Quit();

return EXIT_SUCCESS;
}

