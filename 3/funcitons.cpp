#include <stdio.h>

/*
function struct
<Data type> <Function name>(<param1 data type> <param1>, ...)
{
    ... (some of code)
    return <Function data type>
    если void то "return;" or nothing (the same)
}
*/
//examples

void say_hi();
int sum(int a, int b);

int main(int argc, char** argv)
{

    return 0;
}

void say_hi()
{
    printf("Hi buddy!\n");
}

int sum(int a, int b)
{
    int value = a + b;
    return value;
}