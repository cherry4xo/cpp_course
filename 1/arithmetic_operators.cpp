#include <iostream>
#include <stdio.h>

int main(int argc, char** argv)
{
    int sum = 5 + 5;
    int sub = 10 - 5;
    int mult = 5 * 5;
    int divint = 5 / 2;
    float divfloat = float(5) / float(2);
    int mod = 5 % 2;
    int inc = sum++;
    inc = ++sum;
    int dec = sum--;
    dec = --sum;

    int x = 1;
    printf("%d\n", ++x);

    return 0;
}