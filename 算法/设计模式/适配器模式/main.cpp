#include "Adapter.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    PowerTarget *target = new Adapter();
    std::cout << target->out5v();
    return 0;
}
