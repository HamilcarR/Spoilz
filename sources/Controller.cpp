#include "../includes/Controller.h"

Controller::Controller(std::unique_ptr<View> v){

	initialize_rand() ; 
	_view = std::move(v) ; 
	initController() ; 
}



Controller::~Controller(){



}



void Controller::initController() {



}
