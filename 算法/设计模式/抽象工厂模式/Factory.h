#ifndef __FACTORY__
#define __FACTORY__
#include "Product.h"
#include <iostream>
using std::string;
class AbstractFactory{
    public:
        virtual Color* getColor()=0;
        virtual Shape* getShape()=0;
};

class RedSquareFactory: public AbstractFactory{
    Color* getColor(){
        return new Red();
    }
    Shape* getShape(){
        return new Square();
    }
};

class GreenRectangleFactory: public AbstractFactory{
    Color* getColor(){
        return new Green();
    }
    Shape* getShape(){
        return new Rectangle();
    }
};
#endif