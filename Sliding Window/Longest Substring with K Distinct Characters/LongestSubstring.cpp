#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>


class LongestSubstringKDistinct
{
    public:
        int findLength(const std::string &str, int K)
        {
            int maxLength = 0;
            int windowStart = 0;
            std::unordered_map<char, int> charFrequencyMap;

            // try to extend the range [windowStart, windowEnd]
            for (size_t windowEnd = 0; windowEnd < str.length(); windowEnd++)
            {
                char rightChar = str[windowEnd];
                charFrequencyMap[rightChar]++;

                // shrink the sliding window, until we are left with 'k' distinct characters in the char_frequency_map
                while (static_cast<int>(charFrequencyMap.size()) > K)
                {
                    char leftChar = str[windowStart];
                    charFrequencyMap[leftChar]--;
                    if (charFrequencyMap[leftChar] == 0)
                        charFrequencyMap.erase(leftChar);
                    windowStart++; // shrink the window
                }
                maxLength = std::max(maxLength, static_cast<int>(windowEnd - windowStart + 1)); // remember the maximum length so far
            }
            return (maxLength);
        }
};

int main()
{
    LongestSubstringKDistinct solution;
    
    std::string ex1 = "araaci";
    std::string ex2 = "araaci";
    std::string ex3 = "cbbebi";

    std::cout << "String: " << ex1 << " \tK:2" << std::endl;
    std::cout << "Longest substring with K distinct characters: \t" << solution.findLength(ex1, 2) << std::endl << std::endl;
    std::cout << "String: " << ex2 << " \tK:1" << std::endl;
    std::cout << "Longest substring with K distinct characters: \t" << solution.findLength(ex2, 1) << std::endl << std::endl;
    std::cout << "String: " << ex3 << " \tK:3" << std::endl;
    std::cout << "Longest substring with K distinct characters: \t" << solution.findLength(ex3, 3) << std::endl << std::endl;

    return (0);
}