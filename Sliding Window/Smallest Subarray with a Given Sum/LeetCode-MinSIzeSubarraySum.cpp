#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Solution 
{
   public:
      int minSubArrayLen(int target, std::vector<int>& nums)
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

int main()
{
    Solution solution;

    // Example 1
    int target1 = 7;
    std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    std::cout << "Example 1:" << std::endl;
    std::cout << "Input: target = " << target1 << ", nums = [2, 3, 1, 2, 4, 3]" << std::endl;
    std::cout << "Output: " << solution.minSubArrayLen(target1, nums1) << std::endl << std::endl;

    // Example 2
    int target2 = 4;
    std::vector<int> nums2 = {1, 4, 4};
    std::cout << "Example 2:" << std::endl;
    std::cout << "Input: target = " << target2 << ", nums = [1, 4, 4]" << std::endl;
    std::cout << "Output: " << solution.minSubArrayLen(target2, nums2) << std::endl << std::endl;

    // Example 3
    int target3 = 11;
    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "Example 3:" << std::endl;
    std::cout << "Input: target = " << target3 << ", nums = [1, 1, 1, 1, 1, 1, 1, 1]" << std::endl;
    std::cout << "Output: " << solution.minSubArrayLen(target3, nums3) << std::endl << std::endl;

    return (0);
}