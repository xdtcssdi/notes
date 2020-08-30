#include <iostream>
using namespace std;
int i = 10;
extern int c=10;//在函数外部的extern声明带有初始化，看作是定义
/*
https://blog.csdn.net/skk18739788475/article/details/79643978
*/
int main(int argc, char const *argv[])
{
        
    extern int i;       //声明，不是定义
    cout << i;
    // 除非有extern关键字，否则都是变量的定义。
    extern int d;//声明
    //cout <<d ; 链接时候找不到变量地址报错
    return 0;
}
