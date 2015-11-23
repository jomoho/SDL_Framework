//
// Created by moritz on 22.08.15.
//

#include "Camera.h"

Camera::Camera(float w, float h):
positionWorld(0,0),
positionScreen(w/2,h/2)
{
    screenWidth = w;
    screenHeight = h;
    zoom = 1.0f;
    angle = 0.0f;
}

vec2 Camera::screenToWorld(vec2 screen_pos) {
    vec2 worldpos = screen_pos - positionScreen;
    worldpos.rotate(angle);
    worldpos /= zoom;
    worldpos += positionWorld;
    return worldpos;
}

vec2 Camera::worldToScreen(vec2 world_pos) {
    vec2 screenpos = world_pos - positionWorld;
    screenpos *= zoom;
    screenpos.rotate(-angle);
    screenpos += positionScreen;
    return screenpos;
}
