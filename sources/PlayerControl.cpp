#include "../includes/PlayerControl.h"



typedef enum KEYBOARD_SHORTCUTS {
	SCT_MOVE_UP = 0 , 
	SCT_MOVE_DOWN , 
	SCT_MOVE_LEFT , 
	SCT_MOVE_RIGHT, 
	SCT_INVENTORY ,
	SCT_HIT       } KEYBOARD_SHORTCUTS ; 









PlayerControl::PlayerControl(){



}


PlayerControl::~PlayerControl(){




}


std::string PlayerControl::processInput(int n ){
	

	return std::string("message is ")+std::to_string(n); 	
}
