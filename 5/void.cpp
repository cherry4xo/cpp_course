#include <stdio.h>
#include <sys/types.h>

struct entity
{
    u_int8_t* ptr;
    int size;
};

entity* new_entity(size_t size)
{
    u_int8_t a = 58446;
    entity* ent = new entity;
    ent->ptr = &a;
    ent->size = size;
    return ent;
}

void* foo(size_t size)
{
    entity* e = new_entity(4);

    u_int8_t* user_ptr = e->ptr;
    return user_ptr;
}

int main(int argc, char** argv)
{
    printf("%d\n", foo(4));

    return 0;
}