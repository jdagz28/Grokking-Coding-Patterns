# No-repeat Substring

Given a string, find the **length of the longest substring which has no repeating characters.**


#### Example 1
```
Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".
```

#### Example 2
```
Input: String="abbbb"
Output: 2
Explanation: The longest substring without any repeating characters is "ab".
```

#### Example 3
```
Input: String="abccde"
Output: 3
Explanation: Longest substrings without any repeating characters are "abc" & "cde".
```

### Solution Approach
This problem follows the **sliding window pattern** and can be solved with the same **dynamic sliding window strategy** approach discussed in [Longest Substring with K Disting Characters](../Longest%20Substring%20with%20K%20Distinct%20Characters/README.md).
- a **HashMap** to remember the last index of each character that have been processed.
- whenever a repeating character is encountered, the sliding window is shrinked to ensure that the sliding window always have distinct characters.


```cpp
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
```

#### Time Complexity
$O(N)$ where `N` is the number of characters in the input string.

#### Space Complexity
$O(K)$ where `K` is the number of distinct characters in the input string.
- This also means $K <= N$ - **in the worst case**, the whole string might not have any repeating character so the entire string will be added to the HashMap.

---
# Leetcode - Longest Substring Without Repeating Characters
Given a string `s`, find the length of the longest substring without repeating characters.

#### Examples
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```