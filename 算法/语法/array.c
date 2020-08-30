#include <stdio.h>
void printArray(char (*a)[3][2], int c, int r);
int main(int argc, char const *argv[])
{
    char a[3][2]={{'a','b'}};
    printf("%lu\n", sizeof(&a));  // char *
    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(char*));
    char (*p)[3][2] = &a;
    printArray(p, 3, 2);
    printf("%lu", sizeof(char**));
    return 0;
}
void printArray(char (*a)[3][2], int c, int r){

    for(int i = 0; i < c; i++){
        for(int j = 0; j< r;j++)
            printf("%c ", (*a)[i][j]);
        printf("\n");
    }
}