#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H
#include "Constants.h" 



static constexpr float TILE_BLOCKED_HP_MAX = 500.f ;//HP of a wall  
static constexpr float CHEST_HP_MAX = 500.f ; 

class Object{
public:
	Object();
	Object(const Object &object) ; 
	Object(int column_position , int row_position , GAME_SYMBOLS_ENUM _type) ; 
	Object(int column_position , int row_position , float object_life , GAME_SYMBOLS_ENUM _type) ; 
	
	virtual ~Object() ;

	/*setters*/
	virtual void setPosX(int newPos){_posX = newPos ; } ; 
	virtual void setPosY(int newPos){_posY = newPos ; } ; 
	virtual void setLife(int newLife){_life = newLife; } ; 

	/*getters*/
	virtual int getPosX() const {return _posX ; } ; 
	virtual int getPosY() const {return _posY ; } ; 
	virtual int getLife() const {return _life ; } ; 
	/*Object type*/
	virtual  GAME_SYMBOLS_ENUM getType() const {return _type;} ;   


private:
	int _posX ; //position on columns 
	int _posY ; //position on rows 
	float _life ; // life of the object , everything is destructible	
	GAME_SYMBOLS_ENUM _type  ; 
};



/*************************************************************************************************************/
/*Blocked tile */

class Wall : public Object{
public:
	Wall() ; 
	Wall(int x , int y , float life); 

private:

};


/*************************************************************************************************************/
/*Gates link two rooms with each others*/

class Gate : public Object{
public:
	Gate() ; 
	Gate(int x , int y , float life) ; 

private:
	

};



/*************************************************************************************************************/
/*Objects that can be stored in inventories*/

class Stockable : public Object {
public:
	Stockable() ; 
	Stockable(int x , int y , float life , GAME_SYMBOLS_ENUM type) ; 


	

};



/*************************************************************************************************************/
class Inventory ; 
class Chest : public Stockable{
public:
	Chest();
	Chest(int x , int y , float life) ; 

private:
	Inventory *_inventory;


};






























































#endif 
