#include <stdio.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <sys/types.h>

static int v1 = 0;
static std::atomic<int> v2 { 0 };

int add_v1()
{
    return ++v1;
    /* Generated x86-64 assembly:
        mov     eax, DWORD PTR v1[rip]
        add     eax, 1
        mov     DWORD PTR v1[rip], eax
    */
}

int add_v2()
{
    return v2.fetch_add(1);
    /* Generated x86-64 assembly:
        mov     eax, 1
        lock xadd       DWORD PTR _ZL2v2[rip], eax
    */
}

// Example 1
std::atomic<size_t> counter{ 0 };

void process()
{
    counter.fetch_add(1, std::memory_order_relaxed);
}
void print_metrics()
{
    std::cout << "Number of requests = " << counter.load(std::memory_order_relaxed) << std::endl;
}

void relaxed()
{
    std::thread t1(process);
    std::thread t2(print_metrics);

    t1.join();
    t2.join();

    return;
}

// Example 2

std::atomic<bool> stopped { false };

void thread1()
{
    while(!stopped.load(std::memory_order_relaxed)){
        // Do smth
    }
}

void stop_thread1()
{
    stopped.store(true, std::memory_order_relaxed);
}

int main(int argc, char** argv)
{
    relaxed();

    return 0;
}