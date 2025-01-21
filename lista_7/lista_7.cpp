#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <exception>
#include "allocator.h"

void dot_product(const std::vector<double>& v1, const std::vector<double>& v2, std::promise<double> promise)
{
    try 
    {
        if (v1.empty() || v2.empty())
        {
            throw std::invalid_argument("Pusty wektor");
        }
        if (v1.size() != v2.size())
        {
            throw std::invalid_argument("Wektory roznych rozmiarow");
        }

        double product = 0.0;
        for (int i = 0; i < v1.size(); i++)
        {
            product += v1[i] * v2[i];
        }
        promise.set_value(product);
    }

    catch(const std::invalid_argument& e)
    {
        promise.set_exception(std::make_exception_ptr(e));
    }
    
}

void sum_dot_products(std::vector<std::future<double>>& futures)
{
    double sum = 0.0;
    bool error = false;

    for (auto& future : futures)
    {
        try
        {
            sum += future.get();
        }
        catch (const std::exception& e)
        {
            std::cout << "Blad: " << e.what() << "\n";
            error = true;
        }
    }

    if (!error)
    {
        std::cout << "Suma iloczynow skalarnych: " << sum << "\n";
    }
}



int main()
{
    //Zadanie 1
    std::vector<std::vector<double>> v1 = { 
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {1.0, 2.0, 3.0}
    };

    std::vector<std::vector<double>> v2 = {
        {3.0, 2.0, 1.0},
        {6.0, 5.0, 4.0},
        {9.0, 8.0, 7.0},
        {3.0, 2.0, 1.0},
        {6.0, 5.0, 4.0},
        {9.0, 8.0, 7.0},
        {3.0, 2.0, 1.0},
        {6.0, 5.0, 4.0},
        {9.0, 8.0, 7.0},
        {3.0, 2.0, 1.0}
    };
 

    std::vector<std::promise<double>> promises(10);
    std::vector<std::future<double>> futures;

    for (auto& promise : promises)
    {
        futures.emplace_back(promise.get_future());
    }

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++)
    {
        threads.emplace_back(dot_product, v1[i], v2[i], std::move(promises[i]));
    }

    for (auto& thread : threads)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }

    sum_dot_products(futures);


    //Zadanie 2
    cpplab::allocator<int> alloc;
    std::cout << "\n" << typeid(cpplab::allocator<int>::value_type).name() << "\n";

    cpplab::allocator<int>::value_type* p_test = alloc.allocate(1);
    std::cout << *p_test << "\n";
    *p_test = 3;
    std::cout << *p_test << "\n";
    alloc.deallocate(p_test, 1);

    std::vector<int, cpplab::allocator<int>> v;
    v.push_back(13);
    v.push_back(23);
    std::cout << *(v.end() - 1) << "\n";
}
