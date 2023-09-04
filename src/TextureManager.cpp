#include "TextureManager.h"
#include <iostream>
namespace wd{
    SDL_Texture *TextureManager::CreateTextureFromSurface(SDL_Renderer *renderer, const std::string& imagePath)
    {
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);
        return texture;
    }



}