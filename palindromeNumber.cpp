#include <iostream>

class Solution
{
public:
    /**
     * @brief LeetCode 9: Palindrome Number
     * 
     * Problem Description:
     * Given an integer x, return true if x is a palindrome integer. An integer 
     * is a palindrome when it reads the same backward as forward.
     * 
     * Foundational Algorithmic Insights:
     * - Negative numbers are never palindromes due to the leading minus sign.
     * - Numbers ending in 0 (except 0 itself) cannot be palindromes.
     * - Instead of reversing the entire integer—which risks 32-bit overflow—
     *   we reverse only the back half of the digits. 
     * - We reach the middle when the remaining front half of the number 
     *   becomes smaller than or equal to the growing reversed back half.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(log10(N))
     *   We divide the input number by 10 in every iteration. The loop runs 
     *   exactly through half the total number of digits.
     * - Space Complexity: O(1)
     *   Utilizes a constant amount of extra memory space. Avoids string conversion.
     */
    bool isPalindrome(int x)
    {
        // Edge Case 1: Negative numbers are not palindromes.
        // Edge Case 2: Non-zero numbers ending in 0 are not palindromes.
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int num = x;
        int b = 0;

        // Strip digits from the back and append to the reversed variable.
        // Stop when we reach or pass the halfway point of the digits.
        while (num > b)
        {
            b = (b * 10) + (num % 10);
            num /= 10;
        }

        // For even lengths: remainingFrontHalf == reversedBackHalf (e.g., 12 == 12)
        // For odd lengths: remainingFrontHalf == reversedBackHalf / 10 (e.g., 12 == 123 / 10)
        return num == b || num == (b / 10);
    }
};

int main()
{
    Solution sol;
    std::cout << (sol.isPalindrome(1221) ? "Palindrome Number!" : "Not a Palindrome Number!") << std::endl;
}