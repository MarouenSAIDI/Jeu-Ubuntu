#include "collisionTrigo.h"

// Pour detercter s'il y a collision entre box1 et box2 de forme AABB:

int CollisionAABBvsAABB(AABB box1,AABB box2) //boolean
{
   if((box2.x >= box1.x + box1.w)      // box2 trop à droite
	|| (box2.x + box2.w <= box1.x) // box2 trop à gauche
	|| (box2.y >= box1.y + box1.h) // box2 trop en bas
	|| (box2.y + box2.h <= box1.y))  // box2 trop en haut
          return 0; //false 
   else
          return 1; //true
}

// Pour detercter s'il y a collision entre cercle C et point:

int CollisionPointCercle (int x,int y,Cercle C) //boolean
{
   int d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
   if (d2>=C.rayon*C.rayon)
      return 0; //false
   else
      return 1; //true
}

// Pour detercter s'il y a collision entre cercle c1 et box1 AABB:

int ProjectionSurSegment(int Cx,int Cy,int Ax,int Ay,int Bx,int By)
{
   int ACx = Cx-Ax;
   int ACy = Cy-Ay; 
   int ABx = Bx-Ax;
   int ABy = By-Ay; 
   int BCx = Cx-Bx;
   int BCy = Cy-By; 
   int s1 = (ACx*ABx) + (ACy*ABy);
   int s2 = (BCx*ABx) + (BCy*ABy); 
   if (s1*s2>0)
     return 0;
   return 1;
}


int Collision_Cercle_box1(Cercle C1,AABB box1) //boolean
{
   if (CollisionPointCercle(box1.x,box1.y,C1)==1
    || CollisionPointCercle(box1.x,box1.y+box1.h,C1)==1
    || CollisionPointCercle(box1.x+box1.w,box1.y,C1)==1
    || CollisionPointCercle(box1.x+box1.w,box1.y+box1.h,C1)==1)
      return 1;   // deuxieme test;true

   if (CollisionPointAABB(C1.x,C1.y,box1)==1)
      return 1;   // troisieme test;true
   int projvertical = ProjectionSurSegment(C1.x,C1.y,box1.x,box1.y,box1.x,box1.y+box1.h);
   int projhorizontal = ProjectionSurSegment(C1.x,C1.y,box1.x,box1.y,box1.x+box1.w,box1.y); 
   if (projvertical==1 || projhorizontal==1)
      return 1;   //true
   return 0;  //autre cas;false 
}


