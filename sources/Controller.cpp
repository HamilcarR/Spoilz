#include "../includes/Controller.h"



static constexpr char CHARACTER_TABLE[2] = {
	0x08 , 0x1B } ; 




Controller::Controller(View* v){
	initialize_rand() ; 
	_view = v ; 
	_grid = Grid() ;
	_player = PlayerControl() ; 

}



Controller::~Controller(){



}









/*we only send an array with game symbols to the view , instead of full objects */
static SYMBOLS_MAP create_symbol_map(std::vector<std::vector<Tile>> &tiles){
	SYMBOLS_MAP array ;
	for(int i = 0  ; i < tiles.size() ; i++){
		array.push_back(std::vector<GAME_SYMBOLS_ENUM>()) ; 
		for(int j = 0 ; j < tiles[i].size() ; j++){
			array[i].push_back(tiles[i][j]._symbol.getType()) ; 

		}

	}
	return array ; 

}


void Controller::mainProgram(VIEW_MODE mode){ //main loop 	
	_view->init(mode) ; 
	int input = 0;
	
	do{
		
		
		//TODO IA control ;
		std::string status_message = _player.processInput(input) ; 	
		std::vector<std::vector<Tile>> tiles = _grid.getRoom().getTiles() ; 
		SYMBOLS_MAP array = create_symbol_map(tiles); 
		_view->draw(array) ; 
		_view->writeStatusMessage(status_message) ;
		

	
	}
	while((input = getch()) != 27) ;//ESC key 





	_view->end(); 







}
