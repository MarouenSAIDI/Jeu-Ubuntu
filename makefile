prog: 
	gcc jeu.c fonction.c -o prog -lSDL -lSDL_image  -g
clean:
	rm -fr prog

FLAGS = -l /lib64

LIBS = -lSDL -l SDL

execute:
	./prog
