//
// Created by moritz on 22.11.2015.
//

#include "Map.h"
#include "Game.h"

void Map::drawTiles(Camera *cam) {
    vec2    topleft(0,0),
            bottomright(cam->screenWidth, cam->screenHeight);

    //get camera rectangle in world coordinates
    vec2 topleftW = cam->screenToWorld(topleft);
    vec2 bottomRightW = cam->screenToWorld(bottomright);

    // lets do trivial first:
    uint16 ttl_x = MAX( MIN(topleftW.x/tile_width, width), 0);
    uint16 tbr_x = MAX( MIN(bottomRightW.x/tile_width, width), 0);
    uint16 ttl_y = MAX( MIN(topleftW.y/tile_height, height), 0);
    uint16 tbr_y = MAX( MIN(bottomRightW.y/tile_height, height), 0);

    //raster camera rect in map space
    Sprite sprite;
    sprite.scale = cam->zoom;
    sprite.flags = Sprite::SPRITE_FLAG_UPDATE_DEST;

    for (int y = ttl_y; y < tbr_y; ++y) {
        for (int x = ttl_x; x < tbr_x; ++x) {

            //draw each tile with appropriate offset, rotation and scale
            vec2 pos = cam->worldToScreen({x*tile_width, y*tile_height});
            Game::get()->assets.atlases[atlas].makeSprite(get(x,y), &sprite);
            sprite.draw((int32) pos.x, (int32) pos.y, -cam->angle);
        }
        
    }


}

uint16 Map::get(uint16 x, uint16_t y) {
    if(x >= width || y >= height){
        return 0;
    }

    return map[y*width+x];
}

void Map::drawTile(uint16 tileId, vec2 pos, float scale, float angle) {

}
