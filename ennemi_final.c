#include "ennemi.h"



 ennemi initEnm (){
  ennemi e;
  e.spriteleft = IMG_Load("nour.bmp");
	e.spriteright = IMG_Load("sprit.bmp");
if((e.spriteleft == NULL) || (e.spriteright == NULL)){
  printf("enable to load the image\n");
}
  return e;
}


int rand_pos(int pmax,int pmin)
{
  int pos;
  srand(time(NULL));
  pos=rand()%(pmax-pmin+1)+pmin;
return pos;
}


void moveEnemy(ennemiPos * e, SDL_Surface *screen){
SDL_Event event;
int c = 1;
int tPr = 0, tAct = 0;
int pos;
static int k=0;
e->pmax_ennemi.x = screen->w  ;
e->pmin_ennemi.x = screen->w/2 ;
pos = rand_pos(e->pmax_ennemi.x, e->pmin_ennemi.x);
        tAct = SDL_GetTicks();
        if (tAct - tPr > 30){
           if(k==0){
              if(e->position_ennemi.x < pos){
                  e->position_ennemi.x+= 50;

              }else{
                k=1;
              }
            }
            if(k==1){
                if(e->position_ennemi.x > e->pmin_ennemi.x){
                      e->position_ennemi.x-=50;
                    }else{
                         k=0;
                    }
            }
            tPr = tAct;
 
       }
}



void showEnm(ennemiPos *enm, ennemi e, SDL_Surface * screen){
  SDL_Rect camera;
  camera.x = 0;
  camera.y = 0;
  camera.h = 61;
  camera.w = 65;
enm->position_ennemi.x = 800;
enm->position_ennemi.y = 500;
enm->position_ennemi.h = e.spriteleft->h;
enm->position_ennemi.w = e.spriteleft->w;
 SDL_BlitSurface(e.spriteleft, &camera, screen, &enm->position_ennemi);
}


void animEnm (ennemi * e, ennemiPos ep, SDL_Surface *screen){
  SDL_Rect frame;
  static int inc = 0;
  static int i = 0;
  static int k = 0;
  if (i<=7) {
  inc = inc + 64;
  frame.x = inc;
  frame.y = 0;
  frame.w = 64;
  frame.h = 61;
  SDL_BlitSurface(e->spriteleft, &frame, screen, &ep.position_ennemi);
  i++;
}
  else{
  i=9; inc = 0;
  if (k <= 6) {
    inc = inc + 64;
  frame.x = inc;
  frame.y = 0;
  frame.w = 64;
  frame.h = 61;
  SDL_BlitSurface(e->spriteright, &frame, screen, &ep.position_ennemi);
  k++;
}else{
  k = 9;
  i=0;
  inc =0;
}
}
}

