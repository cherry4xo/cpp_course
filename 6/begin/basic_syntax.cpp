#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

class m_ClassExample
{
private:
    int number;
    int squared_number() { return number * number; }
public:
    int status;
    int get_value() { return squared_number(); }
    void set_number(int number) { this->number = number; }
};

int main(int argc, char** argv)
{
    m_ClassExample obj;
    obj.set_number(5);
    printf("%d\n", obj.get_value());

    return 0;
}