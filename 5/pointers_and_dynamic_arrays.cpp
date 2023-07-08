#include <stdio.h>
#include <stdlib.h>

int total;

int Square(int x)
{
    return x * x;
}

int Square_of_sum(int x, int y)
{
    int z = Square(x + y);
    return z;
}

void foo()
{
    int a = 4, b = 8;
    total = Square_of_sum(a, b);
    printf("output = %d\n", total);
}

void stack_and_heap()
{
    // dynamic memory in C language
    int a; // goes on stack
    int* p; // goes on stack
    p = (int*)malloc(sizeof(int)); // now p is on heap
    *p = 10; // only one way to use heap memory
    free(p);
    p = (int*)malloc(sizeof(int));
    *p = 20;
    // whats wrong???
    // previous block of memory with 10 value still exists but we cannot reach this block
    // this is a garbage that have not creared automatically
    // before use the second malloc function we need to free previous block of memory
    free(p);
    p = (int*)malloc(20 * sizeof(int));
    // array of 20 int 

    // Example in C++ language
    int a0;
    int* p1;
    p1 = new int;
    *p1 = 10;
    delete p1;
    p1 = new int[20];
    delete[] p1;

    return;
}

void c_functions()
{
    // allocate block of memory: malloc, calloc, realloc
    // deallocate block of memory

    // void* malloc(size_t size) does not inits bytes with any value
    void* p0 = malloc(sizeof(int));
    printf("%d\n", p0);
    free(p0);
    int* p = (int*)malloc(sizeof(int));
    *p = 100;
    printf("Value = %d\nAddress = %d\n", *p, p);
    free(p);

    int* a = (int*)malloc(3 * sizeof(int));
    *a = 2;
    *(a + 1) = 4;
    *(a + 2) = 6;
    printf("Values: %d, %d, %d\nAddresses: %d, %d, %d\n", *a, *(a + 1), *(a + 2), a, a + 1, a + 2);
    free(a);

    // void* calloc(size_t num, size_t size) inits bytes with 0
    int* arr = (int*)calloc(3, sizeof(int));
    free(arr);

    // void* realloc(void* ptr, size_t size) changes the size of the allocated memory
    // making the new block of memory and copies all the values of the old block into the new block
    int* p1 = (int*)malloc(2 * sizeof(int));
    p1 = (int*)realloc(p1, 3 * sizeof(int));
    free(p1);

    return;
}

int main(int argc, char** arvg)
{
    // in c we need to know about 4 functions:
    /*
    malloc 
    calloc
    realloc
    free
    */
    // in c++ we need to know about 2 operators
    /*
    new
    delete
    */

   c_functions();

    return 0;
}