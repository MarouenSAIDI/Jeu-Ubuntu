#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argv, char *argc[])
{
	SDL_Surface 
*screen = NULL, *elleimage= NULL;
	SDL_Rect 
position;
	SDL_Event 
event;

int continuer = 1;
position.x =40;
position.y =60;

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


//***********************************


while(continuer)
{
    SDL_WaitEvent(&event);
    if(event.type == SDL_QUIT)
       { continuer = 0;
	break;}
else
elleimage=IMG_Load("/home/elae/Documents/init&aff personnage/elle.png");
if(elleimage == NULL) printf("error imgload");

SDL_BlitSurface(elleimage, NULL, screen, &position);
}

SDL_Flip(screen);
SDL_FreeSurface(elleimage);

SDL_Quit();

return EXIT_SUCCESS;
}

