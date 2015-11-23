//
// Created by moritz on 22.11.2015.
//

#ifndef SDL_FRAMEWORK_ASSETLOADER_H
#define SDL_FRAMEWORK_ASSETLOADER_H


#include <SDL_mixer.h>
#include "PlatformSDL.h"
#include "Sprite.h"
#include<vector>

struct FontDef{
    string filename;
    int size;
};

#define ASSET_FONT_DIR "fonts"
#define ASSET_SOUND_DIR "sfx"
#define ASSET_GFX_DIR "gfx/"

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
            "gfx/1.png",
            "gfx/32.png",
            "gfx/pack.png"
    };

    vector<string> atlasDefinitions = {
            "gfx/pack.json"
    };

    vector<Mix_Chunk*> sfx;
    vector<Mix_Music*> music;
    vector<TTF_Font *> fonts;
    vector<Texture *> textures;
    vector<SpriteAtlas> atlases;

    int32 getTextureId(string fn);

    Texture * loadTexture(const string &filename);

    void loadFonts();
    void freeFonts();

    void loadTextures();
    void freeTextures();

    void loadFilesAudio();
    void destroyAudio();

    void loadAtlases();

    void loadInit();
    void freeAll();
};


#endif //SDL_FRAMEWORK_ASSETLOADER_H
