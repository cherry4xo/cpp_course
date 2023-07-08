#include <stdio.h>

void print(const char* c)
{
    while(*c != '\0')
    {
        printf("%c", *c);
        c++;
    }
    printf("\n");

    return;
}

void print_char_array()
{
    // char c[20] = "Hello";
    char* c = "Hello"; // will be the same output but
    // string gets stored as compule time constant
    // we cannot do this
    // *c = 'A';
    // but if we use char c[20] = "Hello";
    // expression like c[0] = 'A'; will be valid
    print(c);
}

int main(int argc, char** argv)
{
    print_char_array();

    return 0;
}