#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H
#include "GameObjects.h"
#include "Inventory.h"
#include "Constants.h"
#include "Grid.h" 
#include "EntityAI.h" 

typedef std::vector<std::vector<GAME_SYMBOLS_ENUM>> SYMBOLS_MAP ; 

typedef enum KEYBOARD_SHORTCUTS { 
				SHORTCUT_USE = 'e' , 
				SHORTCUT_HIT = 'f', 
				SHORTCUT_INVENTORY = 'i' } KEYBOARD_SHORTCUTS ; 




/*Controls the player's movements, keyboard inputs , iventory , gear , etc*/
class PlayerControl: public Object{

public:
	PlayerControl();
	virtual ~PlayerControl() ;
	virtual std::string processInput(int input , SYMBOLS_MAP &tiles) ;//process keyboard input ... movements , inventory etc . returns a status message 

	 void moveup(SYMBOLS_MAP &tiles);
	 void movedown(SYMBOLS_MAP &tiles);
	 void moveleft(SYMBOLS_MAP &tiles);
	 void moveright(SYMBOLS_MAP &tiles);
	
	 bool hasChangedRoom() const {return _switched_room ; } ; 
	 void newRoom() { _switched_room = false ; } ; 
	 void processObject() ; 
	 void setGrid(Grid *grid){_grid = grid ; } ;

protected:
	Inventory _inventory ; 	
	GAME_SYMBOLS_ENUM _object_on_foot ; //What object is the player standing uppon?
	bool _switched_room ; //true if the player went to another room
	Grid *_grid ; //only a pointer on the grid data structure , no initialization or destruction required here 
};
/***********************************************************************************************************/















#endif
