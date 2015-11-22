/*
 * AppState.h
 *
 *  Created on: Aug 25, 2013
 *      Author: Moritz Laass
 */

#ifndef APPSTATE_H_
#define APPSTATE_H_
#ifdef _MSC_VER
#include "SDL_ttf.h"
#else
#include "SDL2/SDL_ttf.h"
#endif

#include <string>
#include "RendererSDL.h"
#include "Scene.h"
class App;

class AppState {
public:

    double timer;
   // Scene s;
	std::string name;
	AppState * getNext(int branch);
	AppState();
	~AppState();
	void draw();
	void pump(const SDL_Event &event);
	void next(int branch = 1);
};

#endif /* APPSTATE_H_ */
