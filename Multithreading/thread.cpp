/*
*    Program to find sum of first N numbers using multithreading in C++11
*    This is faster than single threaded execution
*/



#include <iostream>
#include <thread>
#include <atomic>

std::atomic<long long> result(0);
long long n;

const int no_of_threads = 4;

void hello(int x)
{
    long long i = x, temp = 0;
    //std::cout << x << " " << n/no_of_threads << std::endl;
    for(i = x; i < x + n/no_of_threads; i++)
         temp += i;
    result += temp;
}

int main()
{
    std::thread t[no_of_threads];
    int i;
    //std::cin >> n;
    n = 10000000;

    for(i = 0; i < no_of_threads; i++)
    {
        t[i] = std::thread(hello, i*n/no_of_threads + 1);
    }

    for(i = 0; i < no_of_threads; i++)
    {
        t[i].join();
    }

    std::cout<<result;

}