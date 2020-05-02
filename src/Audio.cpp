//
// Created by moritz on 22.08.2015.
//

#include "Audio.h"
#include "Log.h"
#include "Game.h"

void Audio::init() {
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        FILE_LOG(logWARNING) << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError();
    }
}



void Audio::play(uint32 sound, uint32 loops) {
    Mix_PlayChannel( -1, Game::getAssets()->sfx[sound], loops );
}

void Audio::playFadeIn(uint32 sound, uint32 loops, float32 seconds) {
    Mix_FadeInChannel( -1, Game::getAssets()->sfx[sound], loops, (int)( seconds*1000.f) );
}

void Audio::setVolume(float32 vol) {
    Mix_Volume(-1, (int) (vol* 128.f));
}

void Audio::playMusic(uint32 sound, uint32 loops, float32 seconds) {
    Mix_FadeInMusic(Game::getAssets()->music[sound], loops, (int)( seconds*1000.f));
}

void Audio::pauseMusic() {
    Mix_PauseMusic();
}

void Audio::resumeMusic() {
    Mix_ResumeMusic();
}

void Audio::stopFadeOutMusic(float32 seconds) {
    Mix_FadeOutMusic( (int)( seconds*1000.f));
}

void Audio::setVolumeMusic(float32 vol) {
    Mix_VolumeMusic((int) (vol* 128.f));
}
