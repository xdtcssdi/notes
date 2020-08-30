#include <iostream>
using namespace std;
/*
https://www.cnblogs.com/lizhenghn/p/3657717.html
至此总结一下静态绑定和动态绑定的区别：
1. 静态绑定发生在编译期，动态绑定发生在运行期；

2. 对象的动态类型可以更改，但是静态类型无法更改；

3. 要想实现动态，必须使用动态绑定；

4. 在继承体系中只有虚函数使用的是动态绑定，其他的全部是静态绑定；


*/

class A{
    public:
    void f(){
        cout << "A: f"<<endl;
    }
};

class B:public A{
    public:
    void f(){
        cout <<"B: f"<<endl;
    }
};
class C:public A{
    public:
    void f(){
        cout <<"C: f"<<endl;
    }
};
class B1:public A{
};

class VA{
    public:
    virtual void f(){
        cout << "virtual A: f"<<endl;
    }
};

class B2:public VA{
    public:
    void f(){
        cout <<"B2: f"<<endl;
    }
};

class CC{
    public:
    virtual void f(int a=10){
        cout<<"CC: "<< a<<endl;
    }
};

class BB:public CC{
    public:
    void f(int a=20){
        cout<<"BB: "<< a<<endl;
    }
};



int main(int argc, char const *argv[])
{
    //非虚函数
    A *a1 = new A;//静态类型A，动态类型A
    A *a2 = new B;//静态类型A，动态类型B
    A *a3 = new C;//静态类型A，动态类型C
    a1->f();//调用A::f
    a2->f();//调用A::f
    a3->f();//调用A::f
    a3 = new B;//静态类型A，动态类型B
    a3->f();//调用A::f
    a3 = nullptr;//静态类型A，没有动态类型
    a3->f();//调用A::f

    B *b = new B;//B覆盖基类函数，静态类型B，动态类型B
    b->f();//调用B::f
    B1 *b1 = new B1;//B1未覆盖基类函数
    b1->f();//调用A::f

    VA *va = new B2;
    va->f();//调用B2::f
    va = nullptr;
    //va->f();//编译通过，运行错误

    //访问控制符、默认参数静态绑定，virtual动态绑定
    BB* bb = new BB;
    bb->f();
    CC* cc = bb;
    cc->f();
    return 0;
}
