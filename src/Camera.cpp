//
// Created by moritz on 22.08.15.
//

#include "Camera.h"
#include "Text.h"
#include "Game.h"

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
    vec2 screenpos = world_pos -positionWorld;
    screenpos.rotate(-angle);
    screenpos *= zoom;
    screenpos += positionScreen;
    return screenpos;
}

void Camera::drawDebug(){
    stringstream s;

    s << "positionWorld: " << positionWorld.x <<", "<<positionWorld.y
    <<"  positionScreen: " << positionScreen.x <<", "<<positionScreen.y
    <<"  zoom: " << zoom <<"  angle: "<<angle;
    Text txt(s.str(), Game::red);
    txt.drawLeft(16, 32, 1.0);
}
