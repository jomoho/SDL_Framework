//
// Created by moritz on 22.11.2015.
//

#ifndef SDL_FRAMEWORK_ASSETLOADER_H
#define SDL_FRAMEWORK_ASSETLOADER_H


#include <SDL_mixer.h>
#include "PlatformSDL.h"
#include<vector>

struct FontDef{
    string filename;
    int size;
};


struct Assets {
    vector<string> sfxFiles = {
            "sfx/Synth.wav"
    };
    vector<string> musicFiles = {
            "sfx/Drums.wav"
    };
    vector<FontDef> fontDefinitions = {
            {"fonts/DroidSansMono.ttf", 12},
            {"fonts/DroidSansMono.ttf", 16},
            {"fonts/MostlyMono.ttf", 14}
    };

    vector<string> textureDefinitions = {
            "gfx/demo.png",
            "gfx/1.png"
    };

    vector<Mix_Chunk*> sfx;
    vector<Mix_Music*> music;
    vector<TTF_Font *> fonts;
    vector<Texture *> textures;

    int32 getTextureId(string fn);

    Texture * loadTexture(const string &filename);

    void loadFonts();
    void freeFonts();

    void loadTextures();
    void freeTextures();


    void loadFilesAudio();
    void destroyAudio();

    void loadInit();
    void freeAll();
};


#endif //SDL_FRAMEWORK_ASSETLOADER_H
