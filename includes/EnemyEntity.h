#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H
#include "PlayerControl.h" 

/*Enemy entity : 
 * -Will detect the player if entering in his FOV 
 * -Will try fight of flight , or seek objects
 *
 * */
class EnemyEntity: public EntityControl {
public:
	EnemyEntity() ; 
	virtual ~EnemyEntity() ; 
	std::string processInput(int input , SYMBOLS_MAP &tiles) ; 
	int input() ; //provides inputs from the _behavior component ie , the AI algorithm  
	void processObject()  ; 


protected:
	EntityAI _behavior ; //AI behavior : Path tracing + A* algorithm 
	Object *_target ; // Actual target of the Enemy : can be the player , or an object to equip. 

};



#endif
