#include <iostream>
#include <math.h>

int main(int argc, char** argv)
{
    int16_t a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if(a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                std::cout << "x = even number\n";
            else
                std::cout << "x has no roots\n";
        }
        else
            std::cout << "x = " << static_cast<float>(-c) / static_cast<float>(b) << std::endl;
    }
    else
    {
        float d = b * b - 4 * a * c;
        if (d < 0)
            std::cout << "x has no roots\n";
        else if (d == 0)
            std::cout << "x = " << (-b) / (2 * a) << std::endl;
        else
        { 
            std::cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << std::endl;
            std::cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << std::endl;
        }
    }

    return 0;
}