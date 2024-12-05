# Fruits into Baskets

Given an array of characters where each character represents a fruit tree, **you are given two baskets** and your goal is to put m**aximum number of fruits in each basket.** The only restriction is that **each basket can have only one type of fruit.**

You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

Write a function to return the maximum number of fruits in both the baskets.

#### Example 1
```
Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']
```

#### Example 2
```
Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket. 
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']
```

### Solution Approach
The problem is similar to **[Longest Substring with K Distinct Characters](../Longest%20Substring%20with%20K%20Distinct%20Characters/README.md)**. In this problem, we need to find the length of the longest subarray with no more than two distinct characters (or fruit types). This transforms the current problem into **Longest Substring with K Distinct characters where K=2.**

```cpp
class MaxFruitCountOf2Types
{
    public:
        int findLength(const std::vector<char> &arr)
        {
            int maxLength = 0;
            int windowStart = 0;
            std::unordered_map<char, int> fruitFrequencyMap;

            // try to extend the range [windowStart, windowEnd]
            for (size_t windowEnd = 0; windowEnd < arr.size(); windowEnd++)
            {
                char rightFruit = arr[windowEnd];
                fruitFrequencyMap[rightFruit]++;

                // shrink the sliding window, until we are left with '2' fruits in the fruitFrequencyMap
                while (static_cast<int>(fruitFrequencyMap.size()) > 2)
                {
                    char leftFruit = arr[windowStart];
                    fruitFrequencyMap[leftFruit]--;
                    if (fruitFrequencyMap[leftFruit] == 0)
                        fruitFrequencyMap.erase(leftFruit);
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
$O(1)$ - runs in constant space. Maximum of three types of fruits stored in the frequency map.

---
## Leetcode - Fruit Into Baskets
https://leetcode.com/problems/fruit-into-baskets/

You are visiting a farm that has a single row of `fruit` trees arranged from left to right. The trees are represented by an integer array fruits where `fruits[i]` is the type of fruit the `iᵗʰ` tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
- You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array `fruits`, return the maximum number of fruits you can pick.

#### Examples
```
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
```

#### Constraints
- 1 ≤ fruits.length ≤ 10⁵
- 0 ≤ fruits[i] < fruits.length

**Solution above does not pass in leetcode without a few modifications (passed 87/91 tests)**