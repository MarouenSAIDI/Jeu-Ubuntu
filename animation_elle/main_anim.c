#include "sprite.h"

int main(int argv, char *argc[])
{
//Les attributs de l'écran (640 * 480)
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
 
//Les attributs de la feuille de sprites (200 * 200)
const int SHEET_WIDTH = 200;
const int SHEET_HEIGHT = 200;
 
//les surfaces
SDL_Surface *screen = NULL;
SDL_Surface *elle_sprite = NULL;

//3 walking frames
SDL_Rect spriteclip[ 3 ]; 

SDL_Event 
event;

int continuer = 1;

/*initialisation de sdl et screen*/
   if (SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
 
    screen=SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE| SDL_DOUBLEBUF);
 if (screen == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

 SDL_WM_SetCaption("AWAKE", NULL);

 // Coloration de la surface ecran en bleu-vert
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));

//*********************************************
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

//Load sprite sheet and Set sprite clips
loadsprite(elle_sprite, &spriteclip[3]);

//On applique les sprites sur l'écran
    apply_surface( 0, 0, elle_sprite, screen, &spriteclip[ 0 ] );
    apply_surface( SCREEN_WIDTH-(SHEET_WIDTH/2), 0, elle_sprite, screen, &spriteclip[ 1 ] );
    apply_surface( 0, SCREEN_HEIGHT-(SHEET_HEIGHT/2), elle_sprite, screen, &spriteclip[ 2 ] );

//**************************************
SDL_FreeSurface(elle_sprite);

SDL_Quit();

return EXIT_SUCCESS;
}
