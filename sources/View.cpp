#include "../includes/View.h"







View::View(){
	_controller = nullptr; 
	_curse = CurseView() ; 
}




View::View(Controller *controller , VIEW_MODE mode){
	_controller = controller ;
	_curse = CurseView() ; 
	_mode = mode ; 
//	init_view() ; 
}


View::~View(){


}




void View::init_view(){
	if(_mode != VIEW_MODE_CURSES)
		init_gui() ; 

}



void View::init_gui(){
//TODO  : GUI here
}


void View::draw(SYMBOLS_MAP &room){
	_curse.draw(room) ; 
}


//Initialize the view 
void View::init(VIEW_MODE mode){
	_mode = mode ; 
	if(_mode == VIEW_MODE_CURSES){
		initscr();
		noecho();

	}
	else{
	init_gui(); 

	}



}


void View::end(){
	if(_mode == VIEW_MODE_CURSES)
	_curse.end();

}

void View::writeStatusMessage(std::string& message){
	if(_mode == VIEW_MODE_CURSES){
		_curse.writeStatusMessage(message); 

	}
	else{

	//TODO gui 
	}


}

/********************************************************************************************************/

CurseView::CurseView(){
//	_window = newwin(DEFAULT_ROW , DEFAULT_COL , ORIGIN_Y , ORIGIN_X) ; 
	_window = nullptr ; 

}




CurseView::CurseView(int lines , int columns , int y0 , int x0){
	_window = newwin(lines , columns , y0 , x0) ; 

	

}



CurseView::~CurseView(){
	if( _window != nullptr)
		delwin(_window) ; 


}



void CurseView::draw(SYMBOLS_MAP &room){
	int offset = OFFSET_MAP_Y ; 
	refresh() ; 
	for(int i = 0 ; i < room.size() ; i++){
		for(int j = 0 ; j < room[i].size() ; j++){
			move(j , offset + i) ;
			const char tile_character = SYMBOLS_CHAR[room[i][j]] ; 
			addch(tile_character | A_BOLD ) ;

		}
		addch(' '); 

	}

}



void CurseView::writeStatusMessage(std::string& message){
		
	mvprintw(STATUS_MESSAGE_X , STATUS_MESSAGE_Y , message.c_str()) ; 


}



void CurseView::end(){
	endwin();

}



