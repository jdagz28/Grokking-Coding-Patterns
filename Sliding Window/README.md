# Sliding Window Pattern

The Sliding Window pattern is a technique often used for solving problems involving **arrays or linked lists** where it is needed to find or calculate something among all **contiguous subarrays** (or sublists) of a given size.

### Example Problem

**Problem Statement:**  
Given an array, find the average of all contiguous subarrays of size `K`.

**Example Input:**
- Array: `[1, 3, 2, 6, -1, 4, 1, 8, 2]`
- `K = 5`

**Steps:**
1. For the first 5 numbers (subarray indices 0–4), the average is:  
   \[(1 + 3 + 2 + 6 - 1) / 5 = 2.2\]
2. For the next subarray (indices 1–5), the average is:  
   \[(3 + 2 + 6 - 1 + 4) / 5 = 2.8\]
3. Continue similarly for all subarrays.

**Output:**  
\[2.2, 2.8, 2.4, 3.6, 2.8\]

---

## Brute Force Solution  
For each subarray of size `K`, calculate the sum and divide it by `K` to get the average.

```cpp
#include <iostream>
#include <vector>

class AverageOfSubarrayOfSizeK {
public:
    static std::vector<double> findAverages(int K, const std::vector<int>& arr)
    {
        std::vector<double> result;
        for (std::size_t i = 0; i <= arr.size() - K; i++) 
        {
            double sum = 0;
            for (std::size_t j = i; j < i + K; j++) 
                sum += arr[j];
            result.push_back(sum / K);
        }
        return (result);
    }
};

int main()
{
    std::vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int K = 5;
    std::vector<double> averages = AverageOfSubarrayOfSizeK::findAverages(K, arr);
    std::cout << "Averages of subarrays of size K: ";
    for (double avg : averages)
        std::cout << avg << " ";
    std::cout << std::endl;
    return (0);
}

```

#### Time Complexity
- $O(N \cdot K)$
  For each element of the array, we iterate through the next `K` elements.

---

## Sliding Window Solution

For **overlapping subarrays, most of the elements are the same**. Instead of recalculating the sum for each subarray, we can:
- **Subtract** the element that is **sliding out** of the window.
- **Add** the element that is **sliding into** the window.


The inefficiency arises because, for any two consecutive subarrays of size `5`, the overlapping portion (which contains four elements) is recalculated for each subarray.  
<div align="center">
    <img src="../images/Sliding Window/SlidingWindow-1.svg" alt="Sliding Window - Overlap" title="Sliding Window Overlap">
</div>

In order to address this inefficiency, we can think of each contiguous subarray as a sliding window of `5` elements. As the window slides forward by one element, we can reuse the previously calculated sum by subtracting the element that is leaving the window and adding the new element entering the window. 
<div align="center">
    <img src="../images/Sliding Window/SlidingWindow-2.svg" alt="Sliding Window - Overlap" title="Sliding Window Subtract -Adding">
</div>

This approach **eliminates the need to recompute the sum for overlapping elements**, significantly reducing the algorithm's time complexity to **O(N)**.


```cpp
#include <iostream>
#include <vector>

class AverageOfSubarrayOfSizeK 
{
    public:
        static std::vector<double> findAverages(int K, const std::vector<int>& arr)
        {
            std::vector<double> result(arr.size() - K + 1);
            double windowSum = 0;
            int windowStart = 0;

            for (std::size_t windowEnd = 0; windowEnd < arr.size(); windowEnd++) 
            {
                windowSum += arr[windowEnd]; // Add the next element

                // Check if we hit the required window size
                if (windowEnd >= static_cast<std::size_t>(K - 1)) 
                {
                    result[windowStart] = windowSum / K; // Calculate the average
                    windowSum -= arr[windowStart]; // Subtract the element going out
                    windowStart++; // Slide the window ahead
                }
            }
            return (result);
        }
};

int main()
{
    std::vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int K = 5;
    std::vector<double> averages = AverageOfSubarrayOfSizeK::findAverages(K, arr);
    std::cout << "Averages of subarrays of size K: ";
    for (double avg : averages)
        std::cout << avg << " ";
    std::cout << std::endl;
    return (0);
}
```

#### Time Complexity
- $O(N):$  
  We iterate through the array once.

#### Space Complexity
- $O(N):$
  For storing the result.

---

## When Window Size Is Dynamic

In some problems, the window size is not fixed. We may need to:
1. **Expand or shrink the window** dynamically.
2. Use **constraints to adjust the window size**.

We will explore such examples in subsequent chapters.

---
## Problems

| Index | Problem Name                                             | Link                                                               | LeetCode                                                                                   |
|-------|----------------------------------------------------------|--------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| 0     | Maximum Subarray                                         | [Link](./Maximum%20Sum%20Subarray%20of%20Size%20K/)               | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)                              |
| 1     | Smallest Subarray with a Given Sum Sum                   | [Link](./Smallest%20Subarray%20with%20a%20Given%20Sum)            | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)        |
| 2     | Longest Substring with At Most K Distinct Characters      |                                                                    | [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) |
| 3     | Fruit Into Baskets                                       |                                                                    | [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)                          |
| 4     | Longest Substring Without Repeating Characters           |                                                                    | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)        |
| 5     | Longest Repeating Character Replacement                  |                                                                    | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)                      |
| 6     | Max Consecutive Ones III                                 |                                                                    | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)              |
| 7     | Permutation in String                                    |                                                                    | [Permutation in String](https://leetcode.com/problems/permutation-in-string/)                   |
| 8     | Find All Anagrams in a String                            |                                                                    | [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)    |
| 9     | Minimum Window Substring                                 |                                                                    | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)              |
| 10    | Substring with Concatenation of All Words                |                                                                    | [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)                  |
