#include <iostream>
#include <cctype>
#include <unordered_map>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size()) return false;
        char char_counts[26] {0};
        for (char c : s)
        {
            char_counts[std::tolower(c) - 'a']++;
        }
        for (char c : t)
        {
            int index = std::tolower(c) - 'a';
            if (char_counts[index] == 0)
            {
                return false;
            }
            char_counts[index]--;
        }
        return true;
    }

    bool isAnagram_general(std::string s, std::string t)
    {
        if (s.size() != t.size()) return false;
        std::unordered_map<char, int> char_map;
        for (char c : s)
        {
            char_map[c]++;
        }
        for (char c : t)
        {
            if (!char_map.contains(c) || char_map[c] == 0)
            {
                return false;
            }

            char_map[c]--;

        }
        return true;
    }
};

int main()
{
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution sol;
    std::cout << ( sol.isAnagram(s, t) ? "True\n" : "False\n" );
    std::cout << ( sol.isAnagram_general(s, t) ? "True\n" : "False\n" );
    return 0;
}