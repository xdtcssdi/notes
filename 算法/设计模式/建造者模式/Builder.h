#ifndef __BUILDER__
#define __BUILDER__
#include "House.h"
class AbstractBuilder{
    public:
        House* house;
        AbstractBuilder(){
            house = new House();
        }
        virtual void buildFloor()=0;
        virtual void buildWall()=0;
        virtual void buildRoof()=0;
        virtual House* getHouse()=0;
};

class ConcreteBuilderA: public AbstractBuilder{
    void buildFloor(){
        house->setFloor("Floor A");
    }
    void buildWall(){
        house->setWall("Wall A");
    }
    void buildRoof(){
        house->setRoof("Roof A");
    }
    House* getHouse(){
        return house;
    }
};
#endif