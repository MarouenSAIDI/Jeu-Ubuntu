#include "aff_elle.h"
#include <SDL/SDL_mixer.h>

void pause (){
  int game_on = 1;
  SDL_Event event;
  while(game_on){
    SDL_WaitEvent(&event);
    switch(event.type){
      case SDL_QUIT:
        game_on = 0;
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

//********************************************************************
void aff_elle(SDL_Surface *ecran, SDL_Surface *image)
{SDL_Rect sett;
image=IMG_Load("elle.png");
sett=init_img(50,310, image,ecran);
SDL_BlitSurface(image , NULL, ecran, &sett );

}
//********************************************************************
void audio(Mix_Music *audio)
{
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
{
  printf("ERROR2");
}

audio = Mix_LoadMUS("music.mp3");
Mix_PlayMusic(audio, -1);

}






