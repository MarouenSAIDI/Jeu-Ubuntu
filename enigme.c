#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include<math.h>
#include "SDL/SDL_ttf.h"
#include "enigme.h"

int generate_question(int*n)
{  int a;
	srand(time(NULL));
 *n= 1+ rand()%9;
  a=(*n);
 return a;
}

void init_affichier_question(SDL_Surface *screen)
{ 
char question[100];
 
 sprintf(question ,"Guess the number between 1 and 9");
 SDL_Surface *background = NULL; 
SDL_Surface *message = NULL; 

//La structure d'événement 


//Le Font qu'on va utiliser
TTF_Font *font=NULL; 

//La couleur du Font 
SDL_Color textColor = { 15, 200, 255 }; 

//Initialisation de SDL_TTF 
	if( TTF_Init() == -1 ) { 
		printf("false"); 
	} 

	//Mise en place de la barre caption 
	

 background = IMG_Load("background.png" );
 font = TTF_OpenFont( "caslon.ttf", 50 ); 
//Mise en place du texte sur la surface message 
message = TTF_RenderText_Solid( font, question, textColor ); 
 //Application des images sur l'écran 



SDL_Rect *p; p->x=90;p->y=265;			
 SDL_BlitSurface( background, NULL,  screen,NULL );
 SDL_BlitSurface( message, NULL,  screen,p ); 
 SDL_Flip(screen) ;



	

	//Fermeture des Fonts qu'on a utilisé 
	TTF_CloseFont( font ); 

	//On quitte SDL_ttf 
	TTF_Quit(); 

	
	
}







int reponse(int *rep )
{ int r;
	SDL_Event event ;
  	int continuer=1;
	
	while(continuer)
	{SDL_WaitEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
		continuer=0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_KP1: 
			  r= 1;
				continuer=0;
			   break ;
			   case  SDLK_KP2 :
			   r= 2;
				continuer=0;
			   break;
			   case SDLK_KP3: 
			   r=3 ;
			continuer=0;
			  break;
			    
                          case  SDLK_KP4: 
			  r= 4;
				continuer=0;
			   break ; 
                           case  SDLK_KP5: 
			  r= 5;
				continuer=0;
			   break ;
                           case  SDLK_KP6: 
			  r= 6;
				continuer=0;
			   break ;
                         case  SDLK_KP7: 
			  r= 7;
				continuer=0;
			   break ;
                           case  SDLK_KP8: 
			  r= 8;(*rep)=(r*100);
				continuer=0;
			   break ;
                           case  SDLK_KP9: 
			  r= 9;
				continuer=0;
			   break ;
                            case  SDLK_KP0: 
			  r= 0;
				continuer=0;
			   break ;
}
       break ;

                 
	}
	

}
                 
	
	



return r;
}


void afficher_resultat (SDL_Surface * screen,int n,int r)
 {SDL_Surface *background; background=NULL;
 
 	if (r==n)
 	{
 		background=IMG_Load("correct.png");
 		SDL_BlitSurface(background, NULL, screen, NULL) ;
        SDL_Flip(screen);
	SDL_Delay(3000);
 	}
 	else
 	{
 		background=IMG_Load("wrong.png");
 		SDL_BlitSurface(background, NULL, screen, NULL) ;
        SDL_Flip(screen);
	SDL_Delay(1000);
if(n>r)
{  background=IMG_Load("higher.png");
 		SDL_BlitSurface(background, NULL, screen, NULL) ;
        SDL_Flip(screen);
	SDL_Delay(3000);

 }	
else
{background=IMG_Load("lower.png");
 		SDL_BlitSurface(background, NULL, screen, NULL) ;
        SDL_Flip(screen);
	SDL_Delay(3000);

}


}
 }

