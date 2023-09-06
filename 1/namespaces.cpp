#include <stdio.h>
#include <iostream>

namespace foo
{
    int sum(int a, int b)
    {
        return a + b;
    }
}

namespace guf
{
    int sum(int a, int b)
    {
        return a * b;
    }
}

// using namespace foo;
// using namespace guf;



int main(int argc, char** argv)
{
    int a = 10, b = 25;
    printf("%d\n", guf::sum(a, b));
    return 0;
}
