#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

void about_atoi()
{
    // функция atoi преобразует строку string в целое значение типа int
    // функция интерпретирует всю строку, как целое число, игнорируя символы, не являющиеся цифрами 
    char input[256];
    std::cout << "Enter the number: ";
    std::cin >> input;

    int value = atoi(input);
    std::cout << "Entered number: " << value << "X2 Entered number: " << (value * 2) << std::endl;

    return;
}

void files()
{
    std::ofstream fout("any_file.txt");
    fout << "What can i do with this file";
    fout.close();
    system("pause");

    return;
}

void nice_loop_bro()
{
    unsigned char n = 256;
    for(unsigned char i = 0; i < n; ++i)
    {
        std::cout << "a";
    }
    unsigned char h = 128;
    for (unsigned char i = 0; i < 2 * h; ++i)
    {
        std::cout << "b";
    }

    return;
}