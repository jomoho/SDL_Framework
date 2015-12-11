//
// Created by moritz on 20.08.15.
//

#include <fstream>
#include "Frame.h"
#include "Game.h"
#include "picojson.h"

Frame::Frame(uint16 id) {
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

Frame::Frame() {

    textureId = 0;
    pivot = {0,0};
    srcRect = {0,0, 32,32};

    //mod = {255, 255, 255, 255, SDL_BLENDMODE_BLEND};
}

void Frame::draw(int32 x, int32 y, float32 angle) {

    if(flags & SPRITE_FLAG_UPDATE_DEST){
        flags ^= SPRITE_FLAG_UPDATE_DEST;
        destRect.w = srcRect.w * scale;
        destRect.h = srcRect.h * scale;
    }

    Point scaledPivot = {(int32) (pivot.x * destRect.w),
                         (int32) (pivot.y * destRect.h)};
    destRect.x = x - scaledPivot.x;
    destRect.y = y - scaledPivot.y;


    //applyMod(app->textures[textureId]);

    SDL_RenderCopyEx(Game::getSDLRenderer(),
                     Game::getAssets()->textures[textureId],
                     &srcRect, &destRect, angle*RAD_TO_DEG, &scaledPivot, SDL_FLIP_NONE);
}
/*
void Frame::applyMod(Texture *tex) {
    SDL_SetTextureColorMod(tex, mod.r, mod.g, mod.b);
    SDL_SetTextureAlphaMod(tex, mod.alpha);
    SDL_SetTextureBlendMode(tex, mod.blend);
}
 */
void Frame::drawStraight(uint32 x, uint32 y) {
    Rect destRect = {
            (int32) x,
            (int32) y,
            (int32)(srcRect.w ),
            (int32)(srcRect.h )};
    SDL_RenderCopy(Game::getSDLRenderer(),
                     Game::getAssets()->textures[textureId],
                     &srcRect,
    &destRect);
}

void Frame::drawStraight333(uint32 x, uint32 y) {
    Rect destRect = {
            (int32)x,
            (int32)y,
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

void SpriteAtlas::makeFrame(uint32 frameId, Frame *frame) {
    if(frameId < definitions.size()){
        frame->pivot = definitions[frameId].pivot;
        frame->textureId = definitions[frameId].textureId;
        frame->srcRect = definitions[frameId].srcRect;
    }
}

int32 SpriteAtlas::getFrameId(char *name) {
    for (int32 i = 0; i < definitions.size() ; ++i) {
        if(strcmp(name, definitions[i].name) == 0){
            return i;
        }
    }
    return -1;
}

int32 SpriteAtlas::parseJSONArray(string json) {
    definitions.empty();
    picojson::value v;
    std::string err = picojson::parse(v, json);
    if (! err.empty()) {
        FILE_LOG(logERROR) <<"Error parsing JSON "<< err;
        return -1;
    }
    if(v.is<picojson::object>()){
        int32 textureId = 0;
        picojson::object obj = v.get<picojson::object>();
        //parse meta object
        {
            picojson::value metaValue = obj["meta"];
            picojson::object meta = metaValue.get<picojson::object>();

            string image = meta["image"].to_str();
            textureId = Game::get()->assets.getTextureId(image);

        }
        //parse array
        {
            picojson::value arrayValue = obj["frames"];
            picojson::array frames = arrayValue.get<picojson::array>();


            picojson::array::iterator it;
            for (it = frames.begin(); it != frames.end(); it++) {
                FrameDefinition sprite;
                sprite.textureId = textureId;

                picojson::object frame = it->get<picojson::object>();

                //parse srcRect
                {
                    picojson::value rectValue = frame["frame"];
                    picojson::object rect = rectValue.get<picojson::object>();

                    sprite.srcRect.x = (int32) rect["x"].get<double>();
                    sprite.srcRect.y = (int32) rect["y"].get<double>();
                    sprite.srcRect.w = (int32) rect["w"].get<double>();
                    sprite.srcRect.h = (int32) rect["h"].get<double>();
                }

                //parse Pivot
                {
                    picojson::value pValue = frame["pivot"];
                    picojson::object p = pValue.get<picojson::object>();

                    sprite.pivot.x = (float32) p["x"].get<double>();
                    sprite.pivot.y = (float32) p["y"].get<double>();
                }


                //parse Name
                {
                    string name = frame["filename"].to_str();
                    if(name.size()>= 31){
                        name.resize(31);
                    }
                    strcpy(sprite.name, name.c_str());
                }

                //push back
                definitions.push_back(sprite);
            }
        }
    }
    return 0;
}

int32 SpriteAtlas::loadFile(string filename) {
    std::ifstream ifs(filename);
    std::string content;
    content.assign( (std::istreambuf_iterator<char>(ifs) ),
                    (std::istreambuf_iterator<char>()    ) );

    return parseJSONArray(content);
}

void Frame::draw(vec2 pos, float32 angle) {
    draw((int32) pos.x, (int32) pos.y, angle);
}
