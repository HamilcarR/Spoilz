#ifndef VIEW_H
#define VIEW_H
#include "Controller.h"
#include "Grid.h" 
#include <ncurses.h>
#include "Constants.h"


typedef std::vector<std::vector<GAME_SYMBOLS_ENUM>> SYMBOLS_MAP ; 



class CurseView {

	public:
		CurseView() ; 
		CurseView(int lines_count , int columns_count , int origin_y0 , int origin_x0); 
		virtual ~CurseView();
		void draw(SYMBOLS_MAP &room) ; 
		void writeStatusMessage(std::string& message) ; 
		void end(); 		
		

	private:
		WINDOW * _window ; 


};



/*************************************************************************************************************/
class Controller ; 
/*graphics */
class View{
public:
	View(); 
	View(Controller* controller , VIEW_MODE mode) ; 
	virtual ~View(); 
	virtual void draw(SYMBOLS_MAP &room) ; 
	void setMode(VIEW_MODE mode){_mode = mode ; } ; 
	void setController(Controller * controller){_controller = controller ; } ; 
	void init(VIEW_MODE mode) ; 
	void end() ;
	void writeStatusMessage(std::string& message);

private:



	void init_view() ;
	void init_gui() ; 
	
	CurseView _curse ; 
	VIEW_MODE _mode ;
	Controller* _controller ;//stack variable , no need to destroy 	
	



}; 















#endif














