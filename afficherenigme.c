#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
//#include "affenigme.h"
typedef struct aff_eng

{
    SDL_Surface *enig[4] ;
 
   SDL_Rect posenig ;

}
 aff_eng;

void afficher_enigme (aff_eng enig)

{
    SDL_Init(SDL_INIT_EVERYTHING);
int i=0;
    
    aff_eng e1 ;
    aff_eng e2 ;
    SDL_Surface *ecran = NULL,*fond = NULL,*fleche=NULL  ;
    SDL_Rect positionb1;
    SDL_Rect pfleche;
    

    SDL_Event event;
    
    positionb1.x = 0;
    positionb1.y = 0;
    (e1.posenig).x=0;
    (e1.posenig).y=0;
    (e2.posenig).x=0;
    (e2.posenig).y=0;

    int continuer = 1;
SDL_Init(SDL_INIT_EVERYTHING);

    ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /* Double Buffering */

    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);
e1.enig[0]=IMG_Load("q1.png");
e1.enig[1]=IMG_Load("bravo2.png");
e1.enig[2]=IMG_Load("ops2.png");


fond = SDL_LoadBMP("background2.bmp");

fleche = IMG_Load("fleche.png");  


    
    
SDL_Flip(ecran);

    SDL_SetColorKey(fond, SDL_SRCCOLORKEY, SDL_MapRGB(fond->format, 255, 255, 255));


    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */



    while (continuer)

    {
//SDL_ShowCursor(SDL_DISABLE);


SDL_PollEvent(&event);
switch(event.type)

        {
case SDL_QUIT:

                continuer = 0;

                break;
case SDL_MOUSEMOTION:
            pfleche.x = event.motion.x;
            pfleche.y = event.motion.y;
break;
case SDL_MOUSEBUTTONUP :
if (( pfleche.x > 550 ) && ( pfleche.y > 0 ) && ( pfleche.x < 663 ) && ( pfleche.y < 200 )) 
   {             
   i=1 ;         


}
else if (( pfleche.x >550  ) && ( pfleche.y > 200 ) && ( pfleche.x < 663 ) && ( pfleche.y < 600 )) 
 i=2;
break;
         }



        



            
                    

 if (i==0) 
{       
SDL_BlitSurface(fond, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[0], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
SDL_Flip(ecran);
if (i==1)        
{       
SDL_BlitSurface(fond, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[1], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
SDL_Flip(ecran);
if (i==2)         
{       
SDL_BlitSurface(fond, NULL, ecran, &positionb1);
SDL_BlitSurface(e1.enig[2], NULL, ecran,&e1.posenig);
SDL_BlitSurface(fleche, NULL, ecran, &pfleche);
SDL_Flip(ecran);
}
SDL_Flip(ecran);


        


}
SDL_FreeSurface (fond);
SDL_FreeSurface(e1.enig[0]);
SDL_FreeSurface(e1.enig[1]);
SDL_FreeSurface(e2.enig[1]);


 SDL_FreeSurface (fleche);


    SDL_Quit();




}
int main(int argc, char *argv[])

 {
aff_eng enig ;

afficher_enigme (enig);
}

 

