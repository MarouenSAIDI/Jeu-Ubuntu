#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#ifndef sprite_H_DEFINED
#define sprite_H_INCLUDED

void loadsprite(SDL_Surface *elle_sprite , SDL_Rect SpriteClip[]);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* spriteclip);

#endif 

