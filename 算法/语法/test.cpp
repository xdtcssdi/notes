#include <iostream>
using namespace std;

class A{
    public:
    void f()const{
        cout<<"ff"<<endl;
    }
};

int main(int argc, char const *argv[])
{
 A* a = new A;
    a->f();
    return 0;
}
