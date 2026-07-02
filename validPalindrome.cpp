#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left])))
            {
                left++;
            }
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right])))
            {
                right--;
            }
            if (std::tolower(static_cast<unsigned char>(s[left])) != std::tolower(static_cast<unsigned char>(s[right])))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::string s = "A man, a plan, a canal: Panama";
    if (sol.isPalindrome(s))
    {
        std::cout << "The string is Palindrome.\n";
    }
    else
    {
        std::cout << "The string is NOT Palindrome.\n";
    }
    
    return 0;
}