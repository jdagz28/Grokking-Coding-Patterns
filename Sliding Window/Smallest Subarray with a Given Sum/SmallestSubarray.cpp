#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>


class MinSizeSubArraySum
{
    public:
        static int findMinSubArray(int S, const std::vector<int> & arr) 
        {
            int windowSum = 0;
            int minLength = std::numeric_limits<int>::max();
            int windowStart = 0;

            for (size_t windowEnd = 0; windowEnd < arr.size(); windowEnd++)
            {
                windowSum += arr[windowEnd];  // add the next element
                // shrink the window as small as possible until the 'windowSum' is smaller than 'S'
                while (windowSum >= S)
                {
                    minLength = std::min(minLength, static_cast<int>(windowEnd - windowStart + 1));
                    windowSum -= arr[windowStart];  // subtract the element going out
                    windowStart++;  // slide the window ahead
                }
            }

            return (minLength == std::numeric_limits<int>::max() ? 0 : minLength);
        }
};

void printVector(const std::vector<int> &arr)
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
    std::vector ex1 = {2, 1, 5, 2, 3, 2};
    std::vector ex2 = {2, 1, 5, 2, 8};
    std::vector ex3 = {3, 4, 1, 1, 6};

    printVector(ex1);
    std::cout << "Smallest subarray length: " << MinSizeSubArraySum::findMinSubArray(7, ex1) << std::endl << std::endl;

    printVector(ex2);
    std::cout << "Smallest subarray length: " << MinSizeSubArraySum::findMinSubArray(7, ex2) << std::endl << std::endl;

    printVector(ex3);
    std::cout << "Smallest subarray length: " << MinSizeSubArraySum::findMinSubArray(8, ex3) << std::endl << std::endl;
}
