#include <stdio.h>

void array_structure()
{
    int a[5] = {0, 1, 2, 3, 4};
    // a[0] gives us base address of the array
    // n = 5; sizeof(int) = 4 => sizeof(a) = 5 * 4 = 20
    printf("Size of a = %d\nSize of int = %d\nn = %d\n", sizeof(a), sizeof(a[0]), sizeof(a) / sizeof(a[0]));
    printf("Base address = %d\n", a);
    printf("Also base address = %d\n", &a[0]);
    printf("First element = %d\n", a[0]);
    printf("Also first element = %d\n", *a);
    int* addr[5];
    for (size_t i = 0; i < 5; ++i) {
        *(addr + i) = (a + i);
    }
    for (size_t i = 0; i < 5; ++i) {
        printf("Address of %d element of a = %d\n", i, *(addr + i));
    }
}

void pointer_to_array()
{
    int a[5] = {0, 1, 2, 3, 4};
    int* p = a;
    for (size_t i = 0; i < 5; ++i) {
        printf("Address = %d\n", p);
        printf("Value = %d\n", *p);
        p++;
        //a++ would be invalid
    }
}

int main(int argc, char** argv)
{
    array_structure();
    // pointer_to_array();

    return 0;
}