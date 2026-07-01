#include <iostream>
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        std::unordered_map<char, char> brackets =
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s)
        {
            if (brackets.contains(c))
            {
                if (st.empty() || st.top() != brackets[c])
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main()
{
    return 0;
}