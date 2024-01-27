#include <iostream>
#include "Functionalaties.h"
#include <mutex>
#include <condition_variable>
std::condition_variable cv;
std::mutex mt;
int number1, number2;
bool flag = true;
int AdditionOftwoNumbers()
{
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, []()
            { return flag; });

    return number1 + number2;
}

int main()
{

    std::cout << "Enter Number1: ";
    std::cin >> number1;
    std::cout << "Enter Number2: ";
    std::cin >> number2;
    flag = true;
    std::future<int> result = std::async(std::launch::async, AdditionOftwoNumbers);
    std::cout << "Addition of two number is: " << result.get() << "\n";

    std::vector<int> vec;

    int i = 0;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> i;
        vec.push_back(i);
    }

    std::array<std::thread, 3> threads;

    try
    {
        threads[0] = std::thread(SumOfnumbers, std::ref(vec), 3);
    }
    catch (std::runtime_error &r)
    {
        std::cout << r.what() << "\n";
    }

    try
    {
        threads[1] = std::thread(&OddNumbers, std::ref(vec));
    }
    catch (std::runtime_error msg)
    {
        std::cout << msg.what();
    };

    ThreadExecution(threads);
}