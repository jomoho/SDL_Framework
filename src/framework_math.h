//
// Created by moritz on 21.11.2015.
//

#ifndef SDL_FRAMEWORK_MATH_H
#define SDL_FRAMEWORK_MATH_H


#include "framework.h"
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define RAD_TO_DEG 57.2958f
#define PI 3.14159265359f
#define HALFPI 1.57079632679f
#define TWOPI 6.28318530718f

inline float32 lerp(float32 a, float32 t, float32 b){
    float32 result = (1.0f - t) * a + t * b;
    return result;
}

struct vec2{
    union {
        struct {
            float32 x;
            float32 y;
        };
        float32 v[2];
    };

    vec2(float32 x, float32 y) :
            x(x), y(y)
    {};
    vec2() :
            x(0), y(0)
    {};

    void direction(float32 angle){
        x = cosf(angle);
        y = sinf(angle);
    };
    inline float32 dot(vec2 other){
        return (x * other.y) - (y * other.x);
    };
    float32 angle(){
        return atan2f(y,x);
    };
    float32 lengthSqr(){
        return x*x + y*y;
    };
    float32 length(){
        return sqrtf( x*x + y*y);
    };
    void rotate(float32 angle){
        float32 cs = cosf(angle);
        float32 sn = sinf(angle);

        float32 tx = x, ty = y;

        x = tx * cs - ty * sn;
        y = tx * sn + ty * cs;
    }
 };


inline vec2 lerp2d(vec2 a, float32 t, vec2 b){
    vec2 result2d ((1.0f - t) * a.x + t * b.x, (1.0f - t) * a.y + t * b.y);
    return result2d;
}

inline vec2 operator+(vec2 a, vec2 b){
    vec2 result ={a.x + b.x, a.y + b.y};
    return result;
}

inline vec2 operator*(vec2 a,float32 b){
    vec2 result = {a.x * b, a.y * b};
    return result;
}

inline vec2 operator-(vec2 a, vec2 b){
    vec2 result ={a.x - b.x, a.y - b.y};
    return result;
}

inline vec2 operator+=(vec2& a, vec2 b){
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline vec2 operator-=(vec2& a, vec2 b){
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

inline vec2 operator*=(vec2& a, float32 s){
    a.x *= s;
    a.y *= s;
    return a;
}

inline vec2 operator/=(vec2& a, float32 s){
    a.x /= s;
    a.y /= s;
    return a;
}



#endif //SDL_FRAMEWORK_MATH_H
