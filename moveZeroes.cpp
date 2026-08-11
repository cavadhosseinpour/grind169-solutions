#include <vector>
#include <utility>
#include <iostream>

/**
 * @file move_zeroes.cpp
 * @brief LeetCode 283: Move Zeroes
 * 
 * @details
 * Problem Description:
 * Given an integer array 'nums', move all 0's to the end of it while maintaining 
 * the relative order of the non-zero elements. The operation must be performed 
 * in-place without making a copy of the array.
 * 
 * Foundational Algorithmic Insights:
 * This solution utilizes the Two-Pointer technique (Read/Write Head model) to 
 * achieve stable partitioning in linear time. 
 * - The 'explorer' pointer scans ahead to find non-zero elements.
 * - The 'write_index' pointer tracks the boundary where the next non-zero 
 *   element belongs.
 * By swapping elements only when a non-zero value is encountered, the zeros 
 * naturally bubble to the right side of the write boundary without requiring 
 * secondary passes or nested loops.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n)
 *   Each element is visited at most twice (once by the explorer pointer, and 
 *   potentially swapped once). This guarantees linear execution time regardless 
 *   of zero-density.
 * - Space Complexity: O(1)
 *   The partitioning is performed completely in-place using a couple of 
 *   integer pointers. No auxiliary data structures are allocated.
 */

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        int left = 0;
        int right = 0;

        while (right < nums.size())
        {
            if (nums[right] != 0)
            {
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                left++;
            }
            right++;
        }
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
}


/*

class Solution 
{
public:
    void moveZeroes(std::vector<int>& nums) 
    {
        int write_index = 0;

        // The explorer pointer acts as the fast read head scanning the input space
        for (int explorer = 0; explorer < nums.size(); ++explorer) 
        {
            if (nums[explorer] != 0) 
            {
                // Optimization: Avoid redundant self-swapping if no zeros have been met yet
                if (explorer != write_index) 
                {
                    std::swap(nums[write_index], nums[explorer]);
                }
                
                // Advance the write boundary for the next valid non-zero element
                write_index++;
            }
        }
    }
};

*/