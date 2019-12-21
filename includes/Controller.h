#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "View.h" 
#include "Grid.h"


class View ; 
class Controller{
public:
	Controller();
	Controller(View *v) ; 
	virtual ~Controller(); 
		
	void init_controller(); 


private:
	void generate_grid() ; 
	void player_control() ; 
	void init_IA() ; 
	




	std::unique_ptr<View> _view ; 




};





















#endif 
