#include "../includes/Constants.h" 
#include "../includes/GameObjects.h"
#include "../includes/View.h" 
#include "../includes/Grid.h" 
#include "../includes/Controller.h" 




int main (int argc , char **argv){
	View view = View(nullptr , VIEW_MODE_CURSES) ; 
	Controller controller = Controller(&view) ;
	view.setController(&controller);
	
	controller.mainProgram(VIEW_MODE_CURSES) ;
return EXIT_SUCCESS ; 
}
