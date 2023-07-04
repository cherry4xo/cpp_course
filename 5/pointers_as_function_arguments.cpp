#include <stdio.h>

//example 1
void Increment_by_value(int a)
{
    a = a + 1;
    printf("Address of an a variable in the function = %d\n", &a);
}

void Increment_by_reference(int *p)
{
    *p = *p + 1;
    printf("Address of an a variable in the function = %d\n", p);
}

int main(int argc, char** argv)
{
    //for ex.1
    int a;
    a = 10;
    Increment_by_reference(&a);
    printf("Address of an a variable in the main function = %d\n", &a);
    printf("a = %d\n", a);
    return 0;
}