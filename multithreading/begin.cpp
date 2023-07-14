#include <stdio.h>
#include <memory>
#include <thread>
#include <sys/types.h>
#include <atomic>


void foo1()
{
    u_int64_t g_count = 0;

    std::thread t1([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            ++g_count;
    });

    std::thread t2([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            ++g_count;
    });

    t1.join();
    t2.join();

    printf("%d\n", g_count);

    return;
}

void foo2()
{
    std::atomic<u_int64_t> g_count { 0 };

    std::thread t1([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            g_count.fetch_add( 1 );
    });

    std::thread t2([&]()
    {
        for(auto i = 0; i < 1000000; ++i)
            g_count.fetch_add( 1 );
    });

    t1.join();
    t2.join();

    printf("%d\n", g_count.load());

    return;
}


int main(int argc, char** argv)
{
    foo1();
    foo2();

    return 0;
}