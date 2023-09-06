#include <iostream>

int main(int argc, char** argv)
{
    bool curtains, lamp, sun;
    std::cin >> sun >> curtains >> lamp;
    if(lamp)
        std::cout << "light\n";
    else if(sun && curtains)
        std::cout << "light\n";
    else
        std::cout << "no light\n";

    return 0;
}