#include <stdio.h>
#include <string>

/*
<data type> <func name>(<func param1> <param name1> ...)
{
    ...(some code)
    return <function data type>
    есл void, return; или ничего
}
*/

void say_hi();
int sum(int a, int b);

void print(int a = 10)
{
    printf("%d\n", a);
}

bool item(int a, int b)
{
    return a > b;
}

int main(int argc, char** argv)
{
    auto hello { [](std::string str){printf("Hello, %s!\n", str.c_str()); } };

    hello("Nikita");

    return 0;
}

void say_hi()
{
    printf("Hi buddy\n");
}

int sum(int a, int b)
{
    return a + b;
}