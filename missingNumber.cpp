#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    /**
     * @brief Solution 1: Arithmetic Summation (Gauss's Formula)
     * 
     * Description:
     * Calculates the expected sum of a contiguous sequence from 0 to N using 
     * the arithmetic progression formula, then subtracts all actual numbers.
     * The remaining value is the missing number.
     * 
     * Algorithmic Insights:
     * Uses 64-bit integers (`long long`) to prevent overflow bugs during the
     * N * (N + 1) multiplication phase when N is exceptionally large.
     * 
     * Complexity:
     * - Time Complexity: O(N) -> Requires a single linear pass over the array.
     * - Space Complexity: O(1) -> Uses fixed scalar variables for tracking sums.
     */
    int missingNumberArithmetic(const std::vector<int>& nums)
    {
        long long nums_size = nums.size();
        long long sum = (nums_size * (nums_size + 1)) / 2;

        for (int i = 0; i < nums_size; ++i)
        {
            sum -= nums[i];
        }
        return static_cast<int>(sum);
    }

    /**
     * @brief Solution 2: Bitwise XOR Manipulation
     * 
     * Description:
     * Leverages the properties of the XOR bitwise operator (X ^ X = 0 and X ^ 0 = X)
     * to eliminate paired values across the sequence range.
     * 
     * Algorithmic Insights:
     * By XORing all index positions [0...N] alongside all actual values in the array,
     * every present number appears exactly twice and evaluates to zero. 
     * The missing number appears only once and is preserved. Immune to overflow.
     * 
     * Complexity:
     * - Time Complexity: O(N) -> Single linear traversal of array elements and indices.
     * - Space Complexity: O(1) -> Only allocates a single bitwise accumulator.
     */
    int missingNumberXOR(const std::vector<int>& nums)
    {
        int nums_size = nums.size();
        int res = nums_size;

        for (int i = 0; i < nums_size; ++i)
        {
            res ^= i ^ nums[i];
        }
        return res;
    }

    /**
     * @brief Solution 3: In-Place Cyclic Sort
     * 
     * Description:
     * Organizes the elements by treating array values as destination target indices.
     * Attempts to place every value X at index X.
     * 
     * Algorithmic Insights:
     * Ignores the out-of-bounds value N during sorting. A subsequent validation 
     * pass finds the mismatched index position, identifying the missing element.
     * 
     * Complexity:
     * - Time Complexity: O(N) -> Even with nested logic, each item is placed into 
     *   its correct slot at most once. Amortized loop operations never exceed 2N steps.
     * - Space Complexity: O(1) -> Mutates the input structure directly without safety allocations.
     */
    int missingNumberCyclicSort(std::vector<int>& nums)
    {
        int nums_size = nums.size();
        int j = 0;

        while (j < nums_size)
        {
            // Check if the current value is within index bounds and out of place
            if (nums[j] < nums_size && nums[j] != j)
            {
                int temp = nums[j];
                // std::swap(nums[j], nums[temp]);
                nums[j] = nums[nums[j]];
                nums[temp] = temp;
            }
            else
            {
                ++j;
            }
        }

        // Search for the mismatched element position
        for (int i = 0; i < nums_size; ++i)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }

        return nums_size;
    }
};

int main()
{
    std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution sol;
    std::cout << "The missing number is: " << sol.missingNumberArithmetic(nums) << std::endl;
    std::cout << "The missing number is: " << sol.missingNumberXOR(nums) << std::endl;
    std::cout << "The missing number is: " << sol.missingNumberCyclicSort(nums) << std::endl;
}
