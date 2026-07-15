#include <iostream>

// Mock implementation of the LeetCode API for local testing / GitHub integration
bool isBadVersion(int version)
{
    int first_bad_version = 4; // Mock value: Change this to test different cases
    return version >= first_bad_version;
}

class Solution
{
/**
 * @file LeetCode 278: First Bad Version
 * @brief Finds the first faulty version in a sequence using a binary search lower-bound template.
 * 
 * ALGORITHM DISCOVERY & FINDINGS:
 * - The search space is monotonic: [false, false, ..., false, true, true, ..., true]
 * - Linear scanning results in O(n) time, failing efficiency expectations.
 * - Binary search reduces time to O(log n) by cutting the space in half each iteration.
 * 
 * INTERVIEW TAKEAWAYS / PATTERNS:
 * - Overflow Prevention: 'left + (right - left) / 2' protects against integer constraints.
 * - Lower-Bound Traversal: 'right = mid' retains the current valid state in the pool,
 *   while 'while (left < right)' prevents endless cycles and converges cleanly.
 * 
 * COMPLEXITY:
 * - Time Complexity: O(log n) - Halves the active window per iteration.
 * - Space Complexity: O(1) - Utilizes static pointer allocations.
 */
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;

        while (left < right)
        {
            // Prevent integer overflow during middle calculation
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid))
            {
                // 'mid' is bad, meaning the target is either 'mid' or to its left
                right = mid; 
            }
            else
            {
                // 'mid' is good, meaning the target must be strictly to its right
                left = mid + 1; 
            }
        }
        // Pointers converge at 'left == right', pinning the exact first bad version
        return left; 
    }
};

int main()
{
    Solution solver;
    int total_versions = 5;
    std::cout << "The first bad version is: " << solver.firstBadVersion(total_versions) << std::endl;
    return 0;
}