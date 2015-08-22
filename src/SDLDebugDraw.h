//
// Created by moritz on 22.08.15.
//

#ifndef SDL_FRAMEWORK_SDLDEBUGDRAW_H
#define SDL_FRAMEWORK_SDLDEBUGDRAW_H

#include <Box2D/Box2D.h>

class SDLDebugDraw : public b2Draw {
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
    void DrawTransform(const b2Transform& xf);
};


#endif //SDL_FRAMEWORK_SDLDEBUGDRAW_H
