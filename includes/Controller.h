#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Constants.h" 
#include "View.h" 
#include "Grid.h"
#include "GameObjects.h" 
#include <ncurses.h>
#include "PlayerControl.h"



class View ; 
class Controller{
public:
	Controller(View* view );
	virtual ~Controller(); 	
	void mainProgram(VIEW_MODE mode); 	


private:

	void initIA() ; 
	
	Grid _grid ;//add player and IA control 
	View* _view ; //stack variable 
	PlayerControl _player ; 



};





















#endif 
