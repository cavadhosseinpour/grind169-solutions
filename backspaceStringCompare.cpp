#include <iostream>
#include <string>

/**
 * @file BackspaceStringCompare.cpp
 * @brief LeetCode 844: Backspace String Compare
 * 
 * @details
 * Problem Description:
 * Given two strings 's' and 't' containing alphanumeric characters and '#' 
 * representing backspace tokens, determine if they are identical after processing 
 * all deletion states. An empty text buffer subjected to a backspace remains empty.
 * 
 * Foundational Algorithmic Insights:
 * Processing strings from left to right requires extra storage (like a Stack) because 
 * backspaces affect past characters. Moving right-to-left flips this relationship: 
 * backspaces tell us how many future characters to skip. By keeping a running count of 
 * pending deletions, we can scan both strings backward in a single pass using two 
 * independent pointers, ensuring constant space complexity.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N + M)
 *   Each character in string 's' (length N) and string 't' (length M) is evaluated 
 *   at most twice (once to register a skip state and once to safely decrement).
 * - Space Complexity: O(1)
 *   No structural copies or call-stack allocations are generated. State tracking 
 *   is isolated to primitive loop indices and integer counters.
 */

class Solution
{
private:
    /**
     * @brief Resolves all active backspaces to find the next valid visible character index.
     * @param str The source string to evaluate.
     * @param index The starting boundary index, passed by value to isolate primary loop state.
     * @return The index of the next un-deleted character, or -1 if the string is exhausted.
     */
    int valid_index(std::string& v, int index)
    {
        int skip_count = 0;

        while (index >= 0)
        {
            if (v[index] == '#')
            {
                ++skip_count;
                --index;
            }
            else if (skip_count > 0)
            {
                --skip_count;
                --index;
            }
            else
            {
                break;
            }
        }
        return index;
    }
public:
    bool backspaceCompare(std::string& s, std::string& t)
    {
        int i = s.length() - 1;
        int j = t.length() - 1;
        while (i >= 0 || j >= 0)
        {
            i = valid_index(s, i);
            j = valid_index(t, j);

            if (i < 0 && j < 0)
            {
                return true;
            }
            if ( i < 0 || j < 0 )
            {
                return false;
            }
            if (s[i] != t[j])
            {
                return false;
            }
            --i;
            --j;
        }
        return true;
    }
};

int main()
{
    std::string s = "a#c";
    std::string t = "b";

    Solution sol;

    std::cout << (sol.backspaceCompare(s, t) ? "They are equal!" : "They are NOT equal!") << std::endl;
}