#include <stdio.h>
#include "curses/curses.h"
#include "carts.h"

static int screen_row;
static int screen_col;

//initialization
void enable_draw()
{
	initscr();
	getmaxyx(stdscr, screen_row, screen_col);
}

//get rows and columns count
void get_shape(int *row, int *col)
{
	*row = screen_row;
	*col = screen_col;
}

void drow_carts(cart *head)
{
	while(head)
	{
		mvprintw( head -> pos.y, head -> pos.x, "*" );
		head = head -> next;
	}
}

void draw_clear_field()
{
	clear();
	/*initscr(); //Инициализация curses

    //mvprintw прежде чем вывести строку, переведёт координаты курсора в заданную позицию
    mvprintw( 5, 5, "Hello, World!" );
    getch();  //Ожидаем нажатия клавиши

    endwin(); //Выход из curses*/

 /*
	// инициализация (должна быть выполнена 
	// перед использованием ncurses)
	initscr();
	
	// Измеряем размер экрана в рядах и колонках
	int row, col;
	getmaxyx(stdscr, row, col);
  
	// перемещение курсора в стандартном экране
	move(row / 2, col / 2);

	printw("Hello world"); // вывод строки
	//refresh(); // обновить экран
	getch(); // ждём нажатия символа
  
	endwin(); // завершение работы с ncurses
*/
	
	for(int i = 0; i < screen_col; i++)
	{
		mvprintw( 0, i, "#" );
	}
	for(int i = 0; i < screen_col; i++)
	{
		mvprintw( screen_row - 1, i, "#" );
	}
	for(int i = 0; i < screen_row; i++)
	{
		mvprintw( i, 0, "#" );
	}
	for(int i = 0; i < screen_row; i++)
	{
		mvprintw( i, screen_col - 1, "#" );
	}
}

//close curses
void disable_draw()
{
	endwin(); // завершение работы с ncurses
}

