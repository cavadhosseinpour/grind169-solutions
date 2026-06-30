#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        numMap.reserve(nums.size());
        for (int i = 0; i != nums.size(); ++i)
        {
            int second = target - nums[i];
            if (numMap.find(second) != numMap.end())
            {
                return {i, numMap[second]};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    return 0;
}