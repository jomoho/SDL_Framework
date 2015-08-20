cmake_minimum_required(VERSION 3.3)
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
    src/Sprite.h)

add_executable(SDL_Framework ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
find_package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}  ${SDL2TTF_INCLUDE_DIRS}  ${OPENGL_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(  ${PROJECT_NAME}  ${SDL2_LIBRARIES}  ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES}  ${OPENGL_LIBRARIES})