/*
 * App.h
 *
 *  Created on: Aug 24, 2013
 *      Author: Moritz Laass
 */

#ifndef APP_H_
#define APP_H_

#include <vector>
#include <iostream>
#include "RendererSDL.h"
#include "AppState.h"
#include "Audio.h"

#define APP_TITLE "FRAMEWORK DEMO"
#define APP_WIDTH 640
#define APP_HEIGHT 480

using namespace std;

struct FontDef{
    string filename;
    int size;
};


class App{
   vector<FontDef> fontDefinitions =
            vector<FontDef>({
                                    {"fonts/DroidSansMono.ttf", 12},
                                    {"fonts/DroidSansMono.ttf", 16},
                                    {"fonts/MostlyMono.ttf", 14}
    });

    vector<string> textureDefinitions =
            vector<string>({
                                   "gfx/demo.png"
    });
	
private:
	void loadFonts();
	void freeFonts();

	Texture * loadTexture(const string &filename);

	void loadTextures();
	void freeTextures();

	void switchNextState();
	void drawDebug();

	int next_state;
public:
	App();
	virtual ~App();
	static App *instance ;
	static App *get();
	static void destroyInstance();

	void run();
	void start();

	void nextState(int branch = 0);
	AppState *state;
	RendererSDL *ren;
	bool quit, debug;

	Audio audio;
	vector<TTF_Font *> fonts;
	vector<Texture *> textures;

    static SDL_Color black, white, red, green, blue;
};

#endif /* APP_H_ */
