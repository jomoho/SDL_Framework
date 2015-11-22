//
// Created by moritz on 22.11.2015.
//

#include "Input.h"

void Input::update() {
        int32 x, y;
        SDL_PumpEvents();
        uint32 mb = SDL_GetMouseState(&x, &y);
        mouse.x = (float32) x;
        mouse.y = (float32) y;
        mouseA = mb & SDL_BUTTON(SDL_BUTTON_LEFT);
        mouseB = mb & SDL_BUTTON(SDL_BUTTON_RIGHT);
}

void Input::keyPump(SDL_Event event) {
    bool32 state = 0;
    if(event.key.type == SDL_KEYDOWN) {
        state = 1;
    }
    switch (event.key.keysym.sym){
        case SDLK_w:{
            up = state;
        }break;
        case SDLK_a:{
            left = state;
        }break;
        case SDLK_s:{
            down = state;
        }break;
        case SDLK_d:{
            right = state;
        }break;
        case SDLK_RSHIFT:
        case SDLK_LSHIFT:{
            shift = state;
        }break;
        case SDLK_SPACE:{
            space = state;
        }break;
    }


}
