//
// Created by moritz on 22.11.2015.
//

#ifndef SDL_FRAMEWORK_MAP_H
#define SDL_FRAMEWORK_MAP_H

#include <string>
#include "framework.h"
#include "Camera.h"

struct Map {

    void load(std::string filename);
    void save(std::string filename);

    void drawtiles(Camera cam );
};


#endif //SDL_FRAMEWORK_MAP_H
