#ifndef AFFENIGME_H_INCLUDED

#define AFFENIGME_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct aff_eng

{
    SDL_Surface *enig[4] ;
 
   SDL_Rect posenig ;

}
 aff_eng;

void afficher_enigme (aff_eng enig);



#endif
