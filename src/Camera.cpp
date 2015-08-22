//
// Created by moritz on 22.08.15.
//

#include "Camera.h"
b2Vec2& operator*=(b2Vec2 &v, const Camera &cam){
    float vx = v.x, vy = v.y;
    v.x= cosf(cam.angle) * (vx) - sinf(cam.angle) * (vy);
    v.y= sinf(cam.angle) * (vx) + cosf(cam.angle) * (vy);

    v -=cam.pos;
    v.x*= cam.scale.x;
    v.y*= cam.scale.y;
    v.y = cam.screenHeight -v.y;
    v += b2Vec2(cam.screenWidth/2, -cam.screenHeight/2);
    return v;
};

Camera::Camera(float w, float h) {
    screenWidth =w;
    screenHeight=h;
    pos= b2Vec2(0,0);
    scale= b2Vec2(10,10);
}

Camera::Camera(Camera &cam) {
    screenHeight=cam.screenHeight;
    screenWidth=cam.screenWidth;
    pos= cam.pos;
    scale= cam.scale;
    angle=cam.angle;
}

Camera::Camera() {
    screenHeight=480;
    screenWidth=640;
    pos= b2Vec2(0,0);
    scale= b2Vec2(10,10);
    angle=0;
}
