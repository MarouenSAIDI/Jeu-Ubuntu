#include "fonction.h"
#include "management.h"


void pause () {
	int continuer = 1;
	SDL_Event event;
	while (continuer) {
		SDL_WaitEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			continuer = 0;
			break;
		default:
			break;
		}
	}
}



SDL_Rect init_img(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	return (offset);
}





void bg(SDL_Surface *ecran, SDL_Surface *background)
{	SDL_Rect sett;
	background = IMG_Load("background.jpg");
	sett = init_img(0, 0, background, ecran);
	SDL_BlitSurface(background , NULL, ecran, &sett );




}


void menuOption() {
	SDL_Surface *ecran = NULL, *image = NULL, *background = NULL;
	SDL_Rect sett, position, camera;
	SDL_Event event;

	int continuer = 1;

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(768, 432, 32, SDL_HWSURFACE);
	background = IMG_Load("background.jpg");
	sett = init_img(0, 0, background, ecran);
	SDL_BlitSurface(background, NULL, ecran, &sett);
	image = IMG_Load("menu option.png");
	sett = init_img(100, 0, image, ecran);
	SDL_BlitSurface(image, NULL, ecran, &sett);
	//camera_sett(SDL_Rect camera);
	SDL_Flip(ecran);

	while (continuer) {
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		}
	}

}


void GamePlay() {
	SDL_Surface *ecran = NULL, *background = NULL, *backgroundMasque = NULL;
	collision c;
	SDL_Rect sett, position;
	SDL_Event event;
	Mix_Music *music;

	int coll = 0;
	char image[30] = "";
	int continuer = 1;
	Personnage_P elle;
	ennemi ennemi_1;
	ennemi ennemi_2;
	life coeur;

	inisialiser_coeur(coeur);
	loadsprite(&elle);
	load_ennemi_1(&ennemi_1);
	load_ennemi_2(&ennemi_2);
	const int FPS = 30;
	const int speed = 20;
	Uint32 start;
	int x, y;
	int frame = 0;

	x = 0;
	y = 0;

	int scoree, enigmee;
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(768, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);



	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("ERROR2");
	}

	music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music, -1);
	SDL_Flip(ecran);


	background = SDL_LoadBMP("bg3.bmp");
	backgroundMasque = SDL_LoadBMP("bg3Masque.bmp");
	SDL_Flip(ecran);
	SDL_Rect camera;
	camera.x = 0;
	camera.y = 0;
	camera.w = 768;
	camera.h = 737;

	_Bool b[2] = {0, 0};


	position.x = 0;
	position.y = 400;

	int i = 1;
	int tempPrecedent = 0, tempActuel = 0;




	tempActuel = SDL_GetTicks();
	/*while (i){
	  i = enigme_main(ecran);
	}*/

	while (continuer) {
		start = SDL_GetTicks();


		int x;
		int y;
		int mouvement;

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;
		case SDL_KEYDOWN:
			//events_keydown(backgroundMasque, mouvement, camera, elle, ennemi_1, ennemi_2, frame, b, event);
			switch (event.key.keysym.sym) {
			case SDLK_RIGHT:

				if (elle.pos.x <= 150) {
					if (event.key.state == SDL_PRESSED) {
						mouvement = 1;
						elle.pos.x = deplacement_perso(backgroundMasque, elle, mouvement, ennemi_1, ennemi_2, camera) ;

					}
				}
				else {
					b[0] = 1;
					mouvement = 11;
					//elle.pos.x = deplacement_perso(backgroundMasque,elle,mouvement,ennemi_1,ennemi_2,camera) ;
					if (elle.pos.x <= 300 && elle.pos.x >= 200) {
						while (i) {
							i = enigme_main(ecran);
						}
					}
					else {
						elle.pos.x = deplacement_perso(backgroundMasque, elle, mouvement, ennemi_1, ennemi_2, camera) ;
					}
					printf(" pos : %d\n", elle.pos.x);

				}
				if (frame < 4)
					frame++;
				else
					frame = 0;

				SDL_Delay(80);
				break;

			case SDLK_LEFT:
				mouvement = 2;
				if (camera.x == 0) {
					if (event.key.state == SDL_PRESSED) {
						mouvement = 2;
						elle.pos.x = deplacement_perso(backgroundMasque, elle, mouvement, ennemi_1, ennemi_2, camera) ;


					}
				}
				else {
					b[1] = 1;
					mouvement = 22;
					elle.pos.x = deplacement_perso(backgroundMasque, elle, mouvement, ennemi_1, ennemi_2, camera) ;

				}
				if (frame < 5)
					frame = 5;

				if (frame < 9 )
					frame++;

				else
					frame = 5;
				SDL_Delay(80);
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_RIGHT:
				b[0] = 0;
				break;
			case SDLK_LEFT:
				b[1] = 0;
				break;
			}
			break;
		}

		if (b[0]) {
			x += speed;
			camera.x += speed;
			if (camera.x + camera.w >= 3355) {
				camera.x = 3355 - 768;
				if (elle.pos.x + elle.pos.w <= camera.w - (elle.pos.x + elle.pos.w)) {
					mouvement = 1;
					elle.pos.x = deplacement_perso(backgroundMasque, elle, mouvement, ennemi_1, ennemi_2, camera);
				}

			}


		}
		else if (b[1]) {
			x -= speed;
			camera.x -= speed;
			if (camera.x <= 0) {
				camera.x = 0;
				if (elle.pos.x >= 0) {
					mouvement = 2;
					elle.pos.x = deplacement_perso(backgroundMasque, elle, mouvement, ennemi_1, ennemi_2, camera) ;
				}
			}
		}

		//scoree=gestion_score(&scoree,enigmee);
		//updateScore(&scoree, ecran);


		blitsurfaces(ecran, background, backgroundMasque, camera, elle, ennemi_1, ennemi_2, frame, coeur);



		ennemi_1.frame ++;
		ennemi_1.pos.x -= 13;


		if (ennemi_1.frame == 3) {
			ennemi_1.frame = 0;
		}
		if (ennemi_1.pos.x <= 300) {
			ennemi_1.pos.x = 1900;
		}
		ennemi_2.frame ++;
		ennemi_2.pos.x -= 10;
		if (ennemi_2.frame == 2) {
			ennemi_2.frame = 0;
		}
		if (ennemi_2.pos.x <= 0) {
			ennemi_2.pos.x = 1000;
		}
		if (1000 / FPS > SDL_GetTicks() - start) {
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
		}
	}
}



