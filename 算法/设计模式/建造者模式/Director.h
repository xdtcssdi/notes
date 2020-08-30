#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "Builder.h"
class Director{
    AbstractBuilder* builder;
    public:
        void setBuilder(AbstractBuilder *builder){
            this->builder = builder;
        }
        House* construct(){
            builder->buildFloor();
            builder->buildWall();
            builder->buildRoof();
            return builder->getHouse();
        }
};


#endif