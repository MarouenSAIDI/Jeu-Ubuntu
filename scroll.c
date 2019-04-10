
#include "scroll.h"

void camera_sett()
{
SDL_Rect camera;
camera.x=0;
camera.y=0;
camera.w=900;
camera.h=600;

}


void scroll(int b1, int b2,SDL_Surface *ecran,SDL_Surface *img,SDL_Rect fond)  //b1:input clavier(droite) , b2:input clavier(gauche)
{int const speed=10;
{if(b1=1)
{ x+=speed;
  camera.x+=speed;
if(camera.x>=3300-900)
{camera.x=0;}
}


else if(b2=1)
{ x-=speed;
  camera.x-=speed;
if(camera.x<=0)
{camera.x=3300-900;}
}

SDL_BlitSurface(img,&camera,ecran,&fond);
}
