#include <stdio.h>

void swap1(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void swap2(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap3(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char const *argv[])
{
    // 值传递=指针传递、引用传递
    int a,b;
    a=3,b=5;
    swap1(a,b);
    printf("%d %d\n",a,b);

    a=3,b=5;
    swap2(&a,&b);
    printf("%d %d\n",a,b);
    
    a=3,b=5;
    swap3(a,b);
    printf("%d %d\n",a,b);
    return 0;
}
