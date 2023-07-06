#include <iostream>
#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main(int argc, char** agrv)
{
    int a = 20, b = 50;
    printf("%d\n", sum(a, b));
    // printf("Hello world!\n");
    return 0;
}