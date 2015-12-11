//
// Created by moritz on 11.12.15.
//

#ifndef SDL_FRAMEWORK_INTERSECTION_TESTS_H
#define SDL_FRAMEWORK_INTERSECTION_TESTS_H

#include "PlatformSDL.h"
#include "framework_math.h"

bool intersect_box_point(Rect * r, vec2 *point){
    float32 r_bottom = r->y + r->h;
    float32 r_right = r->x + r->w;

    return !(   point->x > r_right
                || point->x < r->x
                || point->y > r_bottom
                || point->y < r->y);
}

bool intersect_box_box(Rect * r1, Rect * r2){
    auto r1_bottom = r1->y + r1->h;
    auto r2_bottom = r2->y + r2->h;

    auto r1_right = r1->x + r1->w;
    auto r2_right = r2->x + r2->w;
    return !(   r2->x > r1_right
             || r2_right < r1->x
             || r2->y > r1_bottom
             || r2_bottom < r1->y);
}

bool intersect_circle_point(vec2 *center, float32 radius, vec2 *point){
    vec2 d = (*center)-(*point);
    return d.lengthSqr() < (radius*radius);
}


bool intersect_circle_circle(vec2 *center1, float32 radius1, vec2 *center2, float32 radius2){
    vec2 d = (*center1)-(*center2);
    float32 rr = (radius1+radius2);
    rr *= rr;
    return d.lengthSqr() < rr;
}

bool intersect_ray_ray(vec2 *s1, vec2 *d1, vec2 * s2, vec2 *d2, vec2 * intersection = NULL  ){
    float32 dot = d1->dot(*d2);
    if(dot == 0){
        return false;
    }

    vec2 c = *s2 - *s1;
    float32 t = c.dot(*d1)/dot;
    if(t >1 || t <0){
        return false;
    }

    float32 u = c.dot(*d2)/dot;
    if(u >1 || u <0){
        return false;
    }

    if(intersection != NULL){
        (*intersection) = (*s1) + ((*d1)*t);
    }
    return true;
}


#endif //SDL_FRAMEWORK_INTERSECTION_TESTS_H
