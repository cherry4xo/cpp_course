#include <stdio.h>
#include <iostream>

int main(int argc, char** argv)
{
    /*
    '&' bitwise AND
    '|' bitwise OR
    '<<' bitwise left shift
    '>>' bitwise right shift
    '~' bitwise complement
    '^' bitwise XOR
    */

    std::cout << (4 & 5) << std::endl;
    std::cout << (4 | 5) << std::endl;
    std::cout << (4 << 2) << std::endl;
    std::cout << (4 >> 2) << std::endl;
    std::cout << (~int(5)) << std::endl;
    std::cout << (~u_int64_t(5)) << std::endl;
    std::cout << (12 ^ 10) << std::endl;
    return 0;
}