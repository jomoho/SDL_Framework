//
// Created by moritz on 22.08.15.
//

#include <SDL2_gfxPrimitives.h>
#include "SDLDebugDraw.h"
#include "App.h"

void SDLDebugDraw::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
    Sint16 x[vertexCount];
    Sint16 y[vertexCount];
    for(int i = 0; i < vertexCount; ++i){
        b2Vec2 v = vertices[i]; //((vertices[i] + camera.wpos)*camera.getScale()) ;
        v *= camera;
        
        x[i] = (Sint16) v.x;
        y[i] = (Sint16) v.y;
    }

    polygonRGBA (App::get()->ren->renderer, x, y, vertexCount, color.r, color.g, color.b, color.a);

    polygonRGBA (App::get()->ren->renderer, x, y, vertexCount, 255,255,255,255);
}

void SDLDebugDraw::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
    Sint16 x[vertexCount];
    Sint16 y[vertexCount];
    for(int i = 0; i < vertexCount; ++i){
        b2Vec2 v = vertices[i]; //((vertices[i] + camera.wpos)*camera.getScale()) ;
        v *= camera;
        
        x[i] = (Sint16) v.x;
        y[i] = (Sint16) v.y;
    }

    filledPolygonRGBA (App::get()->ren->renderer, x, y, vertexCount, color.r, color.g, color.b, color.a);


    polygonRGBA (App::get()->ren->renderer, x, y, vertexCount, 255,255,255,255);
}

void SDLDebugDraw::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color) {
    Sint16 x;
    Sint16 y;

    b2Vec2 v = center; //((vertices[i] + camera.wpos)*camera.getScale()) ;
    v*= camera;
    
    x = (Sint16) v.x;
    y = (Sint16) v.y;

    ellipseRGBA(App::get()->ren->renderer,x, y, radius*30, radius*30, color.r, color.g, color.b, color.a);
}

void SDLDebugDraw::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color) {
    Sint16 x;
    Sint16 y;

    b2Vec2 v = center; //((vertices[i] + camera.wpos)*camera.getScale()) ;
    v*= camera;
    
    x = (Sint16) v.x;
    y = (Sint16) v.y;

    filledEllipseRGBA(App::get()->ren->renderer,x, y, radius*30, radius*30, color.r, color.g, color.b, color.a);
}

void SDLDebugDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) {
    b2Vec2 v1 = p1, v2 = p2;
    v1*= camera;
    v2*= camera;

    lineRGBA(App::get()->ren->renderer,v1.x, v1.y, v2.x,v2.y, color.r, color.g, color.b, color.a);
}

void SDLDebugDraw::DrawTransform(const b2Transform &xf) {
    b2Vec2 v1 = xf.p;
    v1*= camera;
    
    pixelRGBA(App::get()->ren->renderer,v1.x, v1.y, 255,255,255,255);
}

