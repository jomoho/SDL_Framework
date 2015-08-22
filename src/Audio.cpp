//
// Created by moritz on 22.08.2015.
//

#include "Audio.h"
#include "Log.h"

void Audio::init() {
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        FILE_LOG(logWARNING) << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError();
    }
}

void Audio::destroy() {
    for(auto it = sfx.begin(); it != sfx.end(); ++it){
        Mix_FreeChunk(*it);
    }
    sfx.clear();
    for(auto it = music.begin(); it != music.end(); ++it){
        Mix_FreeMusic(*it);
    }
    music.clear();
    while(Mix_Init(0))
        Mix_Quit();
}

void Audio::loadFiles(){
    for(auto it = sfxFiles.begin(); it != sfxFiles.end(); ++it){
        Mix_Chunk *s = Mix_LoadWAV( it->c_str() );
        if( s == NULL ) {
            FILE_LOG(logWARNING) <<"Failed to load sound: "<<*it<< " SDL_mixer Error: "<< Mix_GetError();
        }
        sfx.push_back(s);
    }
    for(auto it = musicFiles.begin(); it != musicFiles.end(); ++it){
        Mix_Music *m = Mix_LoadMUS( it->c_str() );
        if( m == NULL ) {
            FILE_LOG(logWARNING) <<"Failed to load music: "<<*it<< " SDL_mixer Error: "<< Mix_GetError();
        }
        music.push_back(m);
    }
}

void Audio::play(int sound, int loops) {
    Mix_PlayChannel( -1, sfx[sound], loops );
}

void Audio::playFadeIn(int sound, int loops, float seconds) {
    Mix_FadeInChannel( -1, sfx[sound], loops, (int)( seconds*1000.f) );
}

void Audio::setVolume(float vol) {
    Mix_Volume(-1, (int) (vol* 128.f));
}

void Audio::playMusic(int sound, int loops, float seconds) {
    Mix_FadeInMusic(music[sound], loops, (int)( seconds*1000.f));
}

void Audio::pauseMusic() {
    Mix_PauseMusic();
}

void Audio::resumeMusic() {
    Mix_ResumeMusic();
}

void Audio::stopFadeOutMusic(float seconds) {
    Mix_FadeOutMusic( (int)( seconds*1000.f));
}

void Audio::setVolumeMusic(float vol) {
    Mix_VolumeMusic((int) (vol* 128.f));
}
