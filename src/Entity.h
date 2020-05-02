//
// Created by moritz on 21.11.2015.
//

#ifndef SDL_FRAMEWORK_ENTITY_H
#define SDL_FRAMEWORK_ENTITY_H


#include <vector>
#include "framework_math.h"
#include "Frame.h"
#include "Game.h"

enum EntityType{
    ENTITY_TYPE_PLAYER = 1,
    ENTITY_TYPE_GUN = 2
};
struct Entity {
    EntityType type;
    uint32 flags;
    vec2 pos;
    Frame * sprite;

    static Entity* make(EntityType which, void * where){
        Entity* entity = (Entity*) where;
        switch(which){
            case ENTITY_TYPE_PLAYER:{
                entity->type = which;
                entity->flags = 0x0000000000000000;
                entity->pos= vec2(0,0);
                //TODO: How To acquire sprites and such. do Sprites contain animations?
                //entity->sprite = App::get()->
            }break;
            case ENTITY_TYPE_GUN:{
                entity->type = which;
                entity->flags = 0x0000000000000000;
                entity->pos= vec2(0,0);
            }break;
            default:{
                return NULL;
            }
        }

        return (Entity*) where;
    }
};
typedef std::vector<Entity> vecEntity;


#endif //SDL_FRAMEWORK_ENTITY_H
