#include <iostream>

int main(int argc, char** argv)
{
    for(size_t i = 2; i < 2 << 10; i = i << 1)
    {
        std::cout << i << std::endl;
    }

    for(;;)
    {
        std::cout << "10\n";
    }

    return 0;
}