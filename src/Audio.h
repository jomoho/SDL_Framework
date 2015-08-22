//
// Created by moritz on 22.08.2015.
//

#ifndef SDL_FRAMEWORK_AUDIO_H
#define SDL_FRAMEWORK_AUDIO_H

#include <SDL2/SDL_mixer.h>
#include <vector>
#include <string>

using namespace std;

class Audio {
    vector<Mix_Chunk*> sfx;
    vector<Mix_Music*> music;
    vector<string> sfxFiles = {"sfx/Synth.wav"};
    vector<string> musicFiles = {"sfx/Drums.wav"};

public:
    void init();
    void destroy();

    void loadFiles();
    void play(int sound, int loops = 0);
    void playFadeIn(int sound, int loops = 0, float seconds= 1.0f);
    void setVolume(float vol); // zero to one
    void playMusic(int sound, int loops = -1, float seconds= 1.0f);
    void pauseMusic();
    void resumeMusic();
    void stopFadeOutMusic(float seconds= 1.0f);
    void setVolumeMusic(float vol); // zero to one
};


#endif //SDL_FRAMEWORK_AUDIO_H
