#include "sprite.h"

void loadsprite(SDL_Surface *elle_sprite , SDL_Rect SpriteClip[])
{//Load sprite sheet
 elle_sprite=IMG_Load("elle_sprite.png");

//Set sprite clips
        SpriteClip[ 0 ].x =   0;
        SpriteClip[ 0 ].y =   0;
        SpriteClip[ 0 ].w =  75;
        SpriteClip[ 0 ].h = 126;

        SpriteClip[ 1 ].x = 75;
        SpriteClip[ 1 ].y =   0;
        SpriteClip[ 1 ].w = 75;
        SpriteClip[ 1 ].h = 126;
        
        SpriteClip[ 2 ].x = 150;
        SpriteClip[ 2 ].y =   0;
        SpriteClip[ 2 ].w =  75;
        SpriteClip[ 2 ].h = 126;
}


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* spriteclip)
{
    SDL_Rect offset;
 
    offset.x = x; 
    offset.y = y;
 
    SDL_BlitSurface( source, spriteclip, destination, &offset );
}

