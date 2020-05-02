//
// Created by moritz on 22.11.2015.
//

#ifndef SDL_FRAMEWORK_INPUT_H
#define SDL_FRAMEWORK_INPUT_H


#include <SDL_mouse.h>
#include <SDL_events.h>
#include "framework_math.h"

struct Input {
    vec2 mouse;
    bool32 mouseA,mouseB,
    up,down,left,right,
    shift,space;

    void keyPump(SDL_Event event);
    void update();
};


#endif //SDL_FRAMEWORK_INPUT_H
