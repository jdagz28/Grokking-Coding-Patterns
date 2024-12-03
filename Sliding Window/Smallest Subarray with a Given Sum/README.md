# Smallest Subarray with a Given Sum

Given an array of positive numbers and a positive number ‘S’, find the length of the **smallest contiguous subarray whose sum is greater than or equal to ‘S’.** Return 0, if no such subarray exists.

#### Example 1
```
Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].
```

#### Example 2
```
Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
```

#### Example 3
```
Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].
```

### Solution Approach
1. **Initialize the Sliding Window**:
   - Start with an empty sliding window and a running sum of zero.
   - Gradually add elements from the beginning of the array into the window until the sum of the window becomes greater than or equal to `S`.

2. **Track the Smallest Window**:
   - As soon as the sum of the sliding window meets or exceeds `S`, record the length of this window as the smallest found so far.

3. **Slide the Window Forward**:
   - Continue processing the array by adding one element at a time to the sliding window.
   - After each addition:
     - Extend the window by including the next element.
     - Reassess if the current window's sum is greater than or equal to `S`.

4. **Shrink the Window to Optimize**:
   - After extending the window, check if it can be shrunk from the left while still maintaining a sum greater than or equal to `S`. This step is crucial for finding the smallest window:
     - For every step of shrinking:
       - Compare the current window's length to the smallest recorded length so far, and update the smallest length if the current one is shorter.
       - Adjust the running sum by removing the leftmost element of the window during each shrinking step.

5. **Repeat the Process**:
   - Continue extending and shrinking the window across the entire array, always striving to maintain the smallest valid window.

<div align="center">
    <img src="../../images/Sliding Window/SmallestSubarray.svg" alt="Smallest Subarray Solution Approach" title="Smallest Subarray Solution Approach">
</div>

```cpp

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

```

#### Time Complexity
$O(N)$
- outer `for` loop runs for all elements and the inner `while` loop processes each element **only once** -- therefore time complexity of the algorithm will be $O(N + N)$ which is asymptotically equivalent to $O(N)$.

#### Space Complexity
$O(1)$ - algorithm runs in constant space.


---
## Leetcode - Minimum Size Subarray Sum
https://leetcode.com/problems/minimum-size-subarray-sum/description/

Given an array of positive integers `nums` and a positive integer `target`, **return the minimal length of a subarray whose sum is greater than or equal to `target`**. If there is no such subarray, return `0` instead.

#### Examples:
```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Input: target = 4, nums = [1,4,4]
Output: 1

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

#### Constraints
- 1 ≤ target ≤ 10⁹
- 1 ≤ nums.length ≤ 10⁵
- 1 ≤ nums[i] ≤ 10⁴

```cpp
class Solution 
{
   public:
      int minSubArrayLen(int target, vector<int>& nums)
      {
         int windowSum = 0;
         int minLen = std::numeric_limits<int>::max();
         int windowStart = 0;

         for (size_t windowEnd = 0; windowEnd < nums.size(); windowEnd++)
         {
               windowSum += nums[windowEnd];
               while (windowSum >= target)
               {
                  minLen = std::min(minLen, static_cast<int>(windowEnd - windowStart + 1));
                  windowSum -= nums[windowStart];
                  windowStart++;
               }
         }
         return (minLen == std::numeric_limits<int>::max() ? 0 : minLen);
      }
};
```
