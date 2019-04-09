#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h> 
#include <unistd.h>


#ifndef FONCTION_H_
#define FONCTION_H_

typedef struct AABB
{
  int x;
  int y;
  int w;
  int h;
}AABB;

typedef struct Cercle
{
   int x,y;
   int rayon;
}Cercle;

int CollisionAABBvsAABB(AABB box1,AABB box2);
int CollisionPointCercle (int x,int y,Cercle C);
int ProjectionSurSegment(int Cx,int Cy,int Ax,int Ay,int Bx,int By);
int Collision_Cercle_box1(Cercle C1,AABB box1);

#endif

