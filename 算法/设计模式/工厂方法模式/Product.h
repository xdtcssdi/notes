#ifndef __PRODUCT__
#define __PRODUCT__

#include <iostream>
using namespace std;
class AbstractProduct{
    public:
        virtual void play()=0;
};

class Basketball:public AbstractProduct{
    void play(){
        cout << "Play Basketball"<<endl;
    }
};

class Football:public AbstractProduct{
    void play(){
        cout << "Play Footballball"<<endl;
    }
};

class Volleyball:public AbstractProduct{
    void play(){
        cout << "Play Volleyball"<<endl;
    }
};


#endif