#include "Functionalaties.h"

void OddNumbers(std::vector<int> &vec)
{
    if (vec.empty())
    {
        std::runtime_error("Data is empty\n");
    }
    for (int i : vec)
    {
        if (i % 2 != 0)
        {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}

void ThreadExecution(std::array<std::thread, 3> &threads)
{

    for (std::thread &thr : threads)
    {
        if (thr.joinable())
        {
            thr.join();
        }
    }
}

void SumOfnumbers(std::vector<int> &res, int N)
{
    if (res.empty())
    {
        throw std::runtime_error("Data is Empty!");
    }
    int sum = 0;
    for (int i : res)
    {
        if (N == 0)
        {
            break;
        }
        sum += i;
    }
    std::cout << "Sum of number is: " << sum << std::endl;
}
