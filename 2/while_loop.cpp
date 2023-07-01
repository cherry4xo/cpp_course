#include <iostream>

int main(int argc, char** argv)
{
    u_int16_t iterator = 0;
    while (iterator < sizeof(u_int16_t) * 8)
    {
        std::cout << iterator << std::endl;
        iterator++;
    }
    iterator = 0;
    while (true)
    {
        std::cout << iterator << std::endl;
        iterator++;
        if(iterator == sizeof(u_int16_t) * 8){
            break;
        }
    }

    return 0;
}