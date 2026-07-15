#include <iostream>
#include <vector>

class Solution
{
private:
    /**
     * @brief Computes the number of distinct ways to climb to the top using memoization.
     * 
     * Problem Description:
     * You are climbing a staircase that takes 'n' steps to reach the top. Each time you 
     * can either climb 1 or 2 steps. Return the number of distinct ways to reach the top.
     * 
     * Foundational Algorithmic Insights:
     * This problem maps to a linear recurrence relation matching the Fibonacci sequence: 
     * f(n) = f(n-1) + f(n-2). Pure recursion yields an O(2^n) time complexity due to 
     * heavily overlapping subproblems. Introducing a memoization table tracks state 
     * evaluations, pruning redundant branches of the recursive call tree to linearize 
     * performance.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(n) - Each state from 1 to n is computed exactly once. 
     *   Subsequent lookups take O(1) time.
     * - Space Complexity: O(n) - Driven by the O(n) auxiliary memory allocated for 
     *   the memoization table and the O(n) maximum depth of the recursive call stack.
     * 
     * Memoization technique:
     * ## 📝 INTERVIEW CHEAT SHEET: MEMOIZATION (TOP-DOWN DP)

        ### 📌 What is it?
        Memoization converts an exponential-time recursive algorithm O(2^n) into a linear-time 
        algorithm O(n) by caching the results of recursive state computations. It trades memory 
        space to gain execution speed.

        ### ⚠️ Common Interview Pitfalls
        1. **Passing Cache by Value:** Always pass the memoization data structure by reference 
        (`&` in C++). Forgetting the `&` causes the program to copy the entire container on 
        every single recursive call, destroying performance and causing an O(n^2) space complexity.
        2. **Cache Initialization Sizing:** Ensure your cache is large enough to prevent 
        out-of-bounds errors. If your problem queries up to input `n`, your array/vector must be 
        sized to at least `n + 1` so that index `n` is legally accessible.
        3. **Invalid Default Values:** Initialize your cache with a value that can never occur 
        as a valid result of the subproblem (e.g., `-1` for path-counting or combinations, 
        since you cannot have negative combinations).

        ### 📊 Time & Space Trade-offs
        * **Time Complexity:** Lowered to O(State_Space * Work_Per_State). For Climbing Stairs, 
        there are `n` states and each state takes O(1) addition work, resulting in O(n) time.
        * **Space Complexity:** Raised to O(n) due to a double-allocation penalty:
        1. The explicit auxiliary memory structure used for the cache.
        2. The implicit memory used by the Operating System for the Recursive Call Stack frames.

        ### 💡 The "Rule of Thumb" Transition Strategy
        In an interview, if you struggle to find a loop solution, **always write the Memoized 
        Recursion first**. It is conceptually easier because it follows human logic (breaking a big 
        goal into smaller goals). Once it works, look at your cache extraction lines and convert it 
        into an iterative loop to drop your space complexity down to O(1).

     * Return_Type helperFunction(StateVariables, Cache/Vector& memo) 
            {
            // STEP 1: Check the Cache
            if (memo[StateVariables] is already calculated) {
                return memo[StateVariables];
            }

            // STEP 2: Handle Base Cases
            if (StateVariables hit baseline conditions) {
                return baseline_value;
            }

            // STEP 3: Compute and Store the Result
            memo[StateVariables] = helperFunction(NextState, memo) + helperFunction(AlternateNextState, memo);

            // STEP 4: Return the Stored Value
            return memo[StateVariables];
            }
     */

    int helper(int n, std::vector<int>& res)
    {
        if (res[n] > 0) return res[n];
        if (n < 3) return n;
        res[n] = helper(n - 1, res) + helper(n - 2, res);
        return res[n];
    }
public:

    int climbStairs(int n)
    {
        if (n <= 1) return 1;
        std::vector<int> res(n + 1, 0);
        return helper(n, res);
    }
/*
    
     * * This is an alternative approach (iterative)
     * @brief Alternative optimal implementation using Bottom-Up iterative space optimization.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(n) - Single pass loop up to 'totalSteps'.
     * - Space Complexity: O(1) - Mutates state using only two scalar tracking variables.
     * * This can only be achieved with two scalar tracking variables not with a vector which takes O(n) space.
    int climbStairs(int n)
    {
        if (n < 2)
        {
            return 1;
        }
        int n_2 = 1;
        int n_1 = 1;
        int current = 1;
        for (int i = 2; i <= n; ++i)
        {
            current = n_2 + n_1;
            n_2 = n_1;
            n_1 = current;
        }
        return current;
    }
    // ORRRRRRR
    int climbStairs(int n)
    {
        if (n < 4) return n;
        std::vector<int> res(n, 0);
        res[0] = 1;
        res[1] = 2;

        int i = 2;
        while (i < n)
        {
            res[i] = res[i - 1] + res[i - 2];
            i++;
        }
        return res[n - 1];
    }
*/

};

int main()
{
    Solution sol;
    std::cout << "Distinct ways of climbing 10 staircases: " << sol.climbStairs(10) << std::endl;
    return 0;
}