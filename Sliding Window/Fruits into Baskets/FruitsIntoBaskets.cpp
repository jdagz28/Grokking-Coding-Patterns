#include <iostream>
#include <vector>
#include <unordered_map>


class MaxFruitCountOf2Types
{
    public:
        int findLength(const std::vector<char> &arr)
        {
            int maxLength = 0;
            int windowStart = 0;
            std::unordered_map<char, int> fruitFrequencyMap;

            // try to extend the range [windowStart, windowEnd]
            for (size_t windowEnd = 0; windowEnd < arr.size(); windowEnd++)
            {
                char rightFruit = arr[windowEnd];
                fruitFrequencyMap[rightFruit]++;

                // shrink the sliding window, until we are left with '2' fruits in the fruitFrequencyMap
                while (static_cast<int>(fruitFrequencyMap.size()) > 2)
                {
                    char leftFruit = arr[windowStart];
                    fruitFrequencyMap[leftFruit]--;
                    if (fruitFrequencyMap[leftFruit] == 0)
                        fruitFrequencyMap.erase(leftFruit);
                    windowStart++; // shrink the window
                }
                maxLength = std::max(maxLength, static_cast<int>(windowEnd - windowStart + 1)); // remember the maximum length so far
            }
            return (maxLength);
        }
};

int main()
{
    MaxFruitCountOf2Types solution;
    
    std::vector<char> ex1 = {'A', 'B', 'C', 'A', 'C'};
    std::vector<char> ex2 = {'A', 'B', 'C', 'B', 'B', 'C'};
    
    std::cout << "Fruits: ";
    for (auto i : ex1)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Maximum number of fruits: \t" << solution.findLength(ex1) << std::endl << std::endl;
    
    std::cout << "Fruits: ";
    for (auto i : ex2)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Maximum number of fruits: \t" << solution.findLength(ex2) << std::endl << std::endl;

    return (0);
}