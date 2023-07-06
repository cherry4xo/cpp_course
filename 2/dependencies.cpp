#include <stdio.h>

void foo();
void deb();

void foo()
{
    printf("Hi\n");
    deb();
}

void deb()
{
    printf("Bye!\n");
    foo();
}

int main(int argc, char** argv)
{
    foo();


    return 0;
}