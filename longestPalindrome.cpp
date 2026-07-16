#include <iostream>
#include <unordered_set>

/**
 * @file longest_palindrome.cpp
 * @brief LeetCode 409 - Longest Palindrome
 * 
 * @details
 * Given a string 's' which consists of lowercase or uppercase letters, return the 
 * length of the longest palindrome that can be built with those letters. Letters 
 * are case-sensitive (e.g., "Aa" is not considered a palindrome).
 * 
 * @section algorithmic_insights Algorithmic Insights
 * The solution implements a greedy pairing algorithm using a hash set. As we 
 * iterate through the string, the set tracks characters with an "odd" frequency 
 * state. When a character is encountered that is already in the set, it completes 
 * a pair. The pair is greedily added to the palindrome length (+2), and the 
 * character is removed from the set to reset its state back to "even". At the end 
 * of the iteration, if the set is not empty, it implies at least one character has 
 * an unpaired instance which can act as the unique central pivot of the palindrome.
 * 
 * @section complexity Complexity Analysis
 * - Time Complexity: O(N)
 *   We perform a single pass over the string of length N. Hash set insertion, 
 *   lookup, and erasure operations take O(1) average time complexity.
 * - Space Complexity: O(1)
 *   While a hash set is used, the character set is bounded by the alphabet size. 
 *   Since the input only contains uppercase and lowercase English letters, the 
 *   maximum number of unique keys in the set is strictly capped at 52. Because 
 *   the memory usage does not scale with the size of N, space is O(1) constant.
 */

class Solution
{
public:
    int longestPalindrome(std::string& s)
    {
        if (s.empty()) return 0;
        std::unordered_set<char> char_set;
        int count = 0;

        for (char c : s)
        {
            if (!char_set.contains(c))
            {
                char_set.insert(c);
            }
            else
            {
                char_set.erase(c);
                count += 2;
            }
        }

        if (!char_set.empty())
        {
            count++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    std::string s = "abccccdd";
    std::cout << "Longest Palindrome from this string is: " << sol.longestPalindrome(s) << std::endl;
}

// Alternatie approach using a fixed size array
/**
 * @file longest_palindrome_array.cpp
 * @brief LeetCode 409 - Longest Palindrome (Fixed Array Optimization)
 * 
 * @details
 * Given a string 's' which consists of lowercase or uppercase letters, return the 
 * length of the longest palindrome that can be built with those letters. Letters 
 * are case-sensitive.
 * 
 * @section algorithmic_insights Algorithmic Insights
 * This solution optimizes performance by replacing the hash set with a fixed-size 
 * frequency array. We map characters to indices by shifting their ASCII values 
 * relative to 'A'. The maximum span from 'A' (65) to 'z' (122) is 58 slots. 
 * In the first pass, we accumulate counts. In the second pass, we greedily collect 
 * all possible pairs using integer division. If the final length is less than the 
 * original string length, it guarantees at least one odd character exists to serve 
 * as the central pivot.
 * 
 * @section complexity Complexity Analysis
 * - Time Complexity: O(N)
 *   Requires one pass over the string of length N to count frequencies, and one 
 *   fixed pass of 58 iterations to calculate the pairs. Linear time overall.
 * - Space Complexity: O(1)
 *   Uses a fixed-size array of 58 integers allocated on the stack. The space is 
 *   strictly constant and entirely independent of the input size N.
 */

/* 

class Solution {
public:
    int longestPalindrome(std::string s) {
        // Range from 'A' (65) to 'z' (122) requires exactly 58 slots
        constexpr int alphabet_span = 122 - 65 + 1;
        int frequency_buckets[alphabet_span] = {0};

        // Pass 1: Populate character frequencies
        for (const char current_char : s) {
            frequency_buckets[current_char - 'A']++;
        }

        int max_palindrome_length = 0;

        // Pass 2: Count pairs from the buckets
        for (int count : frequency_buckets) {
            // Integer division extracts the paired characters
            max_palindrome_length += (count / 2) * 2;
        }

        // If the palindrome is shorter than the string, an odd character exists
        if (max_palindrome_length < s.length()) {
            max_palindrome_length += 1;
        }

        return max_palindrome_length;
    }
};
*/