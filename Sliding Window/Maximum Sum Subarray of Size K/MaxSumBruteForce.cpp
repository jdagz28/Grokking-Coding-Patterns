#include <iostream>
#include <vector>

int findMaxSumSubArray(int k, const std::vector<int> &arr)
{
    int maxSum = 0;
    for (size_t i = 0; i <= arr.size() - k; i++)
    {
        int arrSum = 0;
        for (size_t j = i; j < i + k; j++)
            arrSum += arr[j];
        maxSum = std::max(maxSum, arrSum);
    }
    return (maxSum);
}

void printArray(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        std::cout << "{}" << std::endl;
        return;
    }
    
    std::vector<int>::const_iterator it;
    std::cout << "{ ";
    for (it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it;
        if (it != arr.end() - 1) 
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

int main()
{
    std::vector<int> ex1 = {2, 1, 5, 1, 3, 2};
    std::vector<int> ex2 = {2, 3, 4, 1, 5};
    
    printArray(ex1);
    std::cout << "Maximum sum of a subarray of size 3: "; 
    std::cout << findMaxSumSubArray(3, ex1) << std::endl << std::endl;

    printArray(ex2);
    std::cout << "Maximum sum of a subarray of size 2: "; 
    std::cout << findMaxSumSubArray(2, ex2) << std::endl;
    return (0);
}