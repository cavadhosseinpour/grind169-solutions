#include <vector>
#include <unordered_set>
#include <iostream>

/**
 * @file contains_duplicate.cpp
 * @brief LeetCode 217 - Contains Duplicate
 * 
 * @details
 * Given an integer array 'nums', return true if any value appears at least 
 * twice in the array, and return false if every element is distinct.
 * 
 * Foundational Algorithmic Insights:
 * The algorithm utilizes a hash set to achieve linear time lookup. By tracking
 * visited elements in a hash-based data structure, we can verify whether an 
 * element has been seen before in O(1) average time complexity. This bypasses 
 * the need for nested loops or sorting.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n)
 *   We iterate through the array of length 'n' exactly once. Each lookup and 
 *   insertion operation in a std::unordered_set takes O(1) time on average.
 * - Space Complexity: O(n)
 *   In the worst-case scenario where all elements are unique, the hash set 
 *   will store all 'n' elements, consuming linear auxiliary space.
 */

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> my_set;
        my_set.reserve(nums.size());
        for (const int num : nums)
        {
            // if (my_set.count(num) > 0)
            /*
            Instead of searching the set and then inserting, you can do both in one step.
            std::unordered_set::insert() returns a std::pair.
            The second value in that pair (pair.second) is a boolean that tells you
            if the insertion was successful (true) or if the element already existed (false).
            */
            if (!my_set.insert(num).second)
            {
                return true;
            }
            // my_set.insert(num);
        }
        return false;
    }
};

int main()
{
    std::vector<int> nums {1,1,1,3,3,4,3,2,4,2};
    Solution sol;
    std::cout << (sol.containsDuplicate(nums) ? "The array has duplicates!" : "The array does NOT have duplicates!") << std::endl;
}