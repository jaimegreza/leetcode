#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

     int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        
         if (size <= 2)
            return size;

        int leftIndex = 0; // valid 
        int rightIndex = 1;
        int nextIndex = 1;  

        while (nextIndex < size)
        {
            if (nums[leftIndex] != nums[rightIndex])
            {
                leftIndex++;
                rightIndex++;
                if (leftIndex == nextIndex)
                    nextIndex++;
                continue;
            }
            else
            {
                while (nums[leftIndex] == nums[rightIndex])
                {
                    rightIndex++;
                }
// 0 1 2  1 0 3 4 5
//     l      r 
//        n               
                nums[nextIndex] = nums[rightIndex];
                leftIndex++;
                nextIndex++;
                rightIndex++;
            }
        }
        return (size - nextIndex + 1);

    }

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