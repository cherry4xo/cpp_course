#include <stdio.h>

void simple_working()
{
    int a = 10;
    int* p = &a;
    printf("Address of p: %d\n", p); // адрес памяти
    printf("Value at p: %d\n", *p); // 10
    int b = 20;
    *p = b;
    printf("Value at p: %d\n", *p); // 20

    return;
}

void pointers_arithmetic()
{
    int a = 20;
    int* p = &a;
    printf("p address: %d\n", p);
    printf("Size of integer: %d\n", sizeof(int));
    printf("p + 1 address: %d\n", p + 1);

    return; 
}

void void_pointers()
{
    int a = 1025;
    int* p = &a;
    printf("Size of integer: %d\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);
    // char* p0;
    // p0 = (char*)(p);
    // printf("Size of char: %d\n", sizeof(char));
    // printf("Address = %d, value = %d\n", p0, *p0);
    // printf("Address = %d, value = %d\n", p0 + 1, *(p0 + 1));
    void* p0 = p;
    printf("Address = %d, value = %d\n", p0, *((int*)p0));

    return;
}

int main(int argc, char** argv)
{
    pointers_arithmetic();

    return 0;
}