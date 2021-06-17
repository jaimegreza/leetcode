#include <iostream>
#include <vector>
#include <unordered_map>
#include "algorithm.cpp"
using namespace std;

class Solution
{
    public:
     template <class ForwardIterator>
    ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last)
    {
        if (first != last)
        {
            ForwardIterator next=first; ++next;
            while (next != last) {
                if (*first == *next)     // or: if (pred(*first,*next)), for version (2)
                    return first;
                ++first; ++next;
            }
        }
        return last;
    }
   
    bool containsDuplicate2(vector<int>& nums) {

        if (nums.size() == 1)
            return false;

        //sort(nums.begin(), nums.end());
        JIMMY::quickSort(nums);

        if (adjacent_find(nums.begin(), nums.end()) != nums.end())
        {
            return true;
        }
        return false;
    }
    
    bool containsDuplicate(vector<int>& nums) {

        if (nums.size() == 1)
            return false;

        unordered_map<int,int> map;

        for (int i = 0;i< nums.size();i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                return true;
            }
            else
            {
                map[nums[i]] = 1;
            }
        }

        return false;        
    }



};


int main()
{
    Solution sol;


    vector<int> input = {1,1,1,3,3,4,3,2,4,2};
    cout << sol.containsDuplicate2(input) << endl;

    input = {1,3,4,2};
    cout << sol.containsDuplicate2(input) << endl;


    input = {1,1,1,3,3,4,3,2,4,2,1,1,3,3,4,3,2,4,2,1,1,3,3,4,3,2,4,2,1,1,3,3,4,3,2,4,2,1,1,3,3,4,3,2,4,2};
    cout << sol.containsDuplicate2(input) << endl;

}