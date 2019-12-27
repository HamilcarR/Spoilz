#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H
#include "PlayerControl.h" 

/*Enemy entity : has AI component _behavior*/
class EnemyEntity: public PlayerControl{
public:
	EnemyEntity() ; 
	std::string processInput(int input , SYMBOLS_MAP &tiles) ; //takes an input and the array with the position of the player in it 
	


protected:
	EntityAI _behavior ; 
	


};



#endif
