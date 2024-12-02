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