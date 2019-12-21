#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "View.h" 



class View ; 
class Controller{
public:
	Controller();
	virtual ~Controller(); 









private:
	std::unique_ptr<View> _view ; 




};





















#endif 
