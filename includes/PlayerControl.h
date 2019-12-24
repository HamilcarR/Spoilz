#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H
#include "GameObjects.h"
#include "Inventory.h"

class PlayerControl: public Object{

public:
	PlayerControl();
	virtual ~PlayerControl() ;
	std::string processInput(int input) ;//process keyboard input ... movements , inventory etc . returns a status message 

private:
	Inventory _inventory ; 	

};

#endif
