#include <string>
#include <vector>
#include <iostream>

/**
 * @file LongestCommonPrefix.cpp
 * @brief LeetCode 14 - Longest Common Prefix
 *
 * @section Description
 * Given an array of strings, find the longest common prefix string amongst them.
 * If no common prefix exists, return an empty string "".
 *
 * @section Algorithmic_Insights
 * This solution implements Vertical Scanning (Column-by-Column Evaluation). 
 * We treat the vector of strings as a 2D matrix of characters. The first string 
 * acts as an anchor. We iterate through each character position (column) of the 
 * anchor string and verify if that character matches the character at the same 
 * position in all other strings (rows). 
 * 
 * Early Termination Patterns:
 * 1. Out-of-bounds: Current column index matches or exceeds a string's length.
 * 2. Mismatch: A character in any row differs from the anchor character.
 *
 * Rather than dynamically appending characters to a result string—which triggers 
 * repeated heap reallocations—the algorithm identifies the exact mismatch index 
 * and extracts a single substring at the end, optimizing memory performance.
 *
 * @section Complexity
 * - Time Complexity: O(S), where S is the sum of all characters in all strings.
 *   In the worst case (all strings are identical), the algorithm evaluates all 
 *   characters. In the best/average case, it terminates early in O(N * min_len) 
 *   where N is the number of strings and min_len is the length of the shortest string.
 * - Space Complexity: O(1) auxiliary space. The substring return requires O(M) 
 *   space where M is the length of the prefix, but no additional tracking data 
 *   structures are allocated.
 */

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        const std::string& anchor = strs[0];
        const size_t anchor_length = anchor.length();
        const size_t num_strings = strs.size();

        for (size_t i = 0; i < anchor_length; ++i)
        {
            for (int j = 1; j < num_strings; ++j)
            {
                if (i >= strs[j].length() || strs[j][i] != strs[0][i])
                {
                    return anchor.substr(0, i);
                }
            }
        }
        return anchor;
    }
};

int main()
{
    Solution sol;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << "The longest common prefix is: " << sol.longestCommonPrefix(strs) << std::endl;
}