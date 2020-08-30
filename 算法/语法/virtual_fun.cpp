#include <iostream>
using std::cout;
using std::endl;
/*
编译器发现一个类中有虚函数，便会立即为此类生成虚函数表 vtable。
虚函数表的各表项为指向对应虚函数的指针。
编译器还会在此类中隐含插入一个指针 vptr（对 vc 编译器来说，它插在类的第一个位置上）指向虚函数表。
调用此类的构造函数时，在类的构造函数中，编译器会隐含执行 vptr 与 vtable 的关联代码，
将 vptr 指向对应的 vtable，将类与此类的 vtable 联系了起来。
*/
class A
{
public:
    // virtual 提示子类可能会被重写。
    // 调用的函数是虚函数，则表示动态绑定。
    // 动态绑定，虚函数由对象的实际类型进行判断运行。
    virtual void func1(); // 虚函数
    void func2();
};

class B : A
{
public:
    void func1() { cout << "func1 in class B" << endl; }        //虚函数，virtual省略，重写
    virtual void func2() { cout << "fun2 in class B" << endl; } //无论加不加virtual，两个是不同的函数
};
class Base
{

private:
    virtual void f() { cout << "Base::f" << endl; }
};
typedef void (*Fun)(void);
int main(int argc, char const *argv[])
{
    Base b;
    Fun pFun = NULL;
    cout << "虚函数表地址：" << (int *)(&b) << endl;
    cout << "虚函数表函数地址：" << (int*)*(int *)(&b) << endl;
    pFun = (Fun)(*(int*)*(int *)(&b));// 错
    pFun();
    return 0;
}
