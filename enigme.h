#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include<math.h>


int generate_question(int*n);
void init_affichier_question(SDL_Surface *screen);

int reponse(int *rep );
void afficher_resultat (SDL_Surface * screen,int n,int r);
