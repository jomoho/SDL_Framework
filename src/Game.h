/*
 * Game.h
 *
 *  Created on: Aug 24, 2013
 *      Author: Moritz Laass
 */

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include <iostream>
#include "PlatformSDL.h"
#include "Audio.h"
#include "Entity.h"
#include "Assets.h"
#include "Input.h"

#define GAME_TITLE "FRAMEWORK DEMO"
#define GAME_WIDTH 640
#define GAME_HEIGHT 480

using namespace std;


struct Game {
    bool32 quit, debug;

	PlatformSDL *platformSDL;
	Audio audio;
    Assets assets;
    Input input;

    static Assets * getAssets();
    static SDL_Renderer *getSDLRenderer();
    static SDL_Color black, white, red, green, blue;

    void tearDown();
    static Game *instance ;
    static Game *get();
    static void destroyInstance();

    void run();
    void startup();
    void drawDebug();
    void eventPump(SDL_Event event);
    void updateAndRender(float64 time);
};

#endif /* GAME_H_ */
