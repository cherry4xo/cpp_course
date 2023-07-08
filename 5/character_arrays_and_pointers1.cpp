#include <stdio.h>
#include <iostream>
#include <string.h>

void basic_syntax()
{
    // requirements
    // 1. array should be large enough to accommodate the string
    // size of array >= numbers of characters in the string + 1
    // why + 1??? because the last one byte is point that the last character of the string was the last
    // this is \0 character

    char c[5];
    c[0] = 'j';
    c[1] = 'o';
    c[2] = 'h';
    c[3] = 'n';
    c[4] = '\0';
    int len = strlen(c);
    // int len = sizeof(c) / sizeof(c[0]);
    printf("%s, %d\n", c, len);

    return;
}

void init_ways()
{
    char c[20] = "john";
    int len = strlen(c);
    printf("Length = %d\n", len);
    char str[] = {'j', 'o', 'h', 'n', '\0'};

    return;
}

void pointers_and_stirngs()
{
    // important to know
    // pointers and arrays is different types
    // but are used in similar manner

    char c[6] =  "Hello";
    char* cp;
    cp = c; // all is okay
    // c = cp not valid
    // c = c + 1 not valid
    cp++;
    printf("%c\n", *(c + 1));
    printf("%c\n", *(cp + 1));

    return;
}

void print(char* c)
{
    while(*c != '\0')
    {
        printf("%c", *c);
        c++;
    }
    printf("\n");

    return;
}

void arrays_and_functions()
{
    // array are always passed to function by reference
    char c[20] = "Hello";
    print(c);

    return;
}

int main(int argc, char** argv)
{
    arrays_and_functions();

    return 0;
}