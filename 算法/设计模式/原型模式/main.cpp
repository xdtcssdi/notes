#include <iostream>
#include "proto.h"
#include "Implement.h"
using namespace std;
/*
优点：

当创建新的对象实例较为复杂时，原型模式可以简化创建过程，提高创建对象的效率；
可扩展：模式中提供了抽象原型类，具体原型类可适当扩展；
创建结构简单：创建工厂即为原型对象本身
缺点：

深克隆代码较为复杂；
每一个类都得配备一个clone方法，且该方法位于类的内部，修改时违背开闭原则；
*/
int main(int argc, char const *argv[])
{
    Concrete* type = new Concrete();
    type->setId(1611);
    type->setName("xd");
    type->setWork("math1");
    type->print();
    //浅拷贝
    // Concrete* type2 = type;
    // type2->setId(10000);
    // type2->setName("dx");
    // type2->print();
    // type->print();
    //深拷贝
    Concrete* type3 = type->clone();
    type3->setId(1010);
    type3->setName("Dx");
    type3->print();
    type->print();
    return 0;
}