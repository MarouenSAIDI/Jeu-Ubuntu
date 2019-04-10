#include "elle_fonctions.h"

void init_elle(mainchar* elle)
{
 elle->position.x =50;
    elle->position.y =310;
     elle->image=IMG_Load("elle.png");
elle->score=0;
elle->life=NULL;
}
//**********************************
