CURSES_PATH = curses/pdcurses.a

all: clean main

main: main.o carts.o draw_functions.o
	gcc -o main main.o carts.o draw_functions.o $(CURSES_PATH)

main.o: main.c
	gcc -c -o main.o main.c

carts.o: carts.c
	gcc -c -o carts.o carts.c

draw_functions.o: draw_functions.c
	gcc -c -o draw_functions.o draw_functions.c

clean:
	del /q *.o main.exe