#ifndef VIEW_H
#define VIEW_H
#include "CursesView.h"
#include "Controller.h" 

class Controller ; 
class View{
public:
	View() ; 
	virtual ~View(); 



private:
	std::unique_ptr<Controller> _controller ; 





}; 




#endif














