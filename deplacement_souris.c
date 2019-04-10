#include "deplacement_souris.h"

switch(event.type)

{

   case SDL_QUIT:

       continuer = 0;

       break;

   case SDL_MOUSEBUTTONUP: 

       break;

}
switch(event.type)

{

   case SDL_QUIT:

       continuer = 0;

       break;

   case SDL_MOUSEBUTTONUP:

       if (event.button.button == SDL_BUTTON_RIGHT) 

           continuer = 0;

       break;

}
while (continuer)

{

   SDL_WaitEvent(&event);

   switch(event.type)

   {

       case SDL_QUIT:

           continuer = 0;

           break;

       case SDL_MOUSEBUTTONUP:

           positionperso.x = event.button.x;

           positionperso.y = event.button.y;

           break;

   }



   SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

   SDL_BlitSurface(perso, NULL, ecran, &positionperso); 

   SDL_Flip(ecran);

}

