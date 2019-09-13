#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() -1;
        return binarySearch(nums,target,low,high);
       
    }

    int binarySearch(vector<int> input, int search, int low, int high)
    {

        int mid;

        while ( low <= high)
        {   
            mid = low+((high-low) /2);

            if (input[mid] == search) {
                return mid;
            } 
            else if (input[mid] < search)
            {
                low = mid + 1;
            } 
            else
            {
                high = mid - 1;
            }
        }

        return low;   
    }

};

int main()
{
   // vector<int> input = {1,3,5,6}; //2
   vector<int> input = {1,3,4,6}; // 3 
    Solution sol;
    int target = 5;

    int ret = sol.searchInsert(input,target);

    cout <<  "ret" << ret << endl;


}