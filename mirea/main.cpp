#include <iostream>
#include <sys/types.h>

int main(int argc, char** argv)
{
    u_int16_t x = 10;
    u_int16_t* p = &x;

    std::cout << "x = " << x << " p = " << p << std::endl;

    return 0;
}