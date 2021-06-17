#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
        if (k == 0)
            return false;

        // sliding window
        int beg = 0;
        int end = k;
        if (nums.size() < k)
            end = nums.size()-1;

        if (nums.size() == k)
            end = nums.size()-1;


        unordered_map<int,int> map;

        //initialize sliding window
        if (containsDuplicateInRange(nums, map, beg, end))
            return true;


        // compare sliding window endpoints
        while (++end < nums.size())
        {
            // remove beginning from map;
            if (map.find(nums[beg]) != map.end())
            {
                int tmp = map[nums[beg]];
                if (tmp > 1)
                    map[nums[beg]] = tmp -1;
                else
                    map.erase(nums[beg]);
            }
            beg++;
            // add the new element to map
            if (map.find(nums[end]) != map.end())
            {
                return true;
            }
            else
            {
                map[nums[end]] = 1;                
            }
        }
        return false;
    }

    bool containsDuplicateInRange(vector<int>& nums, unordered_map<int,int>& map, int a, int b)
    {
        for (int i= a;i <= b;i++)
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

    bool isDup(vector<int>& nums, int a, int b)
    {
        return (nums[a] == nums[b]) ? true : false;
    }

    void printVector(vector<int> input)
    {
        for (int i = 0;i< input.size();i++)
        {
            cout << input[i] << " " ;

        }
        cout << endl;
    }

};


int main()
{
    Solution sol;
    vector<int> inp  = {1,2,3,1};
    int k = 3;

    sol.printVector(inp);
    cout << sol.containsNearbyDuplicate(inp,k) << endl;

    inp = {1,2,3,1,2,3};
    k = 2;
    sol.printVector(inp);
    cout << sol.containsNearbyDuplicate(inp,k) << endl;

    inp = {1};
    k = 1;
    sol.printVector(inp);
    cout << sol.containsNearbyDuplicate(inp,k) << endl;

    inp = {4,1,2,3,1,5};
    k = 3;
    sol.printVector(inp);
    cout << sol.containsNearbyDuplicate(inp,k) << endl;

}
