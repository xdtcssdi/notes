#include <iostream>
#include "Factory.h"
#include "Product.h"
using namespace std;

int main(int argc, char const *argv[])
{
    AbstractFactory* factory = new RedSquareFactory();
    Color* color = factory->getColor();
    color->fill();
    Shape* shape = factory->getShape();
    shape->draw();
    return 0;
}
