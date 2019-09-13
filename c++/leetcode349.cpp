#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution
{
public:
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> hits;

        vector<int> result;
        bool bNum1Bigger = false;

        if (nums1.size() > nums2.size())
        {
            result = nums1;
            bNum1Bigger= true;
        }
        else
            result = nums2;

        for (int i = 0;i < result.size() ;i++)
        {
            hits[result[i]] = hits[result[i]] + 1;
        }

        result.clear();

        if (bNum1Bigger)
        {
            for (int i = 0;i< nums2.size();i++)
            {
                if (hits.find(nums2[i]) != hits.end())
                {
                    if (hits[nums2[i]] > 0)
                    {
                        result.push_back(nums2[i]);
                        hits[nums2[i]] = hits[nums2[i]] -1;
                    }
                }
            }
        }
        else
        {
            for (int i = 0;i< nums1.size();i++)
            {
                if (hits.find(nums1[i]) != hits.end())
                {
                    if (hits[nums1[i]] > 0)
                    {
                        result.push_back(nums1[i]);
                        hits[nums1[i]] = hits[nums1[i]] -1;
                    }
                }
            }
        }

        return result;
    }

    vector<int> intersectSet(vector<int>& nums1, vector<int>& nums2) {
        set<int> hits;

        vector<int> result;
        bool bNum1Bigger = false;

        if (nums1.size() > nums2.size())
        {
            result = nums1;
            bNum1Bigger= true;
        }
        else
            result = nums2;

        for (int i = 0;i < result.size() ;i++)
        {
            hits.insert(result[i]);
        }

        result.clear();

        if (bNum1Bigger)
        {
            for (int i = 0;i< nums2.size();i++)
            {
                if (hits.find(nums2[i]) != hits.end())
                {
                    result.push_back(nums2[i]);
                    hits.erase(nums2[i]);
 
                }
            }
        }
        else
        {
            for (int i = 0;i< nums1.size();i++)
            {
                if (hits.find(nums1[i]) != hits.end())
                {
                    result.push_back(nums1[i]);
                    hits.erase(nums1[i]);
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<int> v1 = {3,1,2};
    vector<int> v2 = {1,1};
    
    Solution sol;
    vector<int> result = sol.intersection(v1,v2);

    for (int i = 0;i< result.size();i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

}