#include "ennemi.h"

void deplacerEnnemi(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *posE, SDL_Rect *posJ)
{
int nombreAleatoire = 0, directionTrouvee = 0, recommencerBoucle = 1, i = 0;
srand(time(NULL));     
 
nombreAleatoire = rand()%2;
 
while(recommencerBoucle = 1)
{
    i++;
    switch (nombreAleatoire)
    {
        case 0:
            if(posE->y > posJ->y) 
            {
                if(carte[posE->x][posE->y - 1] != MUR)
                {
                    posE->y--;
                    directionTrouvee = 1;
                    recommencerBoucle = 0;
                    break;
                }
                else
                {
                    nombreAleatoire = !nombreAleatoire;
                    break;
                }
            }
 
 
            if (posE->y < posJ->y) 
            {
                if(carte[posE->x][posE->y + 1] != MUR)
                {
                    posE->y++;
                    directionTrouvee = 1;
                    recommencerBoucle = 0;
                    break;
                }
                else
                {
                    nombreAleatoire = !nombreAleatoire;
                    break;
                }
            }
 
 
            else
            {
                nombreAleatoire = !nombreAleatoire;
                break;
            }
 
 
        case 1:
            if(posE->x > posJ->x) 
            {
                if(carte[posE->x - 1][posE->y] != MUR)
                {
                    posE->x--;
                    directionTrouvee = 1;
                    recommencerBoucle = 0;
                    break;
                }
                else
                {
                    nombreAleatoire = !nombreAleatoire;
                    break;
                }
            }
 
 
            if (posE->x < posJ->x)
 
            {
                if(carte[posE->x + 1][posE->y] != MUR)
                {
                    posE->x++;
                    directionTrouvee = 1;
                    recommencerBoucle = 0;
                    break;
                }
                else
                {
                    nombreAleatoire = !nombreAleatoire;
                    break;
                }
            }
 
 
            
 
    }
if(i > 1)
recommencerBoucle = 0;
}
 
 
 
if (directionTrouvee = 0)
{
    while (directionTrouvee = 0)
    {
        nombreAleatoire = rand()%4;
 
        switch (nombreAleatoire)
        {
            case HAUT:
            if (posE->y - 1 < 0) 
                break;
            
                
 
                
                posE->y--;
                directionTrouvee = 1;
                break;
 
            case BAS:
            if (posE->y + 1 >= NB_BLOCS_HAUTEUR) 
                break;
            
 
              
                posE->y++;
                directionTrouvee = 1;
                break;
 
            case GAUCHE:
            if (posE->x - 1 < 0) 
                break;
            
 
               
                posE->x--;
                directionTrouvee = 1;
                break;
 
            case DROITE:
            if (posE->x + 1 >= NB_BLOCS_LARGEUR) 
                break;
            
 
               
                posE->x++;
                directionTrouvee = 1;
                break;
        }   
    }  
}  
}


