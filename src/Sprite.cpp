//
// Created by moritz on 20.08.15.
//

#include "Sprite.h"
#include "App.h"

Sprite::Sprite(uint id) {
    if(App::get()->textures.size() <= id){
        FILE_LOG(logERROR) << "Texture ID Error: " << id;
        id= 0;
    }
    App * app = App::get();
    textureId = id;
    pivot = {0,0};
    angle = 0;
    scale = 1;
    int w, h;
    SDL_QueryTexture(app->textures[textureId], NULL, NULL, &w, &h);
    srcRect = {0,0, w,h};

    mod = {255, 255, 255, 255, SDL_BLENDMODE_BLEND};
}

Sprite::~Sprite() {

}

void Sprite::draw(int x, int y) {
    App * app = App::get();
    SDL_Renderer * ren = App::get()->ren->renderer;
    Point scaledPivot = {pivot.x * scale,
                         pivot.y * scale};
    Rect destRect = {
            x - scaledPivot.x,
            y - scaledPivot.y,
            srcRect.w * scale,
            srcRect.h * scale};


    applyMod(app->textures[textureId]);

    SDL_RenderCopyEx(ren, app->textures[textureId], &srcRect, &destRect, angle, &scaledPivot, SDL_FLIP_NONE);
}

void Sprite::draw(int x, int y, double angle, double scale) {
    this->scale = scale;
    this->angle = angle;
    this->draw(x,y);
}

void Sprite::applyMod(Texture *tex) {
    SDL_SetTextureColorMod(tex, mod.r, mod.g, mod.b);
    SDL_SetTextureAlphaMod(tex, mod.alpha);
    SDL_SetTextureBlendMode(tex, mod.blend);
}
