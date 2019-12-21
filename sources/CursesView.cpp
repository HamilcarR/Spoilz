#include "../includes/CursesView.h"
#include <ncurses.h> 









void init_curses(){

	initscr();
	cbreak() ; 
	noecho();
	keypad(stdscr , TRUE) ; 





}





void end_curses(){

	endwin(); 

}
