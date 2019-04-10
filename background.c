#include "background.h"
#include <SDL/SDL_mixer.h>

void pause (){
  int continuer = 1;
  SDL_Event event;
  while(continuer){
    SDL_WaitEvent(&event);
    switch(event.type){
      case SDL_QUIT:
        continuer = 0;
      break;
      default:
      break;
    }
  }
}



SDL_Rect init_img(int x, int y, SDL_Surface *source,SDL_Surface *destination)
{
SDL_Rect offset;
offset.x=x;
offset.y=y;
return (offset);}





void affichage(SDL_Surface *ecran, SDL_Surface *background)
{SDL_Rect sett;
background= SDL_LoadBMP("bg.bmp");
sett=init_img(-37,-90, background,ecran);
SDL_BlitSurface(background , NULL, ecran, &sett );

}





void audio(Mix_Music *audio)
{
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
{
  printf("ERROR2");
}

audio = Mix_LoadMUS("music.mp3");
Mix_PlayMusic(audio, -1);

}







