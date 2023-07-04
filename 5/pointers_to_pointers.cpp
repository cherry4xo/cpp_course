#include <iostream>
#include <stdio.h>

void pointer_to_pointer()
{
    int x = 5;
    int* p = &x;
    *p = 6;
    int** q = &p;
    int***r = &q;

    printf("%d\n", *p);
    printf("%d\n", *q);
    printf("%d\n", **q); // *(*q) the same and this is better for perception
    printf("%d\n", *(*r));
    printf("%d\n", *(*(*r)));
    ***r = 10;
    printf("%d\n", x);
    **q = *p + 2;
    printf("%d\n", x);
}

int main(int argc, char** argv)
{
    pointer_to_pointer();
    return 0;
}