//
// Created by moritz on 20.08.15.
//

#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(uint32 id) {
    if(Game::getAssets()->textures.size() <= id){
        FILE_LOG(logERROR) << "Texture ID Error: " << id;
        id= 0;
    }
    textureId = id;
    pivot = {0,0};

    int w, h;
    SDL_QueryTexture(Game::getAssets()->textures[textureId], NULL, NULL, &w, &h);
    srcRect = {0,0, w,h};

    //mod = {255, 255, 255, 255, SDL_BLENDMODE_BLEND};
}



void Sprite::draw(int32 x, int32 y, float32 angle, float32 scale) {

    Point scaledPivot = {(int32) (pivot.x * scale),
                         (int32) (pivot.y * scale)};
    Rect destRect = {
            x - scaledPivot.x,
            y - scaledPivot.y,
            (int32)(srcRect.w * scale),
            (int32)(srcRect.h * scale)};


    //applyMod(app->textures[textureId]);

    SDL_RenderCopyEx(Game::getSDLRenderer(),
                     Game::getAssets()->textures[textureId],
                     &srcRect, &destRect, angle*RAD_TO_DEG, &scaledPivot, SDL_FLIP_NONE);
}
/*
void Sprite::applyMod(Texture *tex) {
    SDL_SetTextureColorMod(tex, mod.r, mod.g, mod.b);
    SDL_SetTextureAlphaMod(tex, mod.alpha);
    SDL_SetTextureBlendMode(tex, mod.blend);
}
 */
void Sprite::drawStraight(uint32 x, uint32 y) {
    Rect destRect = {
            x,
            y,
            (int32)(srcRect.w ),
            (int32)(srcRect.h )};
    SDL_RenderCopy(Game::getSDLRenderer(),
                     Game::getAssets()->textures[textureId],
                     &srcRect,
    &destRect);
}

void Sprite::drawStraight333(uint32 x, uint32 y) {
    Rect destRect = {
            x,
            y,
            (int32)(srcRect.w ),
            (int32)(srcRect.h )};
    Point scaledPivot ={0,0};
    for(int i = 0; i < 333; i++) {
        destRect.x =x+ (i*123431434)%320;
        destRect.y =y+ (i*3557431434)%320;
        SDL_RenderCopyEx(Game::getSDLRenderer(),
                       Game::getAssets()->textures[textureId],
                       &srcRect,
                       &destRect,1.0f ,&scaledPivot, SDL_FLIP_NONE);
    }

}
