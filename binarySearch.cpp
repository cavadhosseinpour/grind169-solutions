#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }

    /*
    Leetcode 875. Koko eating bananas
    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
    The guards have gone and will come back in h hours.
    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.
    If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
    Return the minimum integer k such that she can eat all the bananas within h hours.
    */
    int searchKoko(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0) return -1;

        int left = 1;
        int right = std::ranges::max(nums);
        int mid = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            long long total_hours = 0;
            for (int num : nums)
            {
                total_hours += (num + mid - 1) / mid;
            }

            if (total_hours <= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return mid;
    }

    /*
    2529. Maximum Count of Positive Integer and Negative Integer
    Given an array nums sorted in non-decreasing order,
    return the maximum between the number of positive integers and the number of negative integers.
    In other words, if the number of positive integers in nums is pos and the number of negative integers is neg,
    then return the maximum of pos and neg.
    Note that 0 is neither positive nor negative.
    My note: you are essentially looking for where the boundary of 0 is twice separately,
    to see where the index of first negative or positive element in the middle is, ignoring 0 values.
    */

    int maximumCount(std::vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        int left = 0;
        int right = nums.size() - 1;
        int neg = 0, pos = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0)
            {
                neg = mid + 1;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        left = 0;
        right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0)
            {
                right = mid - 1;
                pos = nums.size() - mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return (pos > neg) ? pos : neg;
    }
};

int main()
{
    std::vector<int> nums {-1, 0, 3, 5, 9, 12};
    int target = 2;
    Solution sol;
    std::cout << "The result is: " << sol.search(nums, target) << std::endl;
    std::vector<int> bananas {3, 6, 7, 11};
    std::cout << "The minimum speed Koko can eat bananas is: " << sol.searchKoko(bananas, 8) << std::endl;
    std::cout << "The maximum between pos int vs neg int is: " << sol.maximumCount(nums) << std::endl;
    return 0;
}