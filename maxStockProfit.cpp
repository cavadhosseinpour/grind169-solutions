#include <vector>
#include <iostream>

class Solution{
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min_day = prices[0];
        int result = 0;
        for (int i = 1; i != prices.size(); ++i)
        {
            if (prices[i] < min_day)
            {
                min_day = prices[i];
            }
            else if (prices[i] - min_day > result)
            {
                result = prices[i] - min_day;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << "The max profit is: " << sol.maxProfit(prices) << "\n";
    return 0;
}