/******************************************************/



int menu(int test) {
	SDL_Surface *screen = NULL, *bg_menu = NULL, *play = NULL, *option = NULL, *help = NULL, *quit = NULL;
	SDL_Rect positionPlay, positionOption, positionHelp, positionQuit;
	Mix_Music *music = NULL;
	SDL_Rect sett;
	int State = 0;

	int continuer = 1;


	SDL_Event event, event_option;


	positionPlay.x = 75;
	positionPlay.y = 81.233;
	positionOption.x = 75;
	positionOption.y = 160.5;
	positionHelp.x = 75;
	positionHelp.y = 239.78;
	positionQuit.x = 75;
	positionQuit.y = 319.15;



	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(768, 432, 32, SDL_HWSURFACE);
	if (screen == NULL) {
		printf("ERROR\n");
		SDL_GetError();
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("AWAKE", NULL);

	bg(screen, bg_menu);

	play = IMG_Load("play.png");
	option = IMG_Load("options.png");
	help = IMG_Load("help.png");
	quit = IMG_Load("quit.png");

	SDL_BlitSurface(play, NULL, screen, &positionPlay);
	SDL_BlitSurface(option, NULL, screen, &positionOption);
	SDL_BlitSurface(help, NULL, screen, &positionHelp);
	SDL_BlitSurface(quit, NULL, screen, &positionQuit);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("ERROR2");
	}

	music = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music, -1);

	SDL_Flip(screen);

	while (continuer) {

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			exit(EXIT_SUCCESS);
			break;

		case SDL_MOUSEMOTION:

			if (event.motion.x < positionPlay.x + positionPlay.w && event.motion.x > positionPlay.x && event.motion.y < positionPlay.y + positionPlay.h && event.motion.y > positionPlay.y) {
				play = IMG_Load("play_green - Copy.png");
				SDL_BlitSurface(play, NULL, screen, &positionPlay);
				SDL_Flip(screen);
			}
			else {
				play = IMG_Load("play.png");
				SDL_BlitSurface(play, NULL, screen, &positionPlay);
				SDL_Flip(screen);
			}
			if (event.motion.x < positionOption.x + positionOption.w && event.motion.x > positionOption.x && event.motion.y < positionOption.y + positionOption.h && event.motion.y > positionOption.y) {
				option = IMG_Load("options_green - Copy.png");
				SDL_BlitSurface(option, NULL, screen, &positionOption);
				SDL_Flip(screen);
			}
			else {
				option = IMG_Load("options.png");
				SDL_BlitSurface(option, NULL, screen, &positionOption);
				SDL_Flip(screen);
			}
			if (event.motion.x < positionHelp.x + positionHelp.w && event.motion.x > positionHelp.x && event.motion.y < positionHelp.y + positionHelp.h && event.motion.y > positionHelp.y) {
				help = IMG_Load("help_options - Copy.png");
				SDL_BlitSurface(help, NULL, screen, &positionHelp);
				SDL_Flip(screen);
			}
			else {
				help = IMG_Load("help.png");
				SDL_BlitSurface(help, NULL, screen, &positionHelp);
				SDL_Flip(screen);
			}
			if (event.motion.x < positionQuit.x + positionQuit.w && event.motion.x > positionQuit.x && event.motion.y < positionQuit.y + positionQuit.h && event.motion.y > positionQuit.y) {
				quit = IMG_Load("help_green - Copy.png");
				SDL_BlitSurface(quit, NULL, screen, &positionQuit);
				SDL_Flip(screen);
			}
			else {
				quit = IMG_Load("quit.png");
				SDL_BlitSurface(quit, NULL, screen, &positionQuit);
				SDL_Flip(screen);
			}

			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT) {
				if (event.button.x < positionQuit.x + positionQuit.w && event.button.x > positionQuit.x && event.button.y < positionQuit.y + positionQuit.h && event.button.y > positionQuit.y) {

					if (event.button.state == SDL_RELEASED) {
						exit(EXIT_SUCCESS);
					}
				}
				else if (event.motion.x < positionPlay.x + positionPlay.w && event.motion.x > positionPlay.x && event.motion.y < positionPlay.y + positionPlay.h && event.motion.y > positionPlay.y) {
					if (event.button.state == SDL_RELEASED) {
						Mix_FreeMusic(music);
						GamePlay();
						test = 0;
					}

				}
				else if (event.motion.x < positionOption.x + positionOption.w && event.motion.x > positionOption.x && event.motion.y < positionOption.y + positionOption.h && event.motion.y > positionOption.y) {

					if (event.button.state == SDL_RELEASED) {

						menuOption();
						test = 0;
					}

				}
				else if (event.motion.x < positionHelp.x + positionHelp.w && event.motion.x > positionHelp.x && event.motion.y < positionHelp.y + positionHelp.h && event.motion.y > positionHelp.y) {
					if (event.button.state == SDL_RELEASED) {
						test = 0;
					}

				}
			}
			break;
		default:
			break;
		}




		if (State == 1)
		{
			play = IMG_Load("play_green - Copy.png");
			SDL_BlitSurface(play, NULL, screen, &positionPlay);
			SDL_Flip(screen);
		}
		else {
			play = IMG_Load("play.png");
			SDL_BlitSurface(play, NULL, screen, &positionPlay);
			SDL_Flip(screen);
		}
		if (State == 2)
		{

			option = IMG_Load("options_green - Copy.png");
			SDL_BlitSurface(option, NULL, screen, &positionOption);
			SDL_Flip(screen);
		}
		else {
			option = IMG_Load("options.png");
			SDL_BlitSurface(option, NULL, screen, &positionOption);
			SDL_Flip(screen);
		}
		if (State == 3) {

			help = IMG_Load("help_options - Copy.png");
			SDL_BlitSurface(help, NULL, screen, &positionHelp);
			SDL_Flip(screen);
		}
		else {
			help = IMG_Load("help.png");
			SDL_BlitSurface(help, NULL, screen, &positionHelp);
			SDL_Flip(screen);
		}
		if ( State == 4)
		{
			quit = IMG_Load("help_green - Copy.png");
			SDL_BlitSurface(quit, NULL, screen, &positionQuit);
			SDL_Flip(screen);
		}
		else {
			quit = IMG_Load("quit.png");
			SDL_BlitSurface(quit, NULL, screen, &positionQuit);
			SDL_Flip(screen);
		}

		SDL_PollEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			continuer = 0;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_DOWN)

			{
				if (State <= 0) {
					State = 5;
				}
				State--;
				SDL_Delay(100);
			}
			if (event.key.keysym.sym == SDLK_UP)

			{
				if (State >= 5) {
					State = 0;
				}
				State++;
				SDL_Delay(100);
			}
			if (event.key.keysym.sym == SDLK_RETURN)

			{	if (State == 1)//Play
				{
					Mix_FreeMusic(music);
					GamePlay();
					test = 0;
				}
				if (State == 2)//Option
				{
					menuOption();
					test = 0;
				}
				if (State == 3)//Help
				{

				}
				if (State == 4)//Quit
				{
					exit(EXIT_SUCCESS);
				}
			}
		}//Switch

	}

	pause();
	SDL_FreeSurface(play);
	SDL_FreeSurface(option);
	SDL_FreeSurface(help);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(bg_menu);

	SDL_Quit();

	return test;
}

