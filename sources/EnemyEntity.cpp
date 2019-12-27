#include "../includes/EnemyEntity.h"




EnemyEntity::EnemyEntity(): EntityControl(1 , 1 , 100 , TILE_ENEMY)  {
	
}
/****************************************************************************************/
EnemyEntity::~EnemyEntity(){


}
/****************************************************************************************/
std::string EnemyEntity::processInput(int input , SYMBOLS_MAP &tiles){

	return " "; 
}

/****************************************************************************************/
int EnemyEntity::input(){


	return 0 ;
}
/****************************************************************************************/


void EnemyEntity::processObject(){


}
