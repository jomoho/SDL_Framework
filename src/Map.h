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
    uint16 atlas;
    uint16 * map;

    Map(uint16 w, uint16 h);

    void drawTiles(Camera *cam);
    uint16 get(uint16 x, uint16_t y);
    void drawTile(uint16 tileId, vec2 pos, float scale, float angle);
};


#endif //SDL_FRAMEWORK_MAP_H
