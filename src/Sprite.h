//
// Created by moritz on 20.08.15.
//

#ifndef SDL_FRAMEWORK_SPRITE_H
#define SDL_FRAMEWORK_SPRITE_H

#include "PlatformSDL.h"

struct DrawMod {
    uint8_t r,g,b, alpha;
    SDL_BlendMode blend;
};

struct sprite_definition{
    char name [32];
    uint32 texture_id;
    Rect src_rect;
};

struct sprite_atlas{
    uint32 count;
    sprite_definition *definitions;
    int32 load(char * filename);
};

struct Sprite {

    //DrawMod mod;
    //void applyMod(Texture *tex);

    uint32 textureId;
    Rect srcRect;
    Point pivot;

    Sprite(uint32 id);
    void draw(int32 x, int32 y, float32 angle, float32 scale);

    void drawStraight(uint32 x, uint32 y);
    void drawStraight333(uint32 x, uint32 y);
};


#endif //SDL_FRAMEWORK_SPRITE_H
