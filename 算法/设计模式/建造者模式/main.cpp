#include <iostream>
#include "Director.h"
#include "Builder.h"
#include "House.h"
using namespace std;
int main(int argc, char const *argv[])
{   
    Director director;
    AbstractBuilder* builder = new ConcreteBuilderA();
    director.setBuilder(builder);
    House* house = director.construct();
    house->print();
    return 0;
}
