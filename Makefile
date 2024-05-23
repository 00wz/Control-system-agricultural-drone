CURSES_PATH = curses/pdcurses.a

all: clean main

main: main.o carts.o drow_functions.o
	gcc -o main main.o carts.o drow_functions.o $(CURSES_PATH)

main.o: main.c
	gcc -c -o main.o main.c

carts.o: carts.c
	gcc -c -o carts.o carts.c

drow_functions.o: drow_functions.c
	gcc -c -o drow_functions.o drow_functions.c

clean:
	del /q *.o main.exe