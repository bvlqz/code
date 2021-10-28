#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> pair; 
        
        int diff; 
        std::map<int, int> diffMap;

        for(int i = 0; i < nums.size(); i++)
        {
            diff = target - nums[i];
            
            if (diffMap.find(diff) != diffMap.end())
            {
                pair = {diffMap[diff], i};
                return pair; 
            } else {
                diffMap[nums[i]] = i;
            }
        }
        return pair;
    }
};

int main()
{
   std::vector<int> nums  = { 2, 7, 11, 15 };
    int target = 9;     // node count
    
    Solution s;
    std::vector<int> result = s.twoSum(nums, target);
    std::cout
        << std::endl
        << result[0]
        << " , "
        << result[1]
        << std::endl; // 3
}
