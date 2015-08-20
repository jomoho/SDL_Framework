/*
 * App.cpp
 *
 *  Created on: Aug 24, 2013
 *      Author: Moritz Laass
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iterator>
#include <typeinfo>
#include "stringtools.h"

#include "App.h"
#include "Log.h"

#include "SDL2/SDL_image.h"

SDL_Color App::black = { 0, 0, 0 };
SDL_Color App::white = { 255, 255, 255 };

App::App() {
#ifdef _DEBUG
	debug = true;
	FILELog::ReportingLevel() = logDEBUG3;
#else
	debug = false;
	FILELog::ReportingLevel() = logWARNING;
#endif

	FILE* log_fd = fopen("logfile.txt", "w");
	Output2FILE::Stream() = log_fd;

	ren = new RendererSDL(APP_TITLE, APP_WIDTH, APP_HEIGHT, 60);
	quit = false;
	next_state = 0;
	state = NULL;

	// load support for PNG images
	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted & flags) != flags) {
		FILE_LOG(logWARNING) << "Error initializing SDL_image" << IMG_GetError();
	}

	loadFonts();
	loadTextures();

	IMG_Quit();
}

App::~App() {
	freeTextures();

	freeFonts();
	SDL_StopTextInput();
	TTF_Quit();

	delete ren;
}

App * App::instance = 0;

App* App::get() {
	if (instance == 0) {
		instance = new App();
	}
	return instance;
}

void App::destroyInstance() {
	if (instance != 0) {
		delete instance;
	}
	instance = 0;
}

void App::start(){

}

void App::loadFonts() {
	TTF_Init();
	TTF_Font *font;
	font = TTF_OpenFont("fonts/DroidSansMono.ttf", 12);
	if (font == NULL) {
		FILE_LOG(logERROR) << "TTF_OpenFont Error: " << TTF_GetError();
	} else {
		fonts.push_back(font);
	}

	font = TTF_OpenFont("fonts/DroidSansMono.ttf", 16);
	if (font == NULL) {
		FILE_LOG(logERROR) << "TTF_OpenFont Error: " << TTF_GetError();
	} else {
		fonts.push_back(font);
	}
}

void App::freeFonts() {
	for (vector<TTF_Font*>::size_type i = 0; i < fonts.size(); ++i) {
		TTF_CloseFont(fonts[i]);
	}
	fonts.empty();
	TTF_Quit();
}

SDL_Texture * App::loadTexture(const string &filename) {
	SDL_Surface *srf;
	srf = IMG_Load_RW(SDL_RWFromFile(filename.c_str(), "rb"), 1);
	if (!srf) {
		FILE_LOG(logERROR) << "loadTexture Error: " << IMG_GetError();
	}
	SDL_Texture * tex;
	tex = SDL_CreateTextureFromSurface(ren->renderer, srf);

	SDL_FreeSurface(srf);
	return tex;
}

void App::loadTextures() {

}

void App::freeTextures() {
	for (vector<SDL_Texture*>::size_type i = 0; i < textures.size(); ++i) {
		SDL_DestroyTexture(textures[i]);
	}
	textures.empty();
}
int last_fps = 30;
void App::drawDebug(){
	int fps = 1000/MAX(ren->tick_diff, 1);
	stringstream s;
	s <<"Frames: " << ren->frames << "/" << ren->droped_frames <<" fps: " << (last_fps + fps)*0.5 ;
	TextElement txt(s.str(), white);
	txt.drawLeft(16, 16, 1.0);

	last_fps = fps;
}

void App::run() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if(state)
			state->pump(event);

		if (event.type == SDL_QUIT || event.type == SDL_QUIT)
			quit = true;
	}

	ren->startFrame();
		if(state){
			state->draw();
		}
		if(debug){
			drawDebug();
		}
	ren->endFrame();

	if(state){
		state->timer += ren->tick_diff;
		if (next_state > 0) {
			switchNextState();
		}
	}
}

void App::nextState(int branch) {
	FILE_LOG(logDEBUG3) << state->name << "->>nextState " << branch;
	next_state = branch;
}

void App::switchNextState() {
	AppState * new_state = state->getNext(next_state);

	if (new_state == NULL) {
		FILE_LOG(logDEBUG3) << "Exit strategy " << next_state;
		quit = true;
	} else {
		delete state;
		state = new_state;
		FILE_LOG(logDEBUG3) << "STATE: " << state->name;
	}

	next_state = -1;
}
