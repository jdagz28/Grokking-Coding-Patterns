#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
    public:
        int totalFruit(std::vector<int> &fruits) 
        {
            int maxLength = 0;
            int windowStart = 0;
            std::unordered_map<char, int> fruitFrequencyMap;

            for (size_t windowEnd = 0; windowEnd < fruits.size(); windowEnd++)
            {
                // Add the current fruit to the map
                fruitFrequencyMap[fruits[windowEnd]]++;

                // If we have more than 2 types of fruits, shrink the window
                while (static_cast<int>(fruitFrequencyMap.size()) > 2)
                {
                    fruitFrequencyMap[fruits[windowStart]]--;
                    if (fruitFrequencyMap[fruits[windowStart]] == 0)
                        fruitFrequencyMap.erase(fruits[windowStart]);
                    windowStart++;
                }
                maxLength = std::max(maxLength, static_cast<int>(windowEnd - windowStart + 1));
            }
            return (maxLength);
        }
};

int main()
{
    Solution solution;
    
    std::vector<int> ex1 = {1, 2, 1};
    std::vector<int> ex2 = {0, 1, 2, 2};
    std::vector<int> ex3 = {1, 2, 3, 2, 2};

    std::cout << "Fruits: ";
    for (auto i : ex1)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Maximum number of fruits: \t" << solution.totalFruit(ex1) << std::endl << std::endl;
    
    std::cout << "Fruits: ";
    for (auto i : ex2)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Maximum number of fruits: \t" << solution.totalFruit(ex2) << std::endl << std::endl;

    std::cout << "Fruits: ";
    for (auto i : ex3)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Maximum number of fruits: \t" << solution.totalFruit(ex3) << std::endl << std::endl;

    return (0);
}