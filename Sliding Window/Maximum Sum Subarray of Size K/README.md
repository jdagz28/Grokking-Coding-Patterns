# Maximum Sum Subarray of Size K

Given an array of positive numbers and a positive number ‘k’, find the **maximum sum of any contiguous subarray of size ‘k’.**

#### Example 1
```
Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
```

#### Example 2
```
Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].
```

---
## Brute Force Solution
- calculate the sum of all ‘k’ sized subarrays of the given array, to find the subarray with the highest sum.

```cpp
#include <iostream>
#include <vector>

int findMaxSumSubArray(int k, const std::vector<int> &arr)
{
    int maxSum = 0;
    for (size_t i = 0; i <= arr.size() - k; i++)
    {
        int arrSum = 0;
        for (size_t j = i; j < i + k; j++)
            arrSum += arr[j];
        maxSum = std::max(maxSum, arrSum);
    }
    return (maxSum);
}

void printArray(const std::vector<int> &arr)
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
    std::vector<int> ex1 = {2, 1, 5, 1, 3, 2};
    std::vector<int> ex2 = {2, 3, 4, 1, 5};
    
    printArray(ex1);
    std::cout << "Maximum sum of a subarray of size 3: "; 
    std::cout << findMaxSumSubArray(3, ex1) << std::endl << std::endl;

    printArray(ex2);
    std::cout << "Maximum sum of a subarray of size 2: "; 
    std::cout << findMaxSumSubArray(2, ex2) << std::endl;
    return (0);
}
```

#### Time Complexity
$O(N \cdot K)$

---
## Sliding Window Solution
- consider each subarray as a **sliding window** of size 'k'.
  - Subtract the element going out of the sliding windows (first element).
  - Add the new element getting included in the sliding window (element after the end of the window)

```cpp
#include <iostream>
#include <vector>

int findMaxSumSubArray(int k, const std::vector<int> &arr)
{
    int maxSum = 0;
    int windowStart = 0;
    int windowSum = 0;

    for (size_t windowEnd = 0; windowEnd < arr.size(); windowEnd++)
    {
        windowSum += arr[windowEnd];
        if (static_cast<int>(windowEnd) >= k - 1)
        {
            maxSum = std::max(maxSum, windowSum);
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }
    return (maxSum);
}

void printArray(const std::vector<int> &arr)
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
    std::vector<int> ex1 = {2, 1, 5, 1, 3, 2};
    std::vector<int> ex2 = {2, 3, 4, 1, 5};
    
    printArray(ex1);
    std::cout << "Maximum sum of a subarray of size 3: "; 
    std::cout << findMaxSumSubArray(3, ex1) << std::endl << std::endl;

    printArray(ex2);
    std::cout << "Maximum sum of a subarray of size 2: "; 
    std::cout << findMaxSumSubArray(2, ex2) << std::endl;
    return (0);
}
```

#### Time Complexity
$O(N)$

#### Space Complexity
$O(1)$

---
## LeetCode - Maximum Subarray
https://leetcode.com/problems/maximum-subarray/

Given an integer array `nums`, find the **subarray** with the largest sum, and return its sum.

#### Examples:
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4] 
Output: 6  
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Input: nums = [1]  
Output: 1  
Explanation: The subarray [1] has the largest sum 1.

Input: nums = [5,4,-1,7,8]  
Output: 23  
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

#### Constraints:

- \(1 \leq \text{nums.length} \leq 10^5\)
- \(-10^4 \leq \text{nums[i]} \leq 10^4\)

**The sliding window algorithm is not optimal for this problem given that subarray sizes are not given.**

```cpp
#include <iostream>
#include <vector>
#include <climits>

class Solution 
{
    public:
        int maxSubArray(std::vector<int>& nums)
        {
            int maxSum = INT_MIN;
            int windowSum = 0;

            for (size_t windowEnd = 0; windowEnd < nums.size(); ++windowEnd)
            {
                windowSum += nums[windowEnd];
                maxSum = std::max(maxSum, windowSum);
                if (windowSum < 0) 
                    windowSum = 0;
            }
            return (maxSum);
        }
};

int main()
{
    Solution solution;

    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]" << std::endl;
    std::cout << "Output: " << solution.maxSubArray(nums1) << std::endl << std::endl; 

    std::vector<int> nums2 = {1};
    std::cout << "Input: nums = [1]" << std::endl;
    std::cout << "Output: " << solution.maxSubArray(nums2) << std::endl << std::endl; 

    std::vector<int> nums3 = {5, 4, -1, 7, 8};
    std::cout << "Input: nums = [5, 4, -1, 7, 8]" << std::endl;
    std::cout << "Output: " << solution.maxSubArray(nums3) << std::endl << std::endl; 

    return (0);
}
```