#include <stdio.h>
#include <iostream>
#include <sys/types.h>

int main(int argc, char** argv)
{
    // 11100100 01001110
    u_int16_t x = 58446;
    u_int16_t* p = &x;
    printf("%d\n", *p);
    // printf("%d\n", *(p + 1));
    void* p0 = p;
    // printf("%d\n", *((u_int8_t*)(void*)(p)));
    // printf("%d\n", *((u_int8_t*)p0));

    printf("%d\n", *((char*)(p)));

    // std::cout << *((u_int8_t*)p0) << std::endl;

    return 0;
}