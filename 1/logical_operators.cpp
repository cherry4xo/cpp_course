#include <iostream>
#include <stdio.h>

int main(int argc, char** argv)
{
    int a = 0, b = 10;
    if (a > b){ std::printf("a is greater than b\n");}
    else {std::printf("b is greater or equals a\n");}

    int a = 5; b = 10;
    if (a > 0 && b > 0) {std::printf("both values are positive\n");}

    int a = -10; int b = 5;
    if (a > 0 || b > 0) {std::printf("at least one value is positive\n");}

    int a = 5;
    if (!(a < 0)) {std::printf("value is not negative\n");}

    return 0;
}