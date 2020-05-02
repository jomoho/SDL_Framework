//
// Created by moritz on 20.08.15.
//

#include "Scene.h"
#include <Box2D/Box2D.h>

Scene::Scene(){
    b2Vec2 gravity(0.0f, -10.0f);
//    world = new b2World(gravity);
//    world->SetDebugDraw(&debugDraw);
//    debugDraw.SetFlags( b2Draw::e_shapeBit |b2Draw::e_jointBit);
}

Scene::~Scene() {
  //  delete world;
}

void Scene::update(float dt) {
//    world->Step(dt, 6, 2);
}
