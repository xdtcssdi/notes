#include <iostream>
#include <execinfo.h>
#include <stdlib.h>

using namespace std;
class A{
    virtual void f1(){
        cout<<"A: f1 "<<endl;
    }
    virtual void f2()=0;
    void f3(){
        cout<<"A: 34"<<endl;
    }
};

class B:A{
    virtual void f1(){
        cout<< "B: f1" <<endl;
    }
    void f2(){
        cout<<"B: f3"<<endl;
    }
};
class C{
    virtual void f(){
        cout<<"C: f1"<<endl;
    }
};

class D:A,C{//多继承，有多个虚指针 F = (*((int*)*(int*)*(vptr + n)+m))
    void f2(){
        cout<<"D: f2"<<endl;
    }
};

typedef void (*F)();
F& getVVtf64(void * obj, int n ,int m){
    F* c = (F*)((int64_t*)*((int64_t*)obj+n)+m);
    return *c;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
