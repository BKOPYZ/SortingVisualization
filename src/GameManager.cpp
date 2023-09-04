#include "GameManager.h"
#include <iostream>
#include "Sorting.h"
namespace wd{
    SDL_Texture* lion;
    GameManager* GameManager::m_Instance = nullptr;

    GameManager *GameManager::GetInstance()
    {
        if(m_Instance == nullptr){
            m_Instance = new GameManager();
        }
        return m_Instance;
    }
    GameManager::~GameManager()
    {
        Graphic::Release();
		m_Graphic = NULL;

    }
    void GameManager::Release()
    {
        delete m_Instance;
        m_Instance = nullptr;
        delete m_SelectionSort;
        m_SelectionSort = nullptr;
 
    }
    void GameManager::Run()
    {
        
        while(m_IsRunning){
            OnHandleEvent();
            OnEarlyUpdate();
            OnUpdate();
            OnRender();
            OnLateUpdate();
            
        }
    }
    GameManager::GameManager()
    {
        m_IsRunning = true;
        m_Graphic = Graphic::getInstance();
        m_Graphic->Init("Game Title",1000,600,0);
        m_SelectionSort = new SelectionSort(200,1000,600);
        
    }
    void GameManager::OnEarlyUpdate()
    {
    }
    void GameManager::OnUpdate()
    {
        m_SelectionSort->OnUpdate();
    }
    void GameManager::OnLateUpdate()
    {
    }
    void GameManager::OnHandleEvent()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                m_IsRunning = false;
                break;
            default:
                break;  
        }
    }
    void GameManager::OnRender()
    {
        m_Graphic->ClearBackBuffer();
        // add things to render here
        m_SelectionSort->OnRender();


        m_Graphic->OnRender();
        
    }
}