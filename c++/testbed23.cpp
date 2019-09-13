#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() == 0)
            return 0;

        int same = nums[0];
        int writeIndex = 0;
        int size = nums.size();

        for (int i=1;i < size;i++)
        {
            if (nums[i] == same)
            {
                continue;
            }
            else
            {
                nums[writeIndex+1] = nums[i];
                same = nums[i];
                writeIndex = writeIndex+1;
            }

        }
        return writeIndex+1;
    }
};

int main()
{
    Solution sol;

    vector<int> input = {0,0,1,1,1,2,2,3,3,4};

    int ret = sol.removeDuplicates(input);

    cout << "ret: " << ret << endl;

    for (int i=0;i<ret;i++)
    {
        cout << input[i] << endl;
    }

}