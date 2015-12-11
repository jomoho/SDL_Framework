//
// Created by moritz on 20.08.15.
//

#ifndef SDL_FRAMEWORK_SPRITE_H
#define SDL_FRAMEWORK_SPRITE_H

#include <vector>
#include "PlatformSDL.h"
#include "framework_math.h"

struct Frame;


struct FrameDefinition {
    char name [32];
    uint32 textureId;
    vec2 pivot;
    Rect srcRect;
};

struct SpriteAtlas {
    std::vector<FrameDefinition> definitions;
    int32 parseJSONArray(string json);
    int32 loadFile(string filename);
    void makeFrame(uint32 frameId, Frame *frame);
    int32 getFrameId(char *name);
    void destroy();
};

struct DrawMod {
    uint8_t r,g,b, alpha;
    SDL_BlendMode blend;
};

struct Frame {
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

    Frame(uint16 id);
    Frame();
    void draw(int32 x, int32 y, float32 angle);
    void draw(vec2 pos, float32 angle);

    void drawStraight(uint32 x, uint32 y);
    void drawStraight333(uint32 x, uint32 y);
};


typedef struct Anim{

    enum AnimMode:uint8 {
        PlayOnce,
        Loop,
        PingPong,
        PingPongOnce
    };
    enum AnimState:uint8 {
        Stop,
        Running
    };

    uint16 frame_count;
    uint8 anim_mode;
    uint8 anim_state;
    uint16 current_frame;
    float32 time_length;
    float32 time_current;
    SpriteAtlas *atlas;
    uint32 *frames;

    void update(float32 delta){
    };
} Anim;

#endif //SDL_FRAMEWORK_SPRITE_H
