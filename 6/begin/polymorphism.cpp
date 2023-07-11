#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string>
#include <iostream>

// существует несколько видов полиморфизма
// 1. Ad Hoc - специальный полиморфизм
// 2. Параметрический полиморфизм 
// 3. Полиморфизм подтипов

// 1. Ad Hoc полиморфизм - хуета та еще
// достигается путем перегрузки методов и операторов
class A 
{
public:
    void ShowMessage()
    {
        printf("message\n");
    }

    void ShowMessage(std::string message)
    {
        std::cout << message << "\n";
    }
};

void foo1()
{
    A* a = new A();
    a->ShowMessage();
    a->ShowMessage("Another message");
}

// Параметрический полиморфизм
// вот это прикольная тема, советую
// достигается путем использования template
template <typename T>
class B
{
private:
    T value;
public:
    B (T value): value(value) {}

    T get_value() { return value ;}
    void set_value (T value) { this->value = value; }
};

void foo2()
{
    B<int>* t_int = new B<int>(5);
    B<float>* t_float = new B<float>(6.0f);

    printf("%d\n", t_int->get_value());
    printf("%d\n", t_float->get_value());
}

// Полиморфизм подтипов
// мвп однозначно
// достигается путем наследования
class C
{
public:
    virtual void ShowMessage()
    {
        printf("message\n");
    }
};

class D: public C
{
public:
    void ShowMessage() override  
    {
        printf("override message\n");
    }
};

void foo3()
{
    C* c = new C;
    C* d = new D;
}

class Parent
{
public:
    virtual void Test2()
    {
        printf("parent test2 method\n");
    }
};

class Child: public Parent
{
public:
    void Test()
    {
        printf("test method");
    }

    void Test2() override
    {
        this->Test();
    }
};

void foo4()
{
    Parent* obj = new Child;
    obj->Test2();
    // obj->Test();
}

class Animal
{
public:
    virtual void move() = 0;
};

class Fish: public Animal
{
public:
    void move() override 
    {
        printf("The fish is swimming\n");
    }
};

class Bird: public Animal
{
public:
    void move() override
    {
        printf("The bird is flying\n");
    }
};

void foo5()
{
    Fish* fish = new Fish;
    Bird* bird = new Bird;

    // static polymorphism
    fish->move();
    bird->move();

    Animal* animal = new Fish;
    animal->move();
    animal = new Bird;
    animal->move();
}

int main(int argc, char** argv)
{
    /*
    Если простыми словами, то полиморфизм - это механизм языка, который 
    обеспечивает различное поведение метода класса в зависимости от 
    типа объекта, который вызывает эту функцию
    */
   foo5();


    return 0;
}