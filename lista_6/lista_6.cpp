#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include "thread_pool.h"

static void sort_vector(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    std::sort(start, end);
}

static void print_vector(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    for (start; start != end; start++)
    {
        std::cout << *start << " ";
    }
}


int main()
{
    //Zadanie 1
    int n = 1000;
    std::vector<int> numbers(n, 0);

    for (int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 10 + 1;
    }

    std::vector<int>::iterator half = numbers.begin() + numbers.size() / 2;

    std::thread thread_1(sort_vector, numbers.begin(), half);
    std::thread thread_2(sort_vector, half, numbers.end());

    thread_1.join();
    thread_2.join();

    std::cout << "Pierwsza polowa: ";
    print_vector(numbers.begin(), half);
    std::cout << "\n\n";

    std::cout << "Druga polowa: ";
    print_vector(half, numbers.end());
    std::cout << "\n\n";


    //Zadanie 2
    Thread_pool pool(3);

    pool.add_task([]() { return 1.0; });
    pool.add_task([]() { return 2.0; });
    pool.add_task([]() { return 3.0; });

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Srednia: " << pool.average() << "\n";

}
