#include "collisionbb.h"

int collision(SDL_Rect box1,SDL_Rect box2)
{
if(box1.y>=box2.y+box2.h)
return 0;
if (box1.x>=box2.x+box2.w)
return 0;
if (box1.y+box1.h<=box2.y)
return 0;
if (box1.x+box1.w<=box2.x)
return 0;
return 1;
}
int collision(Player hero,enemy e)
{
int collision=1;
if(hero.positiontext.x + hero.positiontext. w =< e.positionenemyy. x 
|| hero.positiontext.x => e.positionenemyy. x + e.positionenemyy. w
|| hero.positiontext.y + hero.positiontext.h =< e.positionenemyy. y 
|| hero.positiontext.y => e.positionenemyy. y + e.positionenemyy. h )
{
collision=0;
}
else{
collision=1;
}
return collision;
}

int collisionbox(Player hero,objet ob)
{
int collision=1;
if(hero.positiontext.x + hero.positiontext. w =< ob.positionobjett. x 
|| hero.positiontext.x => ob.positionobjett. x + ob.positionobjett. w
|| hero.positiontext.y + hero.positiontext.h =< ob.positionobjett. y 
|| hero.positiontext.y => ob.positionobjett. y + ob.positionobjett. h )
{
collision=0;
}
else{
collision=1;
}
return collision;
}
