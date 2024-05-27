CURSES_PATH = curses/pdcurses.a

all: clean main

main: main.o carts.o draw_functions.o pumpkins.o position.o
	gcc -o main main.o carts.o draw_functions.o $(CURSES_PATH) pumpkins.o position.o

main.o: main.c
	gcc -c -o main.o main.c

carts.o: carts.c
	gcc -c -o carts.o carts.c

draw_functions.o: draw_functions.c
	gcc -c -o draw_functions.o draw_functions.c

pumpkins.o: pumpkins.c
	gcc -c -o pumpkins.o pumpkins.c

position.o: position.c
	gcc -c -o position.o position.c

clean:
	del /q *.o main.exe