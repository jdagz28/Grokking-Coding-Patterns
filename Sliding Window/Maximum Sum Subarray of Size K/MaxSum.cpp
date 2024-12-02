#include <iostream>
#include <vector>

int findMaxSumSubArray(int k, const std::vector<int> &arr)
{
    int maxSum = 0;
    int windowStart = 0;
    int windowSum = 0;

    for (size_t windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        windowSum += arr[windowEnd];
        if (static_cast<int>(windowEnd) >= k - 1)
        {
            maxSum = std::max(maxSum, windowSum);
            windowSum -= arr[windowStart];
            windowStart++;
        }
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