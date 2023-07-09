#include <stdio.h>

int SumOfElemsWithSize(int a[], int size)
{
    int sum = 0;
    for(size_t i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum;
}

int SumOfElemsWithoutSize(int* a)
{
    int sum = 0;
    int size = sizeof(a) / sizeof(a[0]);
    printf("Size in sum function = %d\n", size);
    for (size_t i = 0; i < size; ++i) {
        sum += a[i]; // or *(a + i)
    }
    return sum;
}

void foo()
{
    int a[5] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    printf("Size in main function = %d\n", size);
    int value1 = SumOfElemsWithSize(a, size); // or &a[0]
    int value2 = SumOfElemsWithoutSize(a); // or &a[0]
    printf("Sum of elements = %d\n", value1);
    printf("Sum of elements = %d\n", value2);

    return;
}

int main(int argc, char** argv)
{
    foo();

    return 0;
}