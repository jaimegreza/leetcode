#include <iostream>
#include <locale>
#include <vector>
#include <unordered_set>
//isalnum
//tolower
using namespace std;

class Solution {
public:

   bool binarySearch(vector<int>& nums, int target)
    {
        
        return binarySearch(nums,target,0,nums.size()-1);
    }


    bool binarySearch(vector<int>& nums,int target, int low, int high)
    {
        if (low > high)
            return false;

        int mid = low + (high - low)/2;

        if (nums[mid] == target)
            return true;
        
        return ( (binarySearch(nums,target,low,mid-1)  ||
                    binarySearch(nums,target,mid+1,high) ));


    }


    int singleNumber(vector<int>& nums) 
    {

        unordered_set<int> set;
        
        if (nums.size() == 1)
            return nums[0];

 
        for (int i = 0;i < nums.size() ; i++ )
        {
           if (set.find(nums[i]) == set.end())
           {
			    if (binarySearch(nums, nums[i],i+1,nums.size()-1))
                    set.insert(nums[i]);
                else
                    return nums[i];
           }
           else
			    set.erase(nums[i]); 
        }    

	    return *(set.begin()); 
    }


    int singleNumberFast(vector<int>& nums) 
    {
        unordered_set<int> numset;

	    for (int num : nums)
	    {
		    if (numset.find(num) == numset.end())
			    numset.insert(num);
		    else
			    numset.erase(num);
	    }

	    return *(numset.begin()); 

    }


    int singleNumberSlow(vector<int>& nums) {

            int cache = 1 ;
            if (nums.size() == 1)
                return nums[0];

            for (int i = 0;i < nums.size() ; i++ )
            {
                if (i == nums.size() -1 )
                    return nums[i];

                if ((!binarySearch(nums, nums[i],i+1,nums.size()-1) &&
                        !binarySearch(nums, nums[i],0,i-1)))
                    return nums[i];
            }

    }

 

    bool isPalindrome(string s) {

         bool bIsPalindrome = true;

        locale loc;
  
        int beg = 0;
        int end = s.length()-1;

        while (beg < end)
        {
            if (!isalnum(s[beg]))
            {
                beg++;
                continue;
            }

            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }

            if (tolower(s[beg],loc) != (tolower(s[end],loc)))
                return false;

            beg++;
            end--;
        }

        return bIsPalindrome;      
    }
};


int main()
{
    Solution sol;

    string s = "A man, a plan, a canal: Panama";
//    string s = "race a car";

    //vector<int> input = {2,2,1};

    vector<int> input = {4,1,2,1,2};

    int two = sol.singleNumber(input);
        //bool ret = sol.isPalindrome(s);

    
}