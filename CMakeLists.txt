cmake_minimum_required(VERSION 2.8)
project(SDL_Framework)

add_definitions(${CMAKE_CXX_FLAGS} "-fpermissive")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

set(SOURCE_FILES
    src/main.cpp
    src/App.cpp
    src/App.h
    src/AppState.cpp
    src/AppState.h
    src/Log.h
    src/RendererSDL.cpp
    src/RendererSDL.h
    src/Text.cpp
    src/Text.h
    src/Sprite.cpp
    src/Sprite.h
    src/Scene.cpp
    src/Scene.h
    src/Audio.cpp
    src/Audio.h
    src/SDLDebugDraw.cpp
    src/SDLDebugDraw.h
    src/sdl2_gfx/SDL2_framerate.c
    src/sdl2_gfx/SDL2_framerate.h
    src/sdl2_gfx/SDL2_gfxPrimitives.c
    src/sdl2_gfx/SDL2_gfxPrimitives.h
    src/sdl2_gfx/SDL2_gfxPrimitives_font.h
    src/sdl2_gfx/SDL2_imageFilter.c
    src/sdl2_gfx/SDL2_imageFilter.h
    src/sdl2_gfx/SDL2_rotozoom.c
    src/sdl2_gfx/SDL2_rotozoom.h
    src/Camera.cpp src/Camera.h

        src/Box2D/Box2D.h
        src/Box2D/Collision/b2BroadPhase.cpp
        src/Box2D/Collision/b2BroadPhase.h
        src/Box2D/Collision/b2CollideCircle.cpp
        src/Box2D/Collision/b2CollideEdge.cpp
        src/Box2D/Collision/b2CollidePolygon.cpp
        src/Box2D/Collision/b2Collision.cpp
        src/Box2D/Collision/b2Collision.h
        src/Box2D/Collision/b2Distance.cpp
        src/Box2D/Collision/b2Distance.h
        src/Box2D/Collision/b2DynamicTree.cpp
        src/Box2D/Collision/b2DynamicTree.h
        src/Box2D/Collision/b2TimeOfImpact.cpp
        src/Box2D/Collision/b2TimeOfImpact.h
        src/Box2D/Collision/Shapes/b2ChainShape.cpp
        src/Box2D/Collision/Shapes/b2ChainShape.h
        src/Box2D/Collision/Shapes/b2CircleShape.cpp
        src/Box2D/Collision/Shapes/b2CircleShape.h
        src/Box2D/Collision/Shapes/b2EdgeShape.cpp
        src/Box2D/Collision/Shapes/b2EdgeShape.h
        src/Box2D/Collision/Shapes/b2PolygonShape.cpp
        src/Box2D/Collision/Shapes/b2PolygonShape.h
        src/Box2D/Collision/Shapes/b2Shape.h
        src/Box2D/Common/b2BlockAllocator.cpp
        src/Box2D/Common/b2BlockAllocator.h
        src/Box2D/Common/b2Draw.cpp
        src/Box2D/Common/b2Draw.h
        src/Box2D/Common/b2GrowableStack.h
        src/Box2D/Common/b2Math.cpp
        src/Box2D/Common/b2Math.h
        src/Box2D/Common/b2Settings.cpp
        src/Box2D/Common/b2Settings.h
        src/Box2D/Common/b2StackAllocator.cpp
        src/Box2D/Common/b2StackAllocator.h
        src/Box2D/Common/b2Timer.cpp
        src/Box2D/Common/b2Timer.h
        src/Box2D/Dynamics/b2Body.cpp
        src/Box2D/Dynamics/b2Body.h
        src/Box2D/Dynamics/b2ContactManager.cpp
        src/Box2D/Dynamics/b2ContactManager.h
        src/Box2D/Dynamics/b2Fixture.cpp
        src/Box2D/Dynamics/b2Fixture.h
        src/Box2D/Dynamics/b2Island.cpp
        src/Box2D/Dynamics/b2Island.h
        src/Box2D/Dynamics/b2TimeStep.h
        src/Box2D/Dynamics/b2World.cpp
        src/Box2D/Dynamics/b2World.h
        src/Box2D/Dynamics/b2WorldCallbacks.cpp
        src/Box2D/Dynamics/b2WorldCallbacks.h
        src/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp
        src/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h
        src/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
        src/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h
        src/Box2D/Dynamics/Contacts/b2CircleContact.cpp
        src/Box2D/Dynamics/Contacts/b2CircleContact.h
        src/Box2D/Dynamics/Contacts/b2Contact.cpp
        src/Box2D/Dynamics/Contacts/b2Contact.h
        src/Box2D/Dynamics/Contacts/b2ContactSolver.cpp
        src/Box2D/Dynamics/Contacts/b2ContactSolver.h
        src/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
        src/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h
        src/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
        src/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h
        src/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
        src/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h
        src/Box2D/Dynamics/Contacts/b2PolygonContact.cpp
        src/Box2D/Dynamics/Contacts/b2PolygonContact.h
        src/Box2D/Dynamics/Joints/b2DistanceJoint.cpp
        src/Box2D/Dynamics/Joints/b2DistanceJoint.h
        src/Box2D/Dynamics/Joints/b2FrictionJoint.cpp
        src/Box2D/Dynamics/Joints/b2FrictionJoint.h
        src/Box2D/Dynamics/Joints/b2GearJoint.cpp
        src/Box2D/Dynamics/Joints/b2GearJoint.h
        src/Box2D/Dynamics/Joints/b2Joint.cpp
        src/Box2D/Dynamics/Joints/b2Joint.h
        src/Box2D/Dynamics/Joints/b2MotorJoint.cpp
        src/Box2D/Dynamics/Joints/b2MotorJoint.h
        src/Box2D/Dynamics/Joints/b2MouseJoint.cpp
        src/Box2D/Dynamics/Joints/b2MouseJoint.h
        src/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp
        src/Box2D/Dynamics/Joints/b2PrismaticJoint.h
        src/Box2D/Dynamics/Joints/b2PulleyJoint.cpp
        src/Box2D/Dynamics/Joints/b2PulleyJoint.h
        src/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp
        src/Box2D/Dynamics/Joints/b2RevoluteJoint.h
        src/Box2D/Dynamics/Joints/b2RopeJoint.cpp
        src/Box2D/Dynamics/Joints/b2RopeJoint.h
        src/Box2D/Dynamics/Joints/b2WeldJoint.cpp
        src/Box2D/Dynamics/Joints/b2WeldJoint.h
        src/Box2D/Dynamics/Joints/b2WheelJoint.cpp
        src/Box2D/Dynamics/Joints/b2WheelJoint.h
        src/Box2D/Rope/b2Rope.cpp
        src/Box2D/Rope/b2Rope.h
)

add_executable(SDL_Framework ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
find_package(OpenGL REQUIRED)

set(BOX2D_INCLUDE_DIR "src" )

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}  ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${BOX2D_INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS} )
TARGET_LINK_LIBRARIES(${PROJECT_NAME}  ${SDL2_LIBRARIES}  ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${OPENGL_LIBRARIES})