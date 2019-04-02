#include <SDL/SDL.h>
#include "clavier.h"
#include "Personnage.h"
using namespace std;
 enum Direction {
        None,
        Left,
        Right,
        Top,
        Bottom
};
 
void test_clavier(bool& continuer, Direction& direction, bool& hit, const SDL_E$
        if(evt.type==SDL_QUIT) {
                continuer = false;
                return;
        }
  if(evt.type == SDL_KEYDOWN) {
                if (evt.key.keysym.sym==SDLK_LEFT) {
                        direction = Left;
                }
                else if (evt.key.keysym.sym==SDLK_RIGHT) {
                        direction = Right;
                }
                else if (evt.key.keysym.sym==SDLK_DOWN) {
                        direction = Bottom;
                }
  if (evt.key.keysym.sym==SDLK_LEFT) {
                        direction = Left;
                }
                else if (evt.key.keysym.sym==SDLK_RIGHT) {
                        direction = Right;
                }
                else if (evt.key.keysym.sym==SDLK_DOWN) {
                        direction = Bottom;
                }
                else if (evt.key.keysym.sym==SDLK_UP) {
                        direction = Top;
                }
 
                else if (evt.key.keysym.sym==SDLK_f) {
                        hit = true;
                }
        }
        else if(evt.type == SDL_KEYUP) {
                if (evt.key.keysym.sym==SDLK_LEFT ||
           direction = Top;
                }
 
                else if (evt.key.keysym.sym==SDLK_f) {
                        hit = true;
                }
        }
        else if(evt.type == SDL_KEYUP) {
                if (evt.key.keysym.sym==SDLK_LEFT ||
                        evt.key.keysym.sym==SDLK_RIGHT ||
                        evt.key.keysym.sym==SDLK_DOWN ||
                        evt.key.keysym.sym==SDLK_UP)
                {
                        direction = None;
                }
        }
}
 
bool continuer = true;
SDL_Event evt;
Direction direction = None;
bool hit;
 
while(continuer) {
        hit = false;
        while(continuer && SDL_PollEvent(&evt)) {
                test_clavier(continuer, direction, hit, evt);
        }
        if(continuer) {
 switch(direction) {
                case Left: perso->deplacer("gauche"); break;
                case Right: perso->deplacer("droite"); break;
                case Top: perso->deplacer("haut"); break;
                case Bottom: perso->deplacer("bas"); break;
                case None: 
                default: break;
                }
 
                        perso->frapper(perso->direction_actuelle());
                }
        }
}
 
               if(hit) {
                       perso->frapper(perso->direction_actuelle());
                }
        }
}
 
