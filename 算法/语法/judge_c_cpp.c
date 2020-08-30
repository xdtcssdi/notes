#include <stdio.h>

int main(int argc, char *argv[])
{
    #ifdef __cplusplus
        printf("This is a c ++ program!\n");
    #else
        printf("This is a c program!");
    #endif
        return 0;
}