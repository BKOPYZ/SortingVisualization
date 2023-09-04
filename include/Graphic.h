#pragma once
#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
namespace wd{
    class Graphic{
        public:
            static Graphic* getInstance();
            ~Graphic();
            static void Release();

            bool Init(const std::string& title, const int& width, const int& height,const Uint32& flag);
            
            SDL_Texture* LoadTexture(const std::string& path);
            void DrawTexture(SDL_Texture* texture,SDL_Rect* clipRect = NULL, SDL_Rect* destRect = NULL, const float& angle = 0.0f,SDL_RendererFlip flip = SDL_FLIP_NONE );
            void FillRect(SDL_Rect* Rect);
            void SetColor(const Uint8& r, const Uint8& g, const Uint8& b, const Uint8& a);
            void ClearBackBuffer();
            void OnRender();

        private:
            int m_ScreenWidth;
            int m_ScreenHeight;
            Uint32 m_Flag;
            static bool m_Initailized;

            SDL_Window* m_Window;
            SDL_Renderer* m_Renderer;
            
            static Graphic* m_Instance;

            Graphic(){}

    };
}