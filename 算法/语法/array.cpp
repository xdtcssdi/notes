#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    
    int a[10]={1,2,3,4};
    cout << &a << endl;
    cout << a << endl;
    cout << *(*&a+1) << endl;//读取地址立即量的时候，arr 会自动退化成&arr
    cout << *(a+1) << endl;
    return 0;
}
