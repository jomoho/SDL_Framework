/*
 * AppState.h
 *
 *  Created on: Aug 25, 2013
 *      Author: Moritz Laass
 */

#ifndef APPSTATE_H_
#define APPSTATE_H_

class App;

class AppState {
	friend class App; 	
protected:
	Uint32 timer;
public:
	string name, instruction;
	virtual AppState * getNext(int branch) = 0;
	AppState();
	virtual ~AppState();
	virtual void draw();
	virtual void pump(const SDL_Event &event);

	void next(int branch = 1);
};

#endif /* APPSTATE_H_ */
