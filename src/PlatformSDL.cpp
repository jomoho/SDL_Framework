/*
 * PlatformSDL.cpp
 *
 *  Created on: Aug 24, 2013
 *      Author: moritz
 */

#include "PlatformSDL.h"

PlatformSDL::PlatformSDL(const string &title, uint32 width, uint32 height, bool fullscreen) {
    frames = 0;
    this->width = width;
    this->height = height;
    this->title = string(title);

    t_start = std::chrono::high_resolution_clock::now();
    t_now = std::chrono::high_resolution_clock::now();
    t_last = std::chrono::high_resolution_clock::now();

    if(SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO) < 0){
        FILE_LOG(logWARNING) << "SDL_Init Error: " << SDL_GetError() << endl;
    }


    int windowflags = SDL_WINDOW_SHOWN;
    if(fullscreen){
        windowflags = windowflags|SDL_WINDOW_FULLSCREEN;
    }


    // Create a sdlWindow
    sdlWindow = SDL_CreateWindow(
            title.c_str() ,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            windowflags);

    if (sdlWindow == NULL){
        FILE_LOG(logWARNING) << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
    }

    sdlRenderer = SDL_CreateRenderer(
            sdlWindow, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (sdlRenderer == NULL){
        FILE_LOG(logWARNING) << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
    }
}

PlatformSDL::~PlatformSDL() {

    // Done! Close the sdlWindow, clean-up and exit the program.
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
}

const string&PlatformSDL::getTitle() {
    return title;
}

void PlatformSDL::setTitle(const string& title) {
    this->title = title;
}

void PlatformSDL::startFrame() {
    SDL_RenderClear(sdlRenderer);
}

void PlatformSDL::endFrame() {
    SDL_RenderPresent(sdlRenderer);

    t_last = t_now;
    t_now = std::chrono::high_resolution_clock::now();

    deltaTime =std::chrono::duration<double>(t_now-t_last).count();
    time = std::chrono::duration<double>(t_now-t_start).count();
    lastTime = std::chrono::duration<double>(t_last-t_start).count();
    if (deltaTime != 0.0) {
        fps = 1.0 / deltaTime;
    }
    //fpsBuf[frames % 32] = fps;
    frames += 1;
}