#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"ennemi.h"

int  main(int argc, char *argv[])
{
 
SDL_Surface*screen;
SDL_Rect positionecran;
SDL_Event event;
ennemiPos ep;
SDL_Rect camera;
camera.x=0;
camera.y=0;
camera.w=960;
camera.h=600; 


 

ennemi e;


    SDL_Init(SDL_INIT_VIDEO);


    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE| SDL_DOUBLEBUF );
    SDL_WM_SetCaption("Afficher Ennemie en Mvt Vient sur x", NULL);
    e = initEnm();

    moveEnemy(&ep,screen);

  
    SDL_Quit();




}
