#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H
#include "GameObjects.h"
#include "Inventory.h"
#include "Constants.h"



typedef std::vector<std::vector<GAME_SYMBOLS_ENUM>> SYMBOLS_MAP ; 

typedef enum KEYBOARD_SHORTCUTS { 
				SHORTCUT_USE = 'e' , 
				SHORTCUT_HIT = 'f', 
				SHORTCUT_INVENTORY = 'i' } KEYBOARD_SHORTCUTS ; 





class PlayerControl: public Object{

public:
	PlayerControl();
	virtual ~PlayerControl() ;
	std::string processInput(int input , SYMBOLS_MAP &tiles) ;//process keyboard input ... movements , inventory etc . returns a status message 

	 void moveup(SYMBOLS_MAP &tiles);
	 void movedown(SYMBOLS_MAP &tiles);
	 void moveleft(SYMBOLS_MAP &tiles);
	 void moveright(SYMBOLS_MAP &tiles);
	
	 bool hasChangedRoom() const {return _switched_room ; } ; 
	 void newRoom() { _switched_room = false ; } ; 
	 void process_object() ; 
private:
	Inventory _inventory ; 	
	GAME_SYMBOLS_ENUM _object_on_foot ; //What object is the player standing uppon?
	bool _switched_room ; //true if the player went to another room 
};

#endif
