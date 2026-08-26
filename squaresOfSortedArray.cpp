#include <vector>
#include <cmath>
#include <iostream>

/**
 * ============================================================================
 * Problem: LeetCode 977 - Squares of a Sorted Array
 * Link:    https://leetcode.com
 * ============================================================================
 * 
 * ALGORITHMIC INSIGHT:
 * - The input array is pre-sorted, meaning absolute values (and thus squared 
 *   magnitudes) peak at the two outer boundaries and decrease toward the center.
 * - Utilizing a two-pointer approach from the outermost elements inwards allows
 *   identifying the maximal remaining squared value in O(1) time per iteration.
 * - Populating the result buffer from the last index (n - 1) down to 0 guarantees
 *   a non-decreasing sorted order in a single pass without extra sorting passes.
 * 
 * COMPLEXITY ANALYSIS:
 * - Time Complexity:  O(n)
 *   Each element is inspected and placed exactly once as the two pointers 
 *   converge over n iterations.
 * 
 * - Space Complexity: O(1) auxiliary (O(n) output space)
 *   The output vector of size n is required by the problem contract; no 
 *   additional auxiliary memory proportional to n is allocated.
 * ============================================================================
 */

 class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int>& nums)
    {
        int nums_size = nums.size();
        std::vector<int> res(nums_size);

        int left = 0;
        int right = nums_size - 1;
        int i = nums_size - 1;
        while (left <= right)
        {
            const int left_sq = nums[left] * nums[left];
            const int right_sq = nums[right] * nums[right];

            if (left_sq > right_sq)
            {
                res[i] = left_sq;
                ++left;
            }
            else
            {
                res[i] = right_sq;
                --right;
            }
            --i;
        }
        return res;
    }
};

int main()
{
    std::vector<int> nums = {-7,-3,2,3,11};
    Solution sol;
    std::vector<int> res = sol.sortedSquares(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << res[i] << ", ";
    }
    std::cout << std::endl;
}