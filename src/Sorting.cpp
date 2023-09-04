#include "Sorting.h"
#include <iostream>
#include <algorithm>

SelectionSort::SelectionSort(const unsigned int& amount,const unsigned int& width, const unsigned int& height)
{
    m_Graphic = wd::Graphic::getInstance();
    size = amount;
    i = 0;
    j = 1;
    screenWidth = width;
    screenHeight = height;
    pixelPerCol = width/amount;
    pixelPerRow = height/amount;
    for(int num = 1; num <= size; ++num ){
        OrderArray.push_back(num);
    }

    std::random_shuffle(OrderArray.begin(), OrderArray.end());

    for(int num =0 ; num < size; ++num){
        Rects.push_back(new SDL_Rect{(num * pixelPerCol + 2 ),(screenHeight - OrderArray[num] * pixelPerRow),(pixelPerCol - 2),(OrderArray[num] * pixelPerRow)});
    }
    m_Graphic->SetColor(255,255,255,255);
    lowest = OrderArray[0];
    
    
}


void SelectionSort::Loop()
{
    if(j == size){
        Rects[i]->y = screenHeight - lowest * pixelPerRow;
        Rects[i]->h = lowest * pixelPerRow;
        Rects[temp]->y = screenHeight - OrderArray[i] * pixelPerRow;
        Rects[temp]->h = OrderArray[i] * pixelPerRow;
        lowest = OrderArray[i];
        OrderArray[i++] = OrderArray[temp];
        OrderArray[temp] = lowest;
        j = i +1;
        lowest = OrderArray[i];
        temp = i;

    }
    NestLoop();

}

void SelectionSort::NestLoop()
{
    if(OrderArray[j] < lowest ){
        lowest = OrderArray[j];
        temp = j;
    }
    j++;
}

void SelectionSort::OnUpdate()
{
    if(i == (size-1)){
        return;
        }
    Loop();
    
}

void SelectionSort::OnRender()
{
    for(int inx = 0 ; inx < size; ++inx){
        
        if(inx == (j-1)){
            m_Graphic->SetColor(255,0,0,255);
            m_Graphic->FillRect(Rects[inx]);
            
        }
        else{
            m_Graphic->SetColor(255,255,255,255);
            m_Graphic->FillRect(Rects[inx]);
            
        }
    }
}
