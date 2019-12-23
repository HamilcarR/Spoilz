#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Constants.h" 
#include "View.h" 
#include "Grid.h"
#include "GameObjects.h" 

class View ; 
class Controller{
public:
	Controller(std::unique_ptr<View> v);
	virtual ~Controller(); 	
	void initController(); 


private:
	void generateGrid() ; 
	void playerControl() ; 
	void initIA() ; 
	

	std::unique_ptr<View> _view ; 




};





















#endif 
