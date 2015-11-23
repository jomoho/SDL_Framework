//
// Created by moritz on 22.11.2015.
//

#ifndef SDL_FRAMEWORK_MAP_H
#define SDL_FRAMEWORK_MAP_H

#include <string>
#include "framework.h"
#include "Camera.h"

struct Map {
    uint16 width, height;
    uint16 tile_width, tile_height;
    uint16 tile_count;
    uint16 atlas;

    uint16 * tiles;
    uint16 * map;


    void drawtiles(Camera cam );
};


#endif //SDL_FRAMEWORK_MAP_H
