#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*

Five Cons:

#################

Constrain: Leetcode gives constraints in their question 
Conceive:  (up to you but best to use a white board and talk it out even to yourself or piece of paper before coding)
Contract: function signature given by LeetCode
Construct: Class created and implementation in public and private methods of Class
Confirm: (tested in main using leetcode examples, testing by passing to leetcode submission)

#################

Constrain:  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
            You may assume that each input would have exactly one solution, and you may not use the same element twice.
            (ask:  negative numbers allowed?  yes
             ask: is array sorted? no)

Conceive:   (put ideas here from whiteboard , be honest)
            since not sorted can't use binary search 
            can use a map to store the complement = target - current element 
            we map it to the index of the current element that is used
            questions? 
            do I need helper functions? NO.
            recursion? NO

Contract:   vector<int> twoSum(vector<int>& nums, int target)
*/

/* Construct */


/*** LEETCODE ACCEPTANCE RESULTS
 
    Success

    Details 
    Runtime: 8 ms, faster than 92.77% of C++ online submissions for Two Sum.
    Memory Usage: 9.9 MB, less than 56.68% of C++ online submissions for Two Sum.

***/

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result = {-1, -1};

        /*  use a map to store requests for complements and the index of the requestor */
        unordered_map<int,int> map;

        for (int i = 0;i < nums.size();i++)
        {
            /* check our map if a request for a compliment is registered */
            /* if registered then we have our compliment whose index is in the map */
            if (map.find(nums[i]) != map.end())
            {
                result[0] = i;
                result[1] = map[nums[i]];
                break;
            }
            /* store the compliment which is a request by the element at index i */
            int complement = target - nums[i];
            map[complement] = i;

        }

        return result;

    }

};


/* Confirm */

int main()
{
    
    vector<int> nums = {2, 7, 11, 15};
   // vector<int> nums = {3, 2, 4};

    Solution sol;
    vector<int> result = sol.twoSum(nums,9);
 //   vector<int> result = sol.twoSum(nums,6);

    cout << "result: " << endl;
    cout << result[0] << endl;
    cout << result[1] << endl;
}