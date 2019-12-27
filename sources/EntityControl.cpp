#include "../includes/EntityControl.h"







EntityControl::EntityControl(int x , int y , int z , GAME_SYMBOLS_ENUM symbol) : Object(x , y , z , symbol){
		_switched_room = false ; 
		_object_on_foot = symbol ; 

}



/****************************************************************************************/
void EntityControl::moveup(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ;
	 if( tiles[posY][posX-1] != TILE_WALL){
 		setPosX(--posX) ;
		_object_on_foot = tiles[posY][posX] ;
 	}
}

/****************************************************************************************/
void EntityControl::movedown(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ; 
	 if( tiles[posY][posX+1] != TILE_WALL){
 		setPosX(++posX) ;
		_object_on_foot = tiles[posY][posX] ; 
 	}
}
/****************************************************************************************/
void EntityControl::moveleft(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ; 
	 if( tiles[posY-1][posX] != TILE_WALL){
		 setPosY(--posY) ;
		_object_on_foot = tiles[posY][posX] ; 
 	}
}
/****************************************************************************************/
void EntityControl::moveright(SYMBOLS_MAP &tiles){
	 int posY = getPosY() ; 
	 int posX = getPosX() ; 
	 if( tiles[posY+1][posX] != TILE_WALL){
 		setPosY(++posY) ;
		_object_on_foot = tiles[posY][posX] ; 
	 }
}

