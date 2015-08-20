/*
 * AppState.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: Moritz Laass
 */
#include "App.h"
#include "AppState.h"

AppState::AppState(): timer(0){
}

AppState::~AppState() {
	// TODO Auto-generated destructor stub
}

void AppState::draw(){
	
}
void AppState::next(int branch){
	App::get()->nextState(branch);
}
void AppState::pump(const SDL_Event &event){

}

