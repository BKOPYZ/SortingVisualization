#pragma once
#include "Graphic.h"
#include "Sorting.h"
namespace wd{

    class GameManager{
        public:
            static GameManager* GetInstance();
            ~GameManager();
            void Release();
            void Run();
            

        private:
            static GameManager* m_Instance;
            bool m_IsRunning;
            Graphic* m_Graphic;
            SelectionSort* m_SelectionSort;


            GameManager();
            void OnEarlyUpdate();
            void OnUpdate();
            void OnLateUpdate();
            void OnHandleEvent();
            void OnRender();
            

    };
}