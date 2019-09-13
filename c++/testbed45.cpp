#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version)
{
   if (version > 4)  
        return true;

    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        
        int exist = binarySearch(n);

        if (exist < 0) return 0;

        int left = leftIndexOfNumberInArray(exist);

        return left;

    }

    int binarySearch(int n)
    {
        int low = 1;
        int high = n;
        return binarySearch(low,high);
    }

    int binarySearch(int low, int high)
    {

        int mid;

        while ( low <= high)
        {   
            mid = low+((high-low) /2);

            bool hit = isBadVersion(mid);
            if (hit) {
                return mid;
            } 
            else 
            {
                low = mid + 1;
            }
        }

        return -1;   
    }


    int leftIndexOfNumberInArray(int index)
    {

        int found = index;

        while (found)
        {
            found = binarySearch(0, found);

            if (found == 0)
                return 0;
            
            bool hit = isBadVersion(found-1);
            if (!hit)
                return found;
            else    
                found = found-1;
        }

        return found;
    }

    void moveZeroes(vector<int>& nums) {
        
        int size = nums.size();
        if (size <= 1)
            return;
        
        int count = 0;
        int last = 0;

        for (int i = 0;i< size;i++)
        {
            int prev = count;
            while (nums[i] == 0)
            {
                count++;
                i++;
                if (i > size-1)
                    break;
            }

            if (prev < count)
            {
                if (i < size)
                {
                    nums[last] = nums[i];
                    last++;
                }
            }
            else
                last = i+1;


        }

        if ((nums[size-1] != 0) && (last = (size-count-1)))
        {
            nums[last] = nums[size-1];                
        }

        for (int i = (size -count ); i < size;i++)
        {
                nums[i]=0;
        }
    }

};


  
    

int main ()
{
    Solution sol;
    vector<int> in = {4,2,4,0,0,3,0,5,1,0};//{0,1,0,3,12};

    sol.moveZeroes(in);

}