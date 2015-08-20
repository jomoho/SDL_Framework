/*
 * Renderer.h
 *
 *  Created on: Aug 24, 2013
 *      Author: Moritz Laass
 */
#ifdef _MSC_VER
	#include "SDL.h"
	#include "SDL_ttf.h"
	#include "SDL_image.h"

#else
	#include "SDL2/SDL.h"
	#include "SDL2/SDL_ttf.h"
	#include "SDL2/SDL_image.h"
#endif

#ifndef RENDERERSDL_H_
#define RENDERERSDL_H_

#include <string>
#include "Log.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


using namespace std;

class RendererSDL {
public:
	RendererSDL(const string& title, Uint32 width, Uint32 height, Uint32 fps, bool fullscreen = false);
	virtual ~RendererSDL();

	void startFrame();
	void endFrame();

	const string& getTitle();
	void setTitle(const string& title);

	SDL_Window *window;
	SDL_Renderer *renderer;
	Uint32 frames, width, height;
	int tick_diff, droped_frames;
private:
	Uint32 last_ticks, fps, tick_interval;
	string title;
};

#endif /* RENDERERSDL_H_ */
