#include "Component.h"
int main(int argc, char const *argv[])
{
    Component *component = new Phone();
    component->operation();
    printf("--------\n");
    Decorator *shell = new DecoratorShell(component);
    Decorator *sticker= new DecoratorSticker(shell);
    sticker->operation();
    return 0;
}
