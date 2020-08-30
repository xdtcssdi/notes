#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    char arr[10]={'A','B','C','\0'};
    cout << "sizeof = " << sizeof(arr) << endl;
    cout << "char* = "<< sizeof((char*)arr) << endl;
    cout << "strlen = " << strlen(arr)<<endl;
    /*
    sizeof 操作符，传入数组不变
    strlen 函数，传入数组退化为指针
    */
    return 0;
}
