#include "Product.h"
int main(int argc, char const *argv[])
{
    Game* gamea = new GameA();
    Game* gameb = new GameB();
    Phone* phone1 = new PhoneA();
    phone1->setSetup(gamea);
    phone1->play();
    phone1->setSetup(gameb);
    phone1->play();
    
    return 0;
}
