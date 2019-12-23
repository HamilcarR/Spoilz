#ifndef OBJECTDISTRIBUTION_H
#define OBJECTDISTRIBUTION_H
#include "Constants.h" 




class ObjectDistribution{
	public: 
	ObjectDistribution(){
		for(int i = 0 ; i < TILE_CLEAR-TILE_CHEST ; i++){
			random_coefficient[i] = (float) rand() ; 
	
		}

	};
	
	
	float random_coefficient[TILE_CLEAR-TILE_CHEST] ;
	

};

#endif