/**********************************************/

void audio(Mix_Music *audio)

{

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("ERROR2");
	}

	audio = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(audio, -1);
}

void loadsprite(Personnage_P* elle)
{	//Load sprite sheet*

	(elle->pos).x = 0;
	(elle->pos).y = 350;
	elle->elle_sprite[0] = IMG_Load("elle1.png");
	elle->elle_sprite[1] = IMG_Load("elle2.png");
	elle->elle_sprite[2] = IMG_Load("elle3.png");
	elle->elle_sprite[3] = IMG_Load("elle4.png");
	elle->elle_sprite[4] = IMG_Load("elle5.png");

	elle->elle_sprite[5] = IMG_Load("elleL1.png");
	elle->elle_sprite[6] = IMG_Load("elleL2.png");
	elle->elle_sprite[7] = IMG_Load("elleL3.png");
	elle->elle_sprite[8] = IMG_Load("elleL4.png");
	elle->elle_sprite[9] = IMG_Load("elleL5.png");

//Set sprite clips
}



SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
	SDL_Color color;
	Uint32 col = 0;
//Determine position
	Uint8* pPosition = (Uint8*)pSurface->pixels;
	pPosition += (pSurface->pitch * y);
	pPosition += (pSurface->format->BytesPerPixel * x);
	memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
