#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H
#include "GameObjects.h"
#include "Inventory.h"
#include "Constants.h"
#include "Grid.h" 
#include "EntityAI.h" 
#include "EntityControl.h"



typedef enum KEYBOARD_SHORTCUTS { 
				SHORTCUT_USE = 'e' , 
				SHORTCUT_HIT = 'f', 
				SHORTCUT_INVENTORY = 'i' } KEYBOARD_SHORTCUTS ; 




/*Controls the player's movements, keyboard inputs , iventory , gear , etc*/
class PlayerControl: public EntityControl{

public:
	PlayerControl();
	virtual ~PlayerControl() ;
	virtual std::string processInput(int input , SYMBOLS_MAP &tiles) ;//process keyboard input ... movements , inventory etc . returns a status message 	
	 void processObject() ; 

protected:
};
/***********************************************************************************************************/















#endif
