//
// Created by moritz on 20.08.15.
//

#ifndef SDL_FRAMEWORK_SCENE_H
#define SDL_FRAMEWORK_SCENE_H

//#include "Box2D/Box2D.h"
#include "SDLDebugDraw.h"

class Scene {
public:
    //b2World *world;
    SDLDebugDraw debugDraw;
    Scene();
    ~Scene();
    void update(float dt);
};


#endif //SDL_FRAMEWORK_SCENE_H
