//============================================================================
// Name        : main.cpp
// Author      : Moritz Laass
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include "PlatformSDL.h"
#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
	Game *app = Game::get();

	app->startup();

	while(!app->quit)  // Enter main loop.
	{
		app->run();
	 }

	Game::destroyInstance();
	return 0;
}
