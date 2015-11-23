//
// Created by moritz on 20.08.15.
//

#ifndef SDL_FRAMEWORK_SPRITE_H
#define SDL_FRAMEWORK_SPRITE_H

#include <vector>
#include "PlatformSDL.h"
#include "framework_math.h"

struct Sprite;


struct SpriteDefinition {
    char name [32];
    uint32 textureId;
    vec2 pivot;
    Rect srcRect;
};

struct SpriteAtlas {
    std::vector<SpriteDefinition> definitions;
    int32 parseJSONArray(string json);
    int32 loadFile(string filename);
    void makeSprite(uint32 spriteId, Sprite* sprite);
    int32 getSpriteId(char * name);
    void destroy();
};

struct DrawMod {
    uint8_t r,g,b, alpha;
    SDL_BlendMode blend;
};

struct Sprite {
    enum : uint16{
        SPRITE_FLAG_UPDATE_DEST = 1
    };
    //DrawMod mod;
    //void applyMod(Texture *tex);

    uint16 textureId;
    uint16 flags;
    float32 scale;
    vec2 pivot;
    Rect srcRect, destRect;

    Sprite(uint16 id);
    Sprite();
    void draw(int32 x, int32 y, float32 angle);

    void drawStraight(uint32 x, uint32 y);
    void drawStraight333(uint32 x, uint32 y);
};


#endif //SDL_FRAMEWORK_SPRITE_H
