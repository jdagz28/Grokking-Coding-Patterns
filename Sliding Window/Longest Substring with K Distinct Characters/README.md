# Longest Substring with K Distinct Characters

Given a string, find the length of the **longest substring** in it **with no more than K distinct characters.**

#### Example 1
```
Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
```

#### Example 2
```
Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".
```

#### Example 3
```
Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
```

### Solution Approach
1. **Initialize the Sliding Window**:
    - Start with an empty sliding window and an empty HashMap to track the frequency of each character.
    - Gradually add characters from the beginning of the string into the window until you have `K` distinct characters in the HashMap.


2. **Track the Smallest Window**:
    - Once you have `K` distinct characters, record the length of this window as the longest found so far.

3. **Slide the Window Forward**:
    - Continue processing the string by adding one character at a time to the sliding window.
    - After each addition:
        - Extend the window by including the next character.
        - Check if the number of distinct characters in the HashMap exceeds `K`.

4. **Shrink the Window to Optimize**:
    - If there are more than `K` distinct characters, shrink the window from the left:
    - For every step of shrinking:
        - Decrement the frequency of the character going out of the window.
        - If a character's frequency becomes zero, remove it from the HashMap.
        - Check if you still have no more than `K` distinct characters.
    - After shrinking, compare the current window's length to the longest recorded length so far, and update it if the current one is longer.

5. **Repeat the Process**:
   - Continue extending and shrinking the window across the entire string, always striving to maintain and record the longest valid window.

<div align="center">
    <img src="../../images/Sliding Window/LongestSubstring.svg" alt="Longest Substring K Distinct Chars Solution Approach" title="SLongest Substring K Distinct Chars Solution Approach">
</div>

```cpp
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
```
#### Time Complexity
$O(N)$
- outer `for` loop runs for all characters and the inner `while` loop processes each character **only once** -- therefore time complexity of the algorithm will be $O(N + N)$ which is asymptotically equivalent to $O(N)$.

#### Space Complexity
$O(K)$ - storing a maximum of K + 1 in the HashMap

---
# Leetcode - Longest Substring with At Most K Distinct Characters
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/ (Premium locked)


Given a string `s` and an integer `k`, return *the length of the longest substring of s that contains at **most k distinct characters**.*

#### Examples
```
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
```

#### Constraints

Here’s the updated formatting to match your example:

markdown
Copy code
- 1 ≤ s.length ≤ 5 × 10⁴  
- 0 ≤ k ≤ 50


```cpp
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
```