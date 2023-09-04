#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>

namespace wd{
    
    class TextureManager{

        public:
            static SDL_Texture* CreateTexture(){return nullptr;}
            static SDL_Texture* CreateTextureFromSurface(SDL_Renderer* renderer,const std::string& imagePath);


        private:




    };


};