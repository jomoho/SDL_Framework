//
// Created by moritz on 22.11.2015.
//

#include "Assets.h"
#include "Game.h"

Texture *Assets::loadTexture(const string &filename) {
    SDL_Surface *srf;
    srf = IMG_Load_RW(SDL_RWFromFile(filename.c_str(), "rb"), 1);
    if (!srf) {
        FILE_LOG(logERROR) << "loadTexture Error: " << IMG_GetError();
    } else {
        FILE_LOG(logDEBUG3) << "Texture loaded: " << filename;
    }
    Texture * tex;
    tex = SDL_CreateTextureFromSurface(Game::getSDLRenderer(), srf);

    SDL_FreeSurface(srf);
    return tex;
}

void Assets::loadInit(){

    loadFonts();
    FILE_LOG(logDEBUG) << "Fonts Loaded!";
    loadTextures();
    FILE_LOG(logDEBUG) << "Textures Loaded!";
    loadFilesAudio();
    FILE_LOG(logDEBUG) << "Audio Loaded!";
}

void Assets::destroyAudio() {
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

void Assets::loadFilesAudio(){
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



void Assets::loadFonts() {
    TTF_Init();
    TTF_Font *font;

    for(auto it = fontDefinitions.begin(); it != fontDefinitions.end(); ++it){
        font = TTF_OpenFont(it->filename.c_str(), it->size);
        if(font == NULL){
            FILE_LOG(logERROR)  << "TTF_OpenFont Error: " << TTF_GetError();
        }else{
            FILE_LOG(logDEBUG)  << "Font Loaded: " << it->filename.c_str();
            fonts.push_back(font);
        }
    }
}

void Assets::freeFonts() {
    for (vector<TTF_Font*>::size_type i = 0; i < fonts.size(); ++i) {
        TTF_CloseFont(fonts[i]);
    }
    fonts.empty();
    TTF_Quit();
}



void Assets::loadTextures() {
    // load support for PNG images
    int flags = IMG_INIT_PNG;
    int inited = IMG_Init(flags);

    if ((inited & flags) != flags) {
        FILE_LOG(logWARNING) << "Error initializing SDL_image" << IMG_GetError();
    }

    for(auto it = textureDefinitions.begin(); it != textureDefinitions.end(); ++it){
        textures.push_back(Assets::loadTexture(*it));
    }

    IMG_Quit();
}

void Assets::freeTextures() {
    for (vector<Texture*>::size_type i = 0; i < textures.size(); ++i) {
        SDL_DestroyTexture(textures[i]);
    }
    textures.empty();
}

void Assets::freeAll() {
    freeTextures();
    freeFonts();
    destroyAudio();
}

int32 Assets::getTextureId(string fn) {
    for(int32 i =0; i < textureDefinitions.size(); i++){
        if (textureDefinitions[i] == fn){
            return i;
        }
    }
    return -1;
}
