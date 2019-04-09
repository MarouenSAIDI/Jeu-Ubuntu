#include "elle_fonctions.h"

void init_elle(mainchar* elle)
{
 elle->position.x =40;
    elle->position.y =60;
     elle->image=IMG_Load("elle.png");
elle->score=0;;
elle->life=IMG_Load("3lives.png");
}
//**********************************

void aff_elle(mainchar* elle, SDL_Surface *screen)
{
SDL_BlitSurface(elle->image, NULL, screen, &elle->position);
}
