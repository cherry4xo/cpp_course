#include <iostream>
#include <sys/types.h>

int main(int argc, char** argv)
{
    int16_t a, b;
    std::cin >> a;
    std::cin >> b;

    if (b != 0)
        std::cout << a + b << " " << a - b << " " << a * b << " " << static_cast<float>(a) / static_cast<float>(b) << std::endl;
    else
        std::cout << a + b << " " << a - b << " " << a * b << std::endl;
    return 0;
}