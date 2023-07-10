#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <sys/types.h>

class m_Encapsulation 
{
private:
    const size_t size;
    int* ptr;
public:
    m_Encapsulation(const size_t size): size(size)
    {
        ptr = (int*)malloc(size);
    }

    void set_value(int value) { *ptr = value; }
    int get_value() { return *ptr; }
    int get_size() { return size; }

    ~m_Encapsulation() { free(ptr); }
};

int main(int argc, char** argv)
{
    /*
    Инкапсуляция в программировании — это принцип, 
    согласно которому внутреннее устройство сущностей нужно объединять в специальной «оболочке» 
    и скрывать от вмешательств извне. 
    Доступ к объектам возможен через специальные открытые методы, 
    а напрямую обратиться к их содержимому нельзя.
    */

    m_Encapsulation* obj = new m_Encapsulation(sizeof(int)); 
    // после создания экземпляра класса - объекта, 
    // я могу взаимодействовать с его свойствами size и ptr
    // посредством методов set_value(), get_value() для *ptr
    // и get_size() для size

    // т.е., я не могу написать вот так
    // *(obj->ptr) = 1024;
    // printf("%d\n", *(obj->ptr));
    // printf("%d\n", obj->size);
   
    obj->set_value(1024);
    printf("%d\n", obj->get_value());
    printf("%d\n", obj->get_size());

    return 0;
}