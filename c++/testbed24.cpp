#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int size = nums.size();
        
         if (size == 0)
            return 0;

        if (size == 1)
        {
            if (nums[0] == val)
            {
                return 0;
            }
            else    
                return 1;
        }

        int leftIndex = 0;
        int rightIndex = size-1;

        while (leftIndex <= rightIndex)
        {
            if (nums[leftIndex] != val)
            {
                leftIndex++;
                continue;
            }
            else
            {
                while (nums[rightIndex] == val)
                {
                    rightIndex--;

                }

                  if (rightIndex < 0)
                        break;
                
                if (leftIndex < rightIndex)
                {
                    nums[leftIndex] = nums[rightIndex];
                    leftIndex++;
                    rightIndex--;
                }
            }

        }
        return rightIndex + 1;
    }
};
int main()
{
    Solution sol;
    
   // vector<int> input = {0,1,2,2,3,0,4,2};

     vector<int> input = {4,5};

    int ret = sol.removeElement(input,5);

    cout << "ret: " << ret << endl;

    for (int i=0;i<ret;i++)
    {
        cout << input[i] << endl;
    }

}