/*
 * PlatformSDL.h
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

#ifndef PLATFORMSDL_H_
#define PLATFORMSDL_H_

#include <string>
#include <chrono>
#include "Log.h"
#include "framework.h"


typedef SDL_Point Point;
typedef SDL_Rect Rect;
typedef SDL_Texture Texture;
typedef SDL_Color Color;


using namespace std;

struct render_sprite{
	uint32 tex_id;
	uint16 src_x, src_y;
	uint16 src_w, src_h;
	uint16 dest_x, dest_y;
	uint16 dest_w, dest_h;
	uint16 pivot_x, pivot_y;
	float32 angle;
};

struct PlatformSDL {

	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;
	uint32 frames, width, height;
	float64 time, deltaTime, lastTime;

    PlatformSDL(const string &title, uint32 width, uint32 height, bool fullscreen = false);
	virtual ~PlatformSDL();
	void startFrame();
	void endFrame();
	const string& getTitle();
	void setTitle(const string& title);
    float64 getFps() const {
        return fps;
    }
private:
    std::chrono::high_resolution_clock::time_point t_now, t_last, t_start;
	string title;
	float64 fps;
};

#endif /* PLATFORMSDL_H_ */
