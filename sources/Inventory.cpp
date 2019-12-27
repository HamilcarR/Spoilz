#include "../includes/Inventory.h"


Inventory::Inventory(){
	_maximum_capacity = START_INV_CAPACITY ; 
		
}

/****************************************************************************************/
Inventory::~Inventory(){


}


/****************************************************************************************/
OPERATION_STATUS Inventory::add(GAME_SYMBOLS_ENUM s){
	_inventory.push_back(s) ; 


}



/****************************************************************************************/
Stockable Inventory::retrieve(GAME_SYMBOLS_ENUM s){



}


/****************************************************************************************/
OPERATION_STATUS Inventory::retrieve(int n) {



}
