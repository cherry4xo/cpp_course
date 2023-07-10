#include <stdio.h>
#include <memory>
#include <stdlib.h>

class m_ExClass
{
public:
    int size;
    int* ptr;
public:
    m_ExClass(size_t size): size(size) 
    {
        this->ptr = (int*)malloc(this->size);
    }
    ~m_ExClass() { free(this->ptr); }
    void* m_malloc()
    {
        free(this->ptr);
        this->ptr = (int*)malloc(this->size);
        return this->ptr;
    }
    void set_value(int value) { *(this->ptr) = value; }
    int get_value() { return *(this->ptr); }
};

void m_unique_ptr()
{
    /*
    Шаблонный класс unique_ptr представляет собой уникальный указатель на объект. 
    Указатель нельзя копировать, но можно передавать владение им с помощью std::move. 
    При уничтожении указателя автоматически вызывается деструктор объекта, на который он указывает.
    */

   std::unique_ptr<m_ExClass> unq1(new m_ExClass(4));
   // or
   auto unq2 = std::make_unique<int>(4);

   unq1->set_value(10);
   printf("%d\n", unq1->get_value());

    return;
}

void unique_ptr_rules()
{
    auto unq = std::make_unique<int>();
    *unq = 4;

    printf("%d\n", *unq);

    // unique_ptr на то и unique, что обладает таким свойством,
    // что его нельзя копировать, но владение им можно передать другой переменной
    // с помощью функции std::move

    // auto cpy = unq;
    // вот так нельзя

    auto mov = std::move(unq);
    printf("%d\n", *mov);

    // всегда можно получать из std::unique_ptr обычный указатель
    // с помощью метода get()
    // но так не стоит делать
    int* ptr = mov.get();
    printf("%d\n", *ptr);

    // но никто не мешает создавать ссылки
    auto& ref = mov;
    printf("%d\n", *ref);

}

void shared_weak()
{
    /*
    shared_ptr отличается от unique_ptr тем, что может иметь несколько владельцев
    т.е работа с shared_ptr схожа с работой с unique_ptr, за исключением того, 
    что shared_ptr можно смело копировать

    дальше вставка из интернетов, но тут очев:
        Число существующих указателей отслеживается при помощи счетчика ссылок. 
        Когда счетчик ссылок обнуляется, вызывается деструктор объекта.
    */

    auto ptr = std::make_shared<int>();

    /*
    есть несколько нюансов работы с shared_ptr
    Интересные грабли при использовании shared_ptr заключается в том, 
    что с его помощью можно создать циклические ссылки. 
    Например, есть два объекта. 
    Первый ссылается при помощи shared_ptr на второй, а второй — на первый. 
    Даже если ни на один из объектов нет других ссылок, 
    счетчики ссылок никогда не обнулятся, и объекты никогда не будут уничтожены.

    Эта проблема обходится при помощи weak_ptr, так называемого слабого указателя. 
    Класс weak_ptr похож на shared_ptr, но не участвует в подсчете ссылок. 
    Также у weak_ptr есть метод lock(), возвращающий временный shared_ptr на объект.
    Ниже пример
    */
}

class SomeClass {
public:
    void sayHello() {
        printf("Hello!\n");
    }
    ~SomeClass() {
        printf("~SomeClass\n");
    }
};

void foo()
{
    std::weak_ptr<SomeClass> wptr;

    {
        auto ptr = std::make_shared<SomeClass>();
        wptr = ptr;

        if(auto tptr = wptr.lock()) {
            tptr->sayHello();
        } else {
            printf("lock() failed\n");
        }
    }

    if(auto tptr = wptr.lock()) {
        tptr->sayHello();
    } else {
        printf("lock() falied\n");
    }
}

int main(int argc, char** argv)
{
    // m_unique_ptr();
    unique_ptr_rules();

    return 0;
}