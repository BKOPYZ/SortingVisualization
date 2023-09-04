#pragma once
#include "Graphic.h"
#include <vector>
#include <memory>
class Sorting{

    public:
        Sorting(){};
        ~Sorting(){};
        //sort and render
        virtual void OnUpdate(){};
        virtual void OnRender(){};  
    protected: 
        int i,j,k,temp,lowest,size,screenWidth,screenHeight, pixelPerCol,pixelPerRow;
        std::vector<SDL_Rect *> Rects;
        std::vector<int> OrderArray;
        wd::Graphic* m_Graphic;
    
};

class SelectionSort: public Sorting{

    public:
        SelectionSort(const unsigned int& amount,const unsigned int& width, const unsigned int& height);
        ~SelectionSort(){};
        void Loop();
        void NestLoop();
        void OnUpdate() override;
        void OnRender() override;  
    
};