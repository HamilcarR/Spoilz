#include "../includes/GameObjects.h"


Object::Object(){
	_posX = 0 ; 
	_posY = 0 ; 
	_life = 0 ; 
	_type = TILE_CLEAR ; 

}

Object::Object(int x , int y , GAME_SYMBOLS_ENUM type){
	_posX = x ; 
	_posY = y ; 
	_life = -1. ; 
	_type = type ; 

}

Object::Object(int x , int y , float life, GAME_SYMBOLS_ENUM type) {
	_posX = x ; 
	_posY = y ; 
	_life = life ; 
	_type = type ; 

}




Object::Object(const Object &object){
	_posX = object.getPosX() ; 
	_posY = object.getPosY() ; 
	_life = object.getLife() ;
	_type = object.getType() ; 

}



Object::~Object(){



}

/*************************************************************************************************************/
Wall::Wall(){


}

Wall::Wall(int x , int y , float life):Object(x , y , life , TILE_WALL){



}







/*************************************************************************************************************/
Chest::Chest(){


}



Chest::Chest(int x , int y , float life):Stockable(x , y , life , TILE_CHEST){


}











/*************************************************************************************************************/

Stockable::Stockable(){


}


Stockable::Stockable(int x , int y , float life , GAME_SYMBOLS_ENUM type) : Object(x , y , life , type) {


}






/*************************************************************************************************************/
























