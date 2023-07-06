#include <iostream>
#include <math.h>


int main(int argc, char** argv)
{
    for(size_t i = 2; i < 2 << 10; i = i << 1)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::pow(2, 10) << std::endl;

    int i = 0;
    for(;;)
    {
        if (i > 10) 
            break;
        std::cout << i << "\n";
        i++;
    }

    return 0;
}