#include "../includes/PlayerControl.h"






PlayerControl::PlayerControl() : Object(5 , 5 , 100 , TILE_PLAYER){
	_switched_room = false ;
	_object_on_foot = TILE_PLAYER ; 

}


PlayerControl::~PlayerControl(){




}



void PlayerControl::moveup(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ;
	 if( tiles[posY][posX-1] != TILE_WALL){
 		setPosX(--posX) ;
		_object_on_foot = tiles[posY][posX] ;
 	}
}

void PlayerControl::movedown(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ; 
	 if( tiles[posY][posX+1] != TILE_WALL){
 		setPosX(++posX) ;
		_object_on_foot = tiles[posY][posX] ; 
 	}

}


void PlayerControl::moveleft(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ; 
	 if( tiles[posY-1][posX] != TILE_WALL){
		 setPosY(--posY) ;
		_object_on_foot = tiles[posY][posX] ; 
 	}

}


void PlayerControl::moveright(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ; 
	 if( tiles[posY+1][posX] != TILE_WALL){
 		setPosY(++posY) ;
		_object_on_foot = tiles[posY][posX] ; 
 	
	 }



}





void PlayerControl::process_object(){



}





std::string PlayerControl::processInput(int n , SYMBOLS_MAP &tiles){
	std::string message ="" ;

	switch(n) {
		case KEY_UP:
			moveup(tiles);	
		break;

		case KEY_DOWN: 
			movedown(tiles);
		break;

		case KEY_LEFT:
			moveleft(tiles);
		break;

		case KEY_RIGHT:
			moveright(tiles);
		break;
		
		case SHORTCUT_USE :
			process_object() ; 
		break;


	}

	tiles[getPosY()][getPosX()] = TILE_PLAYER ;
	message = std::string(OBJECT_DESCRIPTION[_object_on_foot]) + "           "  ;  
	return message; 	
}
