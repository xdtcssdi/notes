#ifndef __FACTORY__
#define __FACTORY__

#include <iostream>
#include "Product.h"
using namespace std;

class AbstractFactory{
    public:
        virtual AbstractProduct* getProduct()=0;
};

class BasketballFactory:public AbstractFactory{
    AbstractProduct* getProduct(){
        return new Basketball();
    }
};

class FootballFactory:public AbstractFactory{
    AbstractProduct* getProduct(){
        return new Football();
    }
};

class VolleyballFactory:public AbstractFactory{
    AbstractProduct* getProduct(){
        return new Volleyball();
    }
};

#endif