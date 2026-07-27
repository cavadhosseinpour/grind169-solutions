#include <iostream>
#include <unordered_map>

/**
 * @file RomanToInteger.cpp
 * @brief LeetCode 13: Roman to Integer Solution
 * 
 * PROBLEM DESCRIPTION:
 * Given a roman numeral string, convert it to its corresponding integer representation.
 * Input is guaranteed to be within the range 1 to 3999.
 * 
 * ALGORITHMIC INSIGHTS:
 * - Roman numerals are evaluated from left to right.
 * - If the value of the current symbol is less than the value of the next symbol,
 *   it indicates a subtractive combination (e.g., IV = 5 - 1 = 4).
 * - Otherwise, the value is additive.
 * - This implementation optimizes lookup time using a fast, branchless inline 
 *   mapping function instead of a heavy `std::unordered_map`.
 * 
 * COMPLEXITY ANALYSIS:
 * - Time Complexity: O(N)
 *   We iterate through the string of length N exactly once. The character-to-value 
 *   lookup runs in O(1) constant time.
 * - Space Complexity: O(1)
 *   No extra heap allocations or data structures scale with input size. Memory overhead 
 *   is strictly limited to a few primitive stack variables.
 */


class Solution {
public:
    // My solution
    int romanToInt_map(std::string& s)
    {
        std::unordered_map<char, int> roman_int_map =
        {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int s_length = s.length();
        int res = 0;

        for (int i = 0; i < s_length; ++i)
        {
            int curr = roman_int_map[s[i]];
            if (i + 1 < s_length)
            {
                int next = roman_int_map[s[i + 1]];
                if (curr < next)
                {
                    res -= curr;
                    continue;
                }
            }
            res += curr;
        }
        return res;
    }
    
    // Optimal solution
    int romanToInt(const std::string& romanString) {
        const int length = romanString.length();
        int totalIntegerResult = 0;

        for (int i = 0; i < length; ++i) {
            const int currentValue = getRomanValue(romanString[i]);

            // Safe boundary check: evaluate look-ahead only if a next character exists
            if (i + 1 < length) {
                const int nextValue = getRomanValue(romanString[i + 1]);

                if (currentValue < nextValue) {
                    totalIntegerResult -= currentValue; // Subtractive rule
                    continue;
                }
            }

            totalIntegerResult += currentValue; // Additive rule
        }

        return totalIntegerResult;
    }

private:
    /**
     * @brief Maps a valid Roman numeral character to its integer equivalent.
     * High-performance alternative to std::unordered_map.
     */
    static constexpr int getRomanValue(char numeral) noexcept {
        switch (numeral) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0; // Fallback for invalid characters
        }
    }
};

int main()
{
    std::string s = "MCMXCIV";
    Solution sol;
    std::cout << "The integer value is: " << sol.romanToInt_map(s) << std::endl;
    return 0;
}