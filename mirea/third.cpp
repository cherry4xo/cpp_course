#include <iostream>
#include <sys/types.h>

int main(int argc, char** agrv)
{
    float b, c;
    std::cin >> b;
    std::cin >> c;

    if (b == 0)
    {
        if (c == 0)
            std::cout << "x = ever number\n";
        else
            std::cout << "x has no roots\n";
    }
    else
        std::cout << "x = " << static_cast<float>(-c) / static_cast<float>(b) << std::endl;

    return 0;
}