#include <stdio.h>
#include "curses/curses.h"

void drow_field()
{
	initscr(); //Инициализация curses

    //mvprintw прежде чем вывести строку, переведёт координаты курсора в заданную позицию
    mvprintw( 5, 5, "Hello, World!" );
    getch();  //Ожидаем нажатия клавиши

    endwin(); //Выход из curses
}
