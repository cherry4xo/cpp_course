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

// --- seq_cst ---
std::atomic<bool> x, y;
std::atomic<int> z;


void thread_write_x()
{
    x.store(true, std::memory_order_seq_cst);
}

void thread_write_y()
{
    y.store(true, std::memory_order_seq_cst);
}

void thread_read_x_then_y()
{
    while(!x.load(std::memory_order_seq_cst));
    if(y.load(std::memory_order_seq_cst))
    {
        ++z;
    }
}

void thread_read_y_then_x()
{
    while(!y.load(std::memory_order_seq_cst));
    if(x.load(std::memory_order_seq_cst))
    {
        ++z;
    }
}

std::thread th1(thread_write_x);
std::thread th2(thread_write_y);
std::thread th3(thread_read_x_then_y);
std::thread th4(thread_read_y_then_x);
std::thread thread0([&](){
        for(size_t i = 0; i < 10; ++i)
            std::cout << i << " ";
        std::cout << std::endl;
    });


void race_condition()
{
    thread0.join();
    z.store(0, std::memory_order_seq_cst);
    th4.join();
    th3.join();
    th2.join();
    th1.join();
    std::cout << z << std::endl;
}


int main(int argc, char** argv)
{
    // relaxed();
    race_condition();

    return 0;
}