//convertir color
	SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}




int CollisionParfaite(Personnage_P elle, SDL_Surface *pSurface)
{
	SDL_Color couleur_obstacle, color;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	int X, Y, W, H;
	X = elle.pos.x;
	Y = elle.pos.y;
	W = elle.pos.w;
	H = elle.pos.h;
	SDL_Rect pos[8];
	pos[0].x = X;
	pos[0].y = Y;
	pos[1].x = X + W / 2;
	pos[1].y = Y;
	pos[2].x = X + W;
	pos[2].y = Y;
	pos[3].x = X;
	pos[3].y = Y + H / 2;
	pos[4].x = X;
	pos[4].y = Y + H;
	pos[5].x = X + W / 2;
	pos[5].y = Y + H;
	pos[6].x = X + W;
	pos[6].y = Y + H;
	pos[7].x = X + W;
	pos[7].y = Y + H / 2;
	int collision = 0;
	int i = 0;
	while ((i < 8) && (collision == 0))
	{
//printf("collision 1 :%d\n",collision);
		couleur_obstacle = GetPixel(pSurface, pos[i].x, pos[i].y);
		printf("RGB :%d %d %d\n", couleur_obstacle.r, couleur_obstacle.g, couleur_obstacle.b);
		if ((couleur_obstacle.r >= color.r && couleur_obstacle.r <= 96) && (couleur_obstacle.g >= color.g && couleur_obstacle.g <= 96) && (couleur_obstacle.b >= color.b && couleur_obstacle.b <= 96)) {
			collision = 1;
//printf("collision 1 :%d\n",collision);
		}
		else {
			i++;
		}
	}

	return collision;
}


int enigme_main(SDL_Surface *ecran) {
	int i = 1;
	enigme e;
	resultat r;
	SDL_Event event;
	SDL_GetTicks();
	e.pos.x = 0;
	e.pos.y = 0;
	r.pos.x = 500;
	r.pos.y = 200;
	e.image = IMG_Load("1.jpg");
	while (i) {
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_a:
				r.image = IMG_Load("00.jpg");
				i = 0;
				break;
			case SDLK_b:
				r.image = IMG_Load("11.jpg");
				i = 0;
				break;
			case SDLK_c:
				r.image = IMG_Load("11.jpg");
				i = 0;
				break;
			}

			break;
		}

		SDL_BlitSurface(e.image, NULL, ecran, &e.pos);
		SDL_BlitSurface(r.image, NULL, ecran, &r.pos);
		SDL_Flip(ecran);
		SDL_Delay(1000);
	}


	return i;

}

