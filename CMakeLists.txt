cmake_minimum_required(VERSION 2.8)
project(SDL_Framework)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

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
        src/Audio.h src/SDLDebugDraw.cpp src/SDLDebugDraw.h

        src/sdl2_gfx/SDL2_framerate.c
        src/sdl2_gfx/SDL2_framerate.h
        src/sdl2_gfx/SDL2_gfxPrimitives.c
        src/sdl2_gfx/SDL2_gfxPrimitives.h
        src/sdl2_gfx/SDL2_gfxPrimitives_font.h
        src/sdl2_gfx/SDL2_imageFilter.c
        src/sdl2_gfx/SDL2_imageFilter.h
        src/sdl2_gfx/SDL2_rotozoom.c
        src/sdl2_gfx/SDL2_rotozoom.h
)

add_executable(SDL_Framework ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
find_package(SDL2_gfx REQUIRED)
find_package(Box2D REQUIRED)
find_package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}  ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${BOX2D_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(  ${PROJECT_NAME}  ${SDL2_LIBRARIES}  ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${BOX2D_LIBRARIES} ${OPENGL_LIBRARIES})