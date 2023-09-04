#pragma once

namespace wd{
    
    class State{

        public:
            State();
            virtual ~State(){}

            virtual void OnHandleEvent(){}
            virtual void OnRender(){}
            virtual void OnUpdate(){}
            
        private:


    };
}