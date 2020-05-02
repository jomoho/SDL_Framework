/*
 * Game.cpp
 *
 *  Created on: Aug 24, 2013
 *      Author: Moritz Laass
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <iomanip>
#include "stringtools.h"
#include "Game.h"
#include "Text.h"

#include "Assets.h"

SDL_Color Game::black = { 0, 0, 0 };
SDL_Color Game::white = { 255, 255, 255 };
SDL_Color Game::red = {255, 0, 0};
SDL_Color Game::green = {0, 255, 0};
SDL_Color Game::blue = {0, 0, 255};

#define _DEBUG 1


void Game::startup(){
#ifdef _DEBUG
    debug = true;
    FILELog::ReportingLevel() = logDEBUG3;
#else
    debug = false;
	FILELog::ReportingLevel() = logWARNING;
#endif

    FILE* log_fd = fopen("logfile.txt", "w");
    Output2FILE::Stream() = log_fd;

    platformSDL = new PlatformSDL(GAME_TITLE, GAME_WIDTH, GAME_HEIGHT);
    quit = false;
    audio.init();
    assets.loadInit();

    map = new Map(16,16);
    camera.screenWidth = (float32) platformSDL->width;
    camera.screenHeight = (float32) platformSDL->height;
    camera.positionScreen = vec2(camera.screenWidth /2,
                                 camera.screenHeight /2);
    /*
    camera.positionWorld = vec2(
            map->tile_width*map->width/2,
            map->tile_height* map->height/2);
    */

}
void Game::tearDown() {
    assets.freeAll();

	SDL_StopTextInput();
	TTF_Quit();

    delete map;
	delete platformSDL;
}

Game *Game::instance = 0;

Game *Game::get() {
	if (instance == 0) {
		instance = new Game();
	}
	return instance;
}

void Game::destroyInstance() {
	if (instance != 0) {
        instance->tearDown();
		delete instance;
	}
	instance = 0;
}

void Game::drawDebug(){
	stringstream s;

    vec2 pos = {platformSDL->width/2.0f, platformSDL->height/2.0f};
    vec2 dir = pos - input.mouse;
    s << std::setprecision(2)
    << "Frames: " << platformSDL->frames
        <<" Time:" << platformSDL->time
    << " FPS: " << (int32)platformSDL->getFps()
    << " mouse: " << (int32) input.mouse.x <<", "<<(int32) input.mouse.y <<": "<<dir.angle() ;
	Text txt(s.str(), white);
	txt.drawLeft(16, 16, 1.0);
    camera.drawDebug();
}

void Game::run() {
    //handle events
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
        eventPump(event);
	}
    input.update();

    //render and update;
	platformSDL->startFrame();
    updateAndRender(platformSDL->deltaTime);

    if(debug){
        drawDebug();
    }
	platformSDL->endFrame();
}

void Game::eventPump(SDL_Event event) {
    input.keyPump(event);
    switch(event.type){
        case SDL_QUIT:{
            quit = true;
        }break;

        default: {
            ;//do nothing
        }
    }
}

void Game::updateAndRender(float64 time) {
    auto platform = platformSDL;

    map->drawTiles(&camera);
    Frame spr(0);
    spr.pivot ={150,250};
    //spr.drawStraight333(sin(platform->time)*45 +45, 12);

    Frame player(2);
    player.pivot = {0.5,0.5};
    player.scale = 2.0;
    player.flags = Frame::SPRITE_FLAG_UPDATE_DEST;


    vec2 pos = {platform->width/2.0f, platform->height/2.0f};
    vec2 dir = pos - input.mouse;

    player.draw(pos.x,pos.y, dir.angle()-HALFPI);

    camera.zoom = 1.0f + 0.5f*sin(platform->time);

    if(input.left){
        camera.positionWorld.x --;
    }
    if(input.right){
        camera.positionWorld.x ++;
    }

    if(input.up){
        camera.positionWorld.y --;
    }
    if(input.down){
        camera.positionWorld.y ++;
    }

    if(input.mouseB) {
        camera.angle += 0.1;

    }
    if(input.mouseA){

        SDL_SetRenderDrawColor(getSDLRenderer(), 0, 0, 0, 255);
        SDL_RenderDrawLine(getSDLRenderer(), pos.x, pos.y,dir.x,dir.y );
    }

    Text t("Some Text!!!", {0, 150, 255});

    t.drawCenter(platform->width / 2, platform->height / 4, 2.0);
    SDL_SetRenderDrawColor(getSDLRenderer(), 255, 155, 0, 255);

    // apply input and update camera

    // update and draw map base layer

    // go through all entities and:
        // run update proc (input/thinking | animations)
        // apply movement
            // if not dynamic collidable but drawable -> draw


    // go through all bodies
        //check for dynamic collisions and solve ->dispatch event
        //check for static collisions and solve ->dispatch event
        //draw entity

    // draw map top layer

    /**
     * types of entities:
     *      ---dynamic + collidable---
     *      player
     *      pickups/weapons
     *      bullets
     *      enemies
     *      doors
     *
     *
     *      ---dynamic non-collidable---
     *      particle systems
     *      decals/blood
     *
     *      ---static collidable---
     *      walls/obstacles (solid)
     *      triggers(air)
     *
     *      ---static non-collidable---
     *      decorations
     *      lights
     *
     *
     */
}

SDL_Renderer *Game::getSDLRenderer() {
    return get()->platformSDL->sdlRenderer;
}

Assets* Game::getAssets() {
    return &(instance->assets);
}

Game::Game(): camera( (float32) GAME_WIDTH, (float32) GAME_HEIGHT) {
    map = 0;
    platformSDL = 0;
    quit = false;
    debug = false;
}
