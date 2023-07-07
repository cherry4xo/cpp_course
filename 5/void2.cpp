#include <stdio.h>
#include <iostream>

int main(int argc, char** argv)
{
    int a = 10;
    void* p = &a;
    int* p0 = &a;

    printf("%d\n%d\n", p, p0);

    // std::cout << p << " " << p0 << "\n";

    return 0;
}