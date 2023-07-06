#include <stdio.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    // 11100100 01011000
    u_int16_t x = 58456;
    u_int16_t* p = &x;
    printf("%d\n", *p);
    // printf("%d\n", *(p + 1));
    void* p0 = p;
    printf("%d\n", *((u_int8_t*)(void*)(p)));

    return 0;
}