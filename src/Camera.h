//
// Created by moritz on 22.08.15.
//

#ifndef SDL_FRAMEWORK_CAMERA_H
#define SDL_FRAMEWORK_CAMERA_H


#include "framework.h"
#include "framework_math.h"

/**
 * The camera center is the screen center
 * by moving the position
 */
struct Camera {

    float32 screenWidth, screenHeight;
    vec2 positionWorld, positionScreen;
    float32 zoom;
    float32 angle;

    vec2 screenToWorld(vec2 screen_pos);
    vec2 worldToScreen(vec2 world_pos);

    Camera(float32 w, float32 h);

};

#endif //SDL_FRAMEWORK_CAMERA_H
