#include <iostream>
#include "Factory.h"
#include "Product.h"
using namespace std;

int main(int argc, char const *argv[])
{
    AbstractFactory * factory = nullptr;
    AbstractProduct * ball = nullptr;

    factory = new BasketballFactory();
    ball = factory->getProduct();
    ball->play();

    factory = new VolleyballFactory();
    ball = factory->getProduct();
    ball->play();
    
    factory = new FootballFactory();
    ball = factory->getProduct();
    ball->play();
    return 0;
}
