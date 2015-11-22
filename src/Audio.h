//
// Created by moritz on 22.08.2015.
//

#ifndef SDL_FRAMEWORK_AUDIO_H
#define SDL_FRAMEWORK_AUDIO_H

#include <SDL2/SDL_mixer.h>
#include <vector>
#include <string>
#include "framework.h"

using namespace std;

struct Audio {

    void init();
    void destroy();

    void loadFiles();
    void play(uint32 sound, uint32 loops = 0);
    void playFadeIn(uint32 sound, uint32 loops = 0, float32 seconds= 1.0f);
    void setVolume(float32 vol); // zero to one
    void playMusic(uint32 sound, uint32 loops = -1, float32 seconds= 1.0f);
    void pauseMusic();
    void resumeMusic();
    void stopFadeOutMusic(float32 seconds= 1.0f);
    void setVolumeMusic(float32 vol); // zero to one
};


#endif //SDL_FRAMEWORK_AUDIO_H
