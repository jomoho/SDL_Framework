/*
 * AppState.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: Moritz Laass
 */
#include "App.h"
#include "Sprite.h"
#include "Text.h"

AppState::AppState(): timer(0){
}

AppState::~AppState() {
	// TODO Auto-generated destructor stub
}

void AppState::draw(){
    auto r = App::get()->ren;
    SDL_SetRenderDrawColor(r->renderer, 255, 155, 0, 255);

	Sprite s(0);
    s.pivot ={150,250};
    s.angle = r->time*6;
    s.draw(r->width/2,r->height/2);

    Text t("Some Text!!!", {0, 150, 255});

    t.drawCenter(r->width / 2, r->height / 4, 2.0);
}
void AppState::next(int branch){
	App::get()->nextState(branch);
}
void AppState::pump(const SDL_Event &event){

}

AppState *AppState::getNext(int branch) {
    return nullptr;
}
