#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
void pause();
 
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *objet = NULL;
    SDL_Rect positionFond, positionobjet;
 
    positionFond.x = 0;
    positionFond.y = 0;
    positionobjet.x = 500;
    positionobjet.y = 260;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    
 
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    
 
    imageDeFond = IMG_Load("backg.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 
    
    objet = IMG_Load("objet.png");
    SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
 
    SDL_Flip(ecran);
    pause();
 
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(objet);
    SDL_Quit();
 
    
}
 
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
