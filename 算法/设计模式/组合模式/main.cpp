#include <iostream>
#include "Component.h"
int main(int argc, char const *argv[])
{
    Component *head = new SubComponent("总部");
    Component *sc = new SubComponent("四川分部");
    Component *my = new SubComponent("绵阳分部");
    Component *cd = new SubComponent("成都分部");
    Component *xz = new Leaf("行政办公室");
    Component *jw = new Leaf("教务办公室");
    head->add(xz);
    head->add(jw);
    head->add(sc);
    sc->add(xz);
    sc->add(jw);
    sc->add(my);
    sc->add(cd);
    my->add(xz);
    my->add(jw);
    cd->add(xz);
    cd->add(jw);
    head->operation();
    return 0;
}
