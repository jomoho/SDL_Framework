//
// Created by moritz on 20.08.15.
//

#ifndef SDL_FRAMEWORK_SPRITE_H
#define SDL_FRAMEWORK_SPRITE_H

#include "RendererSDL.h"
typedef Uint32 uint;
struct DrawMod {
    uint8_t r,g,b, alpha;
    SDL_BlendMode blend;
};

class Sprite {
private:
    DrawMod mod;
    void applyMod(Texture *tex);
public:

    uint textureId;
    Rect srcRect;
    Point pivot;
    double angle;
    double scale;
    Sprite(uint id);
    virtual ~Sprite();

    void draw(int x, int y);
    void draw(int x, int y, double angle, double scale);
};


#endif //SDL_FRAMEWORK_SPRITE_H
