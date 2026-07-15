#include <iostream>

/**
 * @file Solution.cpp
 * @brief LeetCode 383: Ransom Note
 * 
 * @details
 * Given two strings, ransomNote and magazine, return true if ransomNote can be 
 * constructed by consuming characters from magazine, and false otherwise. Each 
 * letter in magazine can only be used once in ransomNote.
 * 
 * @section algorithmic_insights Algorithmic Insights
 * - Domain Constraint: Since inputs are strictly lowercase English letters, a fixed 26-element 
 *   frequency array acts as a perfect, collision-free direct-address hash table.
 * - Array Pointer Offsets: Automatic integer promotion allows `character - 'a'` to seamlessly 
 *   evaluate to a valid boundary array index within the range.
 * - Early Bailout Guard Clause: If the note contains more characters than the entire magazine, 
 *   the evaluation terminates immediately to save clock cycles.
 * 
 * @section complexity Complexity Analysis
 * - Time Complexity: O(N + M)
 *   Where N is the length of ransomNote and M is the length of magazine. We iterate through 
 *   magazine once to seed counts, and ransomNote once to validate/decrement.
 * - Space Complexity: O(1)
 *   The storage required is strictly bounded by a fixed-size table of 26 integers, satisfying 
 *   true constant-space execution regardless of input string growth.
 */

class Solution
{
public:
    bool canConstruct(std::string &ransomNote, std::string &magazine)
    {
        if (ransomNote.length() > magazine.length()) return false;

        int bucket[26] {0};
        for (const char c : magazine)
        {
            bucket[c - 'a']++;
        }
        for (const char c : ransomNote)
        {
            if (bucket[c - 'a'] <= 0)
            {
                return false;
            }

            bucket[c - 'a']--;
        }
        return true;
    }

    /*
    * Alternative Approach using unordered_map:

    bool canConstruct(string ransomNote, string magazine)
    {
        std::unordered_map<char, int> check_map;

        for (char c : magazine)
        {
            check_map[c]++;
        }

        for (char c : ransomNote)
        {
            if (check_map.contains(c) && check_map[c] > 0)
            {
                check_map[c]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    */
};

int main()
{
    std::string ransomNote = "aa";
    std::string magazine = "aab";

    Solution sol;
    std::cout << (sol.canConstruct(ransomNote, magazine) ? "RansomNote can be constructed with Magazine!\n" : "RansomNote can NOT be constructed with magazine!\n");
}