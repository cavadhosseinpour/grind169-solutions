#include <iostream>
#include <cstdint>

class Solution
{
public:
    /**
     * @brief Reverses the bits of a given 32-bit unsigned integer.
     * 
     * Foundational Algorithmic Insights:
     * - The algorithm processes the input integer bit by bit from right to left.
     * - In each iteration, the result accumulator is shifted left to make room
     *   for the next bit.
     * - The least significant bit (LSB) of the input is extracted using a bitwise
     *   AND operation (n & 1) and combined with the result using a bitwise OR.
     * - The input integer is then shifted right to process the next bit.
     * - Executing the loop exactly 32 times ensures all leading and trailing zeros
     *   are correctly mirrored.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(1). The loop always runs exactly 32 times, regardless
     *   of the input value.
     * - Space Complexity: O(1). Only a few fixed-size registers/variables are
     *   used to store the result and loop counter.
     */
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t reversedResult = 0;
        const int totalBits = 32;

        for (int i = 0; i < totalBits; ++i)
        {
            // Shift result left to make room, then inject the lowest bit of n
            reversedResult = (reversedResult << 1) | (n & 1);
            
            // Shift n right to prepare the next bit
            n >>= 1;
        }

        return reversedResult;
    }
};

int main()
{
    uint32_t n = 43261596;
    Solution sol;
    std::cout << "Reversing bits makes it: " << sol.reverseBits(n) << std::endl;
}