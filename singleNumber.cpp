#include <vector>
#include <iostream>

class Solution {
public:
    /**
     * @brief Finds the single element in an array where every other element appears twice.
     * 
     * Algorithmic Insights:
     * This solution utilizes the bitwise XOR (^) operator. XORing a number by itself
     * results in 0 (A ^ A = 0), and XORing any number with 0 retains its value (A ^ 0 = A).
     * Because XOR is commutative and associative, the order of elements does not matter.
     * All duplicate pairs will cancel each other out to 0, leaving only the unique single number.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(N) where N is the number of elements in the input vector.
     *   We iterate through the array exactly once.
     * - Space Complexity: O(1) auxiliary space.
     *   Only a single integer variable is used to accumulate the XOR state.
     */
    int singleNumber(const std::vector<int>& nums)
    {
        int unique_accumulator = 0;

        for (const int current_number : nums)
        {
            unique_accumulator ^= current_number;
        }

        return unique_accumulator;
    }
};

int main()
{
    std::vector<int> nums = {4,1,2,1,2};
    Solution sol;
    std::cout << "The single number is: " << sol.singleNumber(nums) << std::endl;
}
