cmake_minimum_required(VERSION 2.8)
project(SDL_Framework)

add_definitions(${CMAKE_CXX_FLAGS} "-fpermissive")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

set(SOURCE_FILES
        #Third party Header files
        src/picojson.h

        #main
        src/main.cpp

        #header files only
        src/framework.h
        src/framework_math.h
        src/Log.h

        # .cpp/.c files with corresponding .h files
        src/Game.cpp src/Game.h
        src/PlatformSDL.cpp src/PlatformSDL.h
        src/Text.cpp src/Text.h
        src/Frame.cpp src/Frame.h
        src/Audio.cpp src/Audio.h
        src/Camera.cpp src/Camera.h
        src/Entity.cpp src/Entity.h
        src/Map.cpp src/Map.h
        src/Assets.cpp src/Assets.h
        src/Input.cpp src/Input.h

        src/intersection_tests.h src/Sprite.cpp src/Sprite.h)

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