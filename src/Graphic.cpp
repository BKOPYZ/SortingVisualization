#include "Graphic.h"

namespace wd{
    Graphic* Graphic::m_Instance = nullptr;
    bool Graphic::m_Initailized = true;
    Graphic *Graphic::getInstance()
    {
        if(m_Instance == nullptr){
            m_Instance = new Graphic();
        }
        return m_Instance;
    }


    Graphic::~Graphic()
    {
        SDL_DestroyRenderer(m_Renderer);
        m_Renderer = nullptr;
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
    }


    bool Graphic::Init(const std::string &title, const int &width, const int &height,const Uint32& flag)
    {
        m_ScreenWidth = width;
        m_ScreenHeight = height;
        //Initialize SDL Video and Audio and handling initialization errors
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

			printf("[ERROR]: SDL Initialization Error: %s\n", SDL_GetError());
			return false;
		}

		//Creating the window
		m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

		//Handling with window creation errors
		if(m_Window == NULL) {

			printf("[ERROR]: Window Creation Error: %s\n", SDL_GetError());
			return false;
		}

		//Creating the renderer
		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

		//Handling with the renderer creation errors
		if(m_Renderer == NULL) {

			printf("[ERROR]: Renderer Creation Error: %s\n", SDL_GetError());
			return false;
		}

		//Setting the renderer's clear color to white

        return true;
    }


    void Graphic::Release()
    {
        delete m_Instance;
        m_Instance = nullptr;

        m_Initailized = false;
    }
    SDL_Texture *Graphic::LoadTexture(const std::string &path)
    {
        SDL_Surface* tempSurface = IMG_Load(path.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer,tempSurface);
        SDL_FreeSurface(tempSurface);
        return texture;
    }
    void Graphic::DrawTexture(SDL_Texture *texture, SDL_Rect *clipRect, SDL_Rect *destRect, const float &angle, SDL_RendererFlip flip)
    {
        SDL_RenderCopyEx(m_Renderer,texture,clipRect,destRect,angle,NULL,flip);
    }
    void Graphic::FillRect(SDL_Rect *Rect)
    {
        SDL_RenderFillRect(m_Renderer,Rect);
    }
    void Graphic::SetColor(const Uint8 &r, const Uint8 &g, const Uint8 &b, const Uint8 &a)
    {
        SDL_SetRenderDrawColor(m_Renderer,r,g,b,a);
    }
    void Graphic::ClearBackBuffer()
    {
        SetColor(0,0,0,255);
        SDL_RenderClear(m_Renderer);
    }
    void Graphic::OnRender()
    {  
        SDL_RenderPresent(m_Renderer);
    }
}