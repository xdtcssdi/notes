#include <iostream>
using namespace std; // 1、namespace 
class A{
    protected:
        int value;
};
class B:A{
    public:
        using A::value;//2、仅引用，不参与形参声明，也可以用来调用父类函数
};
using F = void (*)();//3、取别名，比typedef更容易识别
typedef void (*F)();

int main(int argc, char const *argv[])
{
    B a;
    cout<<a.value<<endl;
    return 0;
}
