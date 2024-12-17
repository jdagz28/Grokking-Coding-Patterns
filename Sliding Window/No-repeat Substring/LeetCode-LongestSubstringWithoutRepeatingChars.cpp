#include <iostream>
#include <string>
#include <unordered_map>

class Solution 
{
    public:
        int lengthOfLongestSubstring(std::string s) 
        {
            int windowStart = 0;
            int maxLength = 0;
            std::unordered_map<char, int> charIndexMap;

            for (size_t windowEnd = 0; windowEnd < s.length(); windowEnd++)
            {
                char rightChar = s[windowEnd];;
                
                if (charIndexMap.find(rightChar) != charIndexMap.end())
                    windowStart = std::max(windowStart, charIndexMap[rightChar] + 1);
                charIndexMap[rightChar] = windowEnd;
                maxLength = std::max(maxLength, static_cast<int>(windowEnd - windowStart + 1));
            }
            
            return (maxLength);
        }
};

int main()
{
    std::string str1 = "abcabcbb";
    std::string str2 = "bbbbb";
    std::string str3 = "pwwkew";
    Solution solution;

    std::cout << str1 << ": " << solution.lengthOfLongestSubstring(str1) << std::endl;
    std::cout << str2 << ": " << solution.lengthOfLongestSubstring(str2) << std::endl;
    std::cout << str3 << ": " << solution.lengthOfLongestSubstring(str3) << std::endl;

    return (0);
}