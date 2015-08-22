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
	friend class App; 	
protected:
    double timer;
public:
    Scene s;
	std::string name;
	virtual AppState * getNext(int branch);
	AppState();
	virtual ~AppState();
	virtual void draw();
	virtual void pump(const SDL_Event &event);

	void next(int branch = 1);
};

#endif /* APPSTATE_H_ */
