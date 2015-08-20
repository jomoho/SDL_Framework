//============================================================================
// Name        : main.cpp
// Author      : Moritz Laass
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include "RendererSDL.h"
#include "App.h"

using namespace std;

int main(int argc, char** argv) {
	App *app = App::get();

	app->start();
	while(!app->quit)  // Enter main loop.
	{
		app->run();
	 }

	App::destroyInstance();
	return 0;
}
