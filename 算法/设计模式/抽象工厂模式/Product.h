#ifndef __PRODUCT__
#define __PRODUCT__
#include <iostream>
using namespace std;
class Shape{
    public: virtual void draw()=0;
};

class Color{
    public: virtual void fill()=0;
};

class Rectangle: public Shape{
    void draw(){
        cout << "Rectangle draw()"<<endl;
    }
};

class Red:public Color{
    void fill(){
        cout<<"Red fill"<<endl;
    }
};

class Square: public Shape{
    void draw(){
        cout << "Square draw()"<<endl;
    }
};

class Green:public Color{
    void fill(){
        cout<<"Green fill"<<endl;
    }
};


#endif