#include "../includes/GameObjects.h"


Object::Object(int x , int y , float life) {
	_posX = x ; 
	_posY = y ; 
	_life = life ; 

}




Object::Object(const Object &object){
	_posX = object.getPosX() ; 
	_posY = object.getPosY() ; 
	_life = object.getLife() ; 

}



Object::~Object(){



}

/*************************************************************************************************************/
Wall::Wall(){


}

Wall::Wall(int x , int y , float life):Object(x , y , life){



}

Wall::~Wall(){




}


/*************************************************************************************************************/
Chest::Chest(){


}



Chest::Chest(int x , int y , float life):Object(x , y , life){


}




Chest::~Chest(){



}





































