#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:


        vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result = {-1,-1};

        unordered_map<int,pair<int,int>> map;

        for (int i=0;i< nums.size();i++)
        {
            if (map.find(nums[i]) != map.end())
            { 
                 pair<int,int> p = map[nums[i]];

                 if (p.first == p.second)
                 {
                    pair<int,int> newp = {p.first,i};
                    map[nums[i]] = newp;
                 }
            }
            else
            {
                pair<int,int> p = {i,i};
                map[nums[i]] =  p;
            }
        }

        for (int i=0;i< nums.size();i++)
        {
            int diff = target - nums[i];

            if (diff == nums[i])
            {
                pair<int,int> p = map[diff];

                if (p.first == p.second)
                    continue;
                else
                {
                    result[0] = p.first;
                    result[1] = p.second;
                    return result;
                }   

            }
            if (map.find(diff) != map.cend())
            {
                pair<int,int> p = map[diff];
                result[0] = i;
                result[1] = p.first;
                return result;

            }


        }

        return result;

    }
};


int main()
{
//    vector<int> nums = {2, 7, 11, 15};
    vector<int> nums = {3, 2, 4};

    Solution sol;
 //   vector<int> result = sol.twoSum(nums,9);
    vector<int> result = sol.twoSum(nums,6);

    cout << "result: " << endl;
    cout << result[0] << endl;
    cout << result[1] << endl;
    return 0;

}