#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatingSubstring
{
    public:
        int findLength(const std::string &str)
        {
            int windowStart = 0;
            int maxLength = 0;
            std::unordered_map<char, int> charIndexMap;

            // Expand the sliding window by iterating through the string [windowStart, windowEnd]
            for (size_t windowEnd = 0; windowEnd < str.length(); windowEnd++)
            {
                char rightChar = str[windowEnd];

                // If the current character already exists in the map, it means we have a duplicate.
                // Move the start of the window to ensure there are no duplicates.
                if (charIndexMap.find(rightChar) != charIndexMap.end())
                {
                    // Update 'windowStart' to the index after the last occurrence of 'rightChar',
                    // but ensure it doesn't move backward (use max to keep it at or ahead of its current position).
                    windowStart = std::max(windowStart, charIndexMap[rightChar] + 1);
                }
                charIndexMap[rightChar] = windowEnd; // Update or insert the current character's index in the map
                maxLength = std::max(maxLength, static_cast<int>(windowEnd - windowStart + 1)); // Remember the maximum length so far
            }
            return (maxLength);
        }
};

int main()
{
    std::string str1 = "aabccbb";
    std::string str2 = "abbbb";
    std::string str3 = "abccde";
    NoRepeatingSubstring solution;

    std::cout << str1 << ": " << solution.findLength(str1) << std::endl;
    std::cout << str2 << ": " << solution.findLength(str2) << std::endl;
    std::cout << str3 << ": " << solution.findLength(str3) << std::endl;

    return (0);
}