//
// Created by moritz on 22.08.15.
//

#ifndef SDL_FRAMEWORK_CAMERA_H
#define SDL_FRAMEWORK_CAMERA_H


#include <Box2D/Common/b2Math.h>

class Camera {
public:
    Camera();
    Camera(float w, float h);
    Camera(Camera & cam);
    float screenWidth, screenHeight;
    b2Vec2 scale = b2Vec2(10,10);
    b2Vec2 pos= b2Vec2(0,0);
    float angle=0;
};

b2Vec2& operator*=(b2Vec2 &v, const Camera &cam);

#endif //SDL_FRAMEWORK_CAMERA_H
