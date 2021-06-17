#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    template <class ForwardIterator>
    ForwardIterator max_element ( ForwardIterator first, ForwardIterator last )
    {
        if (first==last) return last;
        ForwardIterator largest = first;

        while (++first!=last)
            if (*largest<*first)    // or: if (comp(*largest,*first)) for version (2)
                largest=first;
    
        return largest;
    }

    template <class ForwardIterator, class T>
    ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
    {
        ForwardIterator it;
        typename std::iterator_traits<ForwardIterator>::difference_type count, step;
        count = std::distance(first,last);
        while (count>0)
        {
            it = first; step=count/2; std::advance (it,step);
            if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
                first=++it;
                count-=step+1;
            }
            else count=step;
        }
        return first;
    }

    template <class ForwardIterator, class T>
    bool binary_search (ForwardIterator first, ForwardIterator last, const T& val)
    {
        first = std::lower_bound(first,last,val);
        return (first!=last && !(val<*first));
    }

    int findPeakElement(vector<int>& nums) {

        if (nums.size() == 1)
            return 0;

        if (nums.size() == 2)
            return (nums[0] > nums[1] ? 1 : 0);

        int left  = 0;
        int right = nums.size() -1;

        while (left < right)
        {
            int mid = left + (right - left)/2;

            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }

        }

        return left;
        
    }

    int findPeakElement2(vector<int>& nums) {

        if (nums.size() == 1)
            return 0;

        if (nums.size() == 2)
            return (nums[0] > nums[1] ? 1 : 0);

        int idx = std::distance(nums.begin(), max_element(nums.begin(),nums.end()));

        return idx;

    }
};


int main()
{
    Solution sol;

    vector<int> input1 = {1,2,1,3,5,6,4};

    cout << sol.findPeakElement(input1) << endl;

    input1 = {1,2,3,1};

    cout << sol.findPeakElement(input1) << endl;


}