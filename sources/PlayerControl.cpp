#include "../includes/PlayerControl.h"





/****************************************************************************************/
PlayerControl::PlayerControl() : EntityControl(5 , 5 , 100 , TILE_PLAYER){

}
/****************************************************************************************/
PlayerControl::~PlayerControl(){

}
/****************************************************************************************/
void PlayerControl::processObject(){
	if(_object_on_foot == TILE_GATE)
		_switched_room = true ; 
	else if(_object_on_foot != TILE_GATE && _object_on_foot != TILE_CLEAR)
			_inventory.add(_object_on_foot) ; 
}
/****************************************************************************************/
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
			processObject() ; 
		break;
	}

	tiles[getPosY()][getPosX()] = TILE_PLAYER ;
	message = std::string(OBJECT_DESCRIPTION[_object_on_foot]) + "           "  ;  
	return message; 	
}
