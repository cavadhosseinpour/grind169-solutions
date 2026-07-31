#include <cstdint>
#include <iostream>

class Solution {
public:
    /**
     * @brief Calculates the Hamming weight (number of 1 bits) of an unsigned 32-bit integer.
     * 
     * Algorithmic Insights:
     * - Uses Brian Kernighan's Algorithm to isolate and clear the lowest set bit iteratively.
     * - The expression `n & (n - 1)` flips the rightmost '1' bit to '0' and sets all subsequent 
     *   trailing '0' bits to '1'. Anding this result with the original 'n' effectively eliminates
     *   the rightmost '1' bit.
     * - This transforms the execution time to be directly proportional to the number of set bits 
     *   rather than the total bit-width of the data type.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(k), where k is the number of 1 bits present in the integer (k <= 32).
     *   In the worst case (all bits set), it takes 32 iterations.
     * - Space Complexity: O(1). The iterative approach utilizes a single counter variable,
     *   eliminating the O(k) call-stack overhead of the recursive approach.
     */
    int hammingWeight(uint32_t n)
    {
        int setBitCounter = 0;

        while (n > 0)
        {
            n &= (n - 1);
            setBitCounter++;
        }

        return setBitCounter;
    }

    int hammingWeight_recursive(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return hammingWeight((n & (n - 1))) + 1;
        // return hammingWeight(n >> 1) + (n & 1);
    }
};

int main()
{
    Solution sol;
    uint32_t n = 2147483645;
    std::cout << "Number of 1 Bits of " << n << ": " << sol.hammingWeight(n) << std::endl;
    std::cout << "Number of 1 Bits of " << n << ": " << sol.hammingWeight_recursive(n) << std::endl;
}
