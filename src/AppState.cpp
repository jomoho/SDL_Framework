/*
 * AppState.cpp
 *
 *  Created on: Aug 25, 2013
 *      Author: Moritz Laass
 */
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include "App.h"
#include "Sprite.h"
#include "Text.h"
#include "sdl2_gfx/SDL2_gfxPrimitives.h"

AppState::AppState(): timer(0){
    App::get()->audio.playMusic(0);
    s.debugDraw.camera = Camera(App::get()->ren->width, App::get()->ren->height);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = s.world->CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);


    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = s.world->CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);
}

AppState::~AppState() {
	// TODO Auto-generated destructor stub
}

void AppState::draw(){
    auto r = App::get()->ren;

	Sprite spr(0);
    spr.pivot ={150,250};
    spr.angle = r->time*6;
    spr.draw(r->width/2,r->height/2);

    Text t("Some Text!!!", {0, 150, 255});

    t.drawCenter(r->width / 2, r->height / 4, 2.0);


    s.update(r->deltaTime);
    s.world->DrawDebugData();

    SDL_SetRenderDrawColor(r->renderer, 255, 155, 0, 255);
}

void AppState::next(int branch){
	App::get()->nextState(branch);
}

void AppState::pump(const SDL_Event &event){
    if( event.type == SDL_KEYDOWN )
    {
        //Select surfaces based on key press
        switch( event.key.keysym.sym )
        {
            case SDLK_UP:
            App::get()->audio.play(0);
               break;
        }
    }
}

AppState *AppState::getNext(int branch) {
    return nullptr;
}
