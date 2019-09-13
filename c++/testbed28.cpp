#include <iostream>
#include <vector>
#include <limits>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        if (nums.size() == 1)
            return nums[0];
            
        int size = nums.size();

        int max = INT_MIN;
        int cur = 0;

        for (int i = 0;i < size;i++)
        {
            int val = nums[i];

            cur = cur + val;
            
            if (cur < 0)
            {
                if (val > max)
                {
                    max = val;
                }
                
                cur = 0;
                continue;
            }
            else
            {
                if (cur > max)
                {
                    max = cur;
                }
            }

        }

        return max;
    }
};
int main()
{
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4}; //6
    // vector<int> input = {-2,-1}; //-1

    Solution sol;
    int ret = sol.maxSubArray(input);

    cout << "ret: " << ret << endl;

}