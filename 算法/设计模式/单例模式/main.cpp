#include "Singleton.h"

int main(int argc, char const *argv[])
{
    Singleton *obj = Singleton::getInstance();
    obj = Singleton::getInstance();
    
    return 0;
}
