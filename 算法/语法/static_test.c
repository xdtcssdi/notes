#include <stdio.h>

void fun1(){
    int a = 0;// 普通的局部变量，auto可以省略的
    a++;
    printf("%d ", a);
}

void fun2(){
    static int a = 0; // 静态的局部变量
    a++;
    printf("%d ", a);
}

void fun3(){
    register int a = 0; // 建议存到寄存器中，编译器并不一定会将它处理为寄存器变量
    a++;
    printf("%d ", a);
}

extern int b;
// extern int a;
void fun4(){
    printf("%d ", b);
    //printf("%d ", a);
}


int main(int argc, char const *argv[])
{
    fun1();
    fun1();
    printf("\n");
    fun2();
    fun2();
    printf("\n");
    fun3();
    fun3();
    printf("\n");
    fun4();
    return 0;
}
