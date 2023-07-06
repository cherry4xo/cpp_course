#include <stdio.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    // fundamental data types

    int a = 69; // integer data type (2 or 4 bytes)
    printf("int size = %d\n", sizeof(a));

    // byte, short, long
    // signed, unsigned

    float b = 329.123; // floating-point data type (4 bytes)
    printf("float size = %d\n", sizeof(b));

    double c = 3768.123083129; // double floating-point data type (8 bytes)
    printf("double size = %d\n", sizeof(c));

    char d = 57; // character data type (1 byte) 
    printf("char size = %d\n", sizeof(d));

    wchar_t e = 1234; // wide character (4 bytes)
    printf("w_char_t size = %d\n", sizeof(e));

    bool f = 1; // boolean data type (1 byte)
    printf("bool size = %d\n", sizeof(f));

    void; // void data type (0 bytes)

    return 0;
}