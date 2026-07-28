#include <iostream>
#include <vector>

/**
 * @file CountingBits.cpp
 * @brief Solution for LeetCode 338: Counting Bits.
 *
 * Problem Description:
 * Given an integer n, return an array ans of length n + 1 such that for each i 
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 *
 * Foundational Algorithmic Insights:
 * 1. Method 1 (LSB Shift): The bit count of an integer `i` is equal to the bit 
 *    count of `i / 2` plus 1 if `i` is odd, or 0 if `i` is even.
 * 2. Method 2 (Pop Lowest Set Bit): Dropping the lowest set bit using `i & (i - 1)` 
 *    results in a smaller integer whose bit count is already calculated. Adding 1 
 *    yields the correct bit count for `i`.
 * 3. Method 3 (Non-Bitwise Math Recurrence): Emulates the LSB Shift using standard 
 *    arithmetic operations (`i / 2` and `i % 2`).
 *
 * Complexity Analysis (All Methods):
 * - Time Complexity: O(n) - We iterate from 1 to n exactly once. Each state transition 
 *   takes O(1) constant time.
 * - Space Complexity: O(1) auxiliary space (O(n) total space to store the output vector).
 */

 class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> ans(n + 1, 0);
        for (int i = 1; i < n + 1; ++i)
        {
            // --- METHOD 1: Dynamic Programming via Least Significant Bit (LSB) Shift ---
            // i >> 1 divides by 2; i & 1 isolates the last bit (odd/even check)

            //ans[i] = ans[(i >> 1)] + (i & 1);

            // --- METHOD 2: Dynamic Programming via Clearing Lowest Set Bit ---
            // i & (i - 1) removes the lowest set bit of i
            
            ans[i] = ans[i & (i - 1)] + 1;


            // --- METHOD 3: Dynamic Programming via Pure Math (Non-Bitwise Operations) ---
            // i / 2 replaces the right shift; i % 2 replaces the bitwise AND
            
            // ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }
};

int main()
{
    int n = 16;
    Solution sol;
    std::vector<int> ans = sol.countBits(n);
    for (int i = 0; i < ans.size(); ++i)
    {
        std::cout << ans[i] << ", ";
    }
    std::cout << std::endl;
}