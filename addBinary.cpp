/**
 * @file AddBinary.cpp
 * @brief LeetCode 67 - Add Binary
 *
 * @section description Problem Description
 * Given two binary strings a and b, return their sum as a binary string. The 
 * inputs can be exceptionally long, requiring arbitrary-precision arithmetic.
 *
 * @section insights Algorithmic Insights
 * 1. Two-Pointer Traversal: Simulates manual addition by walking right-to-left
 *    using independent indices for each string to handle length mismatches.
 * 2. Virtual Padding: Safely defaults exhausted string pointers to 0 math values
 *    instead of physically padding the inputs, avoiding unnecessary allocations.
 * 3. Linear Appending Optimization: Characters are appended to the rear of the 
 *    result string to avoid O(N) allocation shifting costs during loop execution. 
 *    The result is reversed at the end in a single linear pass.
 *
 * @section complexity Complexity Analysis
 * - Time Complexity: O(max(N, M)), where N and M are the lengths of strings a 
 *   and b. We iterate exactly once through the longest string. Reversing takes O(max(N, M)).
 * - Space Complexity: O(max(N, M)) to store the output string. Excluding the 
 *   output storage, the auxiliary space used is O(1) for pointers and numeric states.
 */

#include <iostream> 
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string addBinary(std::string &a, std::string &b)
    {
        std::string c;
        c.reserve(std::max(a.length(), b.length()) + 1);
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry_over = 0;

        while (i >= 0 || j >= 0 || carry_over > 0)
        {
            int digit_a = (i >= 0) ? a[i--] - '0' : 0;
            int digit_b = (j >= 0) ? b[j--] - '0' : 0;
            
            int sum = digit_a + digit_b + carry_over;
            c.push_back(static_cast<char>((sum % 2) + '0'));
            carry_over = sum / 2;
            /*
            Alternatively:
            //  Inside your optimized while loop:
                int digitA = (i >= 0) ? (a[i--] - '0') : 0;
                int digitB = (j >= 0) ? (b[j--] - '0') : 0;

                // Hardware level simulation of a Full Adder circuit
                int current_sum = digitA ^ digitB ^ carry;
                carry = (digitA & digitB) | (carry & (digitA ^ digitB));

                result.push_back(current_sum + '0');
            
            */
        }
        std::reverse(c.begin(), c.end());
        return c;
    }
};

int main()
{
    Solution sol;
    std::string a {"1010"};
    std::string b {"1011"};
    std::cout << "Sum of a & b in binary is: " << sol.addBinary(a, b) << std::endl;
}