#include <iostream>
#include <unordered_map>
#include <string>

class Solution 
{
    public:
        int lengthOfLongestSubstringKDistinct(const std::string &s, int k)
        {
        if (k == 0 || s.empty())
            return 0;

        std::unordered_map<char, int> charCountMap;
        int maxLength = 0;
        int left = 0;

        for (size_t right = 0; right < s.length(); ++right) 
        {
            // Add current character to map
            char rightChar = s[right];
            charCountMap[rightChar]++;
            // Shrink window until we have at most k distinct characters
            while (static_cast<int>(charCountMap.size()) > k) 
            {
                char leftChar = s[left];
                charCountMap[leftChar]--;
                if (charCountMap[leftChar] == 0) 
                    charCountMap.erase(leftChar);
                left++;
            }
            // Update maxLength if this window is larger
            maxLength = std::max(maxLength, static_cast<int>(right - left + 1));
        }

        return (maxLength);
    }
};

int main() 
{
    Solution solution;
    std::string ex1 = "eceba";
    std::string ex2 = "aa";

    std::cout << "String: " << ex1 << " \tK:2" << std::endl;
    std::cout << "Longest substring with K distinct characters: \t" << solution.lengthOfLongestSubstringKDistinct(ex1, 2) << std::endl << std::endl;

    std::cout << "String: " << ex2 << " \tK:1" << std::endl;
    std::cout << "Longest substring with K distinct characters: \t" << solution.lengthOfLongestSubstringKDistinct(ex2, 1) << std::endl << std::endl;

    return (0);
}