int deplacement_perso(SDL_Surface *pSurface, Personnage_P elle, int i, ennemi ennemi_1, ennemi ennemi_2, SDL_Rect camera) {
	int collision;
	if (i == 1) {
		if (camera.x + camera.w >= 3355) {

			collision = CollisionParfaite(elle, pSurface);
			if (collision == 1) {
				elle.pos.x = elle.pos.x;
			}
			else {
				elle.pos.x += 10;
			}
		}
		else {
			elle.pos.x += 10;
			collision = CollisionParfaite(elle, pSurface);
		}

	}
	else if (i == 11) {
		(elle.pos.x ) += 1;
		collision = CollisionParfaite(elle, pSurface);
	}
	else if (i == 2) {
		if (elle.pos.x <= 0) {
			elle.pos.x = 0;
			collision = CollisionParfaite(elle, pSurface);
		}
		else {
			elle.pos.x -= 10;
			collision = CollisionParfaite(elle, pSurface);
		}
	}
	else if (i == 22) {
		elle.pos.x -= 1;
		collision = CollisionParfaite(elle, pSurface);
	}
	int received = 0;
	int directionArduino;
	arduinoReadData(&received);
	switch (received) {
	case 0:
		directionArduino = 0;
		break;
	case 1:
		directionArduino = 1;
		break;
	case 2:
		directionArduino = 2;
		break;
	}
	if ((directionArduino == 1)) {
		elle.pos.x += 10;
	}
	if ((directionArduino == 2 )) {
		elle.pos.x -= 10;
	}
	printf(" collision : %d\n", collision);
	return elle.pos.x;
}

void load_ennemi_1(ennemi *ennemi_1) {




	ennemi_1->pos.x = 1000;
	ennemi_1->pos.y = 30;
	ennemi_1->frame = 0;

	ennemi_1->clip_long[0] = IMG_Load("ghost1.png");
	ennemi_1->clip_long[1] = IMG_Load("ghost2.png");
	ennemi_1->clip_long[2] = IMG_Load("ghost3(1).png");


}

void load_ennemi_2(ennemi *ennemi_2) {


	ennemi_2->pos.x = 700;
	ennemi_2->pos.y = 50;

	ennemi_2->frame = 0;

	ennemi_2->clip[0] = IMG_Load("nour.png");
	ennemi_2->clip[1] = IMG_Load("enn.png");

}

int collision_BB(ennemi ennemi_x, Personnage_P elle, int i) {
	if ((ennemi_x.pos.x >= elle.pos.x + elle.pos.w) || (ennemi_x.pos.x + ennemi_x.pos.w <= elle.pos.x) || (ennemi_x.pos.y >= elle.pos.y + elle.pos.h) || (ennemi_x.pos.y + ennemi_x.pos.h <= elle.pos.y)) {
		i = 0;
	}
	else {
		i = 1;
	}
	return i;
}

int collision_Trigo(Personnage_P elle, cercle C, int i) {
	int d2 = (elle.pos.x - C.x) * (elle.pos.x - C.x) + (elle.pos.y - C.y) * (elle.pos.y - C.y);
	if (d2 >= C.rayon * C.rayon)
		i = 0; //false
	else
		i = 1; //true
	return i;
}


void blitsurfaces(SDL_Surface *ecran, SDL_Surface *background, SDL_Surface *backgroundMasque, SDL_Rect camera, Personnage_P elle, ennemi ennemi_1, ennemi ennemi_2,
                  int frame, life coeur) {
	SDL_Rect posMaske;
	posMaske.x = 0;
	posMaske.y = 0;

	SDL_BlitSurface(backgroundMasque, &camera, ecran, &posMaske);
	SDL_BlitSurface(background, &camera, ecran, NULL);
	//SDL_BlitSurface(backgroundMasque, &camera, ecran, &posMaske);
	SDL_BlitSurface( elle.elle_sprite[frame], NULL, ecran, &elle.pos);
	SDL_BlitSurface( ennemi_1.clip_long[ennemi_1.frame], NULL, ecran, &ennemi_1.pos);
	SDL_BlitSurface( ennemi_2.clip[ennemi_2.frame], NULL, ecran, &ennemi_2.pos);
	SDL_BlitSurface(coeur.image1, NULL, ecran, &coeur.pos1);

	SDL_Flip(ecran);
}




int mouvement_ennemi(int x) {
	int sens = 0;
	if (x == 500) {
		x -= 300;
	}
	else {
		if ( x >= 0) {
			x += 10;
		}
	}

	printf("pos 1 :%d\n", x);



	return x;
}


int type_de_collision(SDL_Surface *backgroundMasque, ennemi ennemi_1, ennemi ennemi_2, Personnage_P elle) {
	int collision = 0;
	cercle c1, c2;


}

int arduinoWriteData(int x)
{
	char chemin[] = "/home/saidi/ttyACM0";
	FILE*f;

	f = fopen(chemin, "w");
	if (f == NULL)
		return (-1);

	fprintf(f, "%d", x);
	fclose(f);

	return (0);
}

int arduinoReadData(int *x)
{
	char chemin[] = "/home/saidi/ttyACM0";
	FILE*f;
	char c;
	f = fopen(chemin, "r");

	if (f == NULL)
		return (-1);

	fscanf(f, "%d", x);

	fclose(f);

	return (0);
}




