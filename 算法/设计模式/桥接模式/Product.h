#ifndef __PRODUCT__
#define __PRODUCT__
#include<iostream>
class Game{
    public: virtual void play()=0;
};
class GameA:public Game{
    void play(){
        std::cout<<"Play GameA"<<std::endl;
    }
};
class GameB:public Game{
    void play(){
        std::cout<<"Play GameB"<<std::endl;
    }
};
class Phone{
    public:
        virtual void setSetup(Game*)=0;
        virtual void play()=0;
};
class PhoneA:public Phone{
    Game* game;
    void setSetup(Game* game){
        this->game = game;
    }
    void play(){
        game->play();
    }
};
#endif