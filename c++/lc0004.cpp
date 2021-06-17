#include <iostream>
#include <vector>

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

Constrain:  There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.
   

Conceive:   (put ideas here from whiteboard , be honest)
            the easiest idea was to use mergeSort but that is not O(log (m+n))
            Binary search is hinted because of the O (log (m + n))
            but since the arrays are already sorted using MergeSort should be O(log (m+n))
            so dividing by 2 in the mergeSort should be O (log (m + n))

            however, Binary search would mean I would have to search for an element from one array for its
            position in the other array if its a duplicate or which index you can insert that. Since all I need do is 
            work up to half of all the elements of both arrays could do something less than a full implementation of
            mergesort. just one pass of Mergehalves stopping when i have the middle values to calculate median.

            start with O(M+N) without binary search.


Contract:    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)

*/

/* Construct */


class Solution {

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if ((m == 0) && (n == 1))
            return nums2[0];

        if ((n == 0) && (m == 1))
            return nums1[0];

        /* we have at least 2 elements to work with */

        int totalLen = m + n;
        bool isOdd = totalLen % 2;
        int midLen = totalLen / 2;
        int count = (isOdd) ? midLen + 1: midLen;        

        /* bounds checks */
        // all lower values in nums1
        if (nums1[m-1] <= nums2[0])
        {

            double median = 0.0;
            
            if (m > count)
            {
                if (isOdd)
                {
                    median = nums1[count];
                }
                else
                {
                    median = (nums1[count] + nums1[count+1]) / 2.0;
                }
                return median;
            }
            else if (m == count) //m == count
            {
                
                if (isOdd)
                {
                    median = nums2[0];
                }
                else
                {
                    median = (nums1[m-1] + nums2[0]) / 2.0;
                }
                return median;

            }
            else  // m < count
            {
                int remainder = count - m;

                if (isOdd)
                {
                    median = nums2[remainder-1];
                }
                else
                {
                    median = (nums2[remainder] + nums2[remainder-1]) / 2.0;
                }
                return median;
            }
        }

        if (nums2[n-1] <= nums1[0])
        {

            double median = 0.0;
            
            if (n > count)
            {
                if (isOdd)
                {
                    median = nums2[count];
                }
                else
                {
                    median = (nums2[count] + nums2[count+1]) / 2.0;
                }
                return median;
            }
            else if (n == count) //n == count
            {
                
                if (isOdd)
                {
                    median = nums1[0];
                }
                else
                {
                    median = (nums2[m-1] + nums1[0]) / 2.0;
                }
                return median;

            }
            else  // n < count
            {
                int remainder = count - n;

                if (isOdd)
                {
                    median = nums1[remainder-1];
                }
                else
                {
                    median = (nums1[remainder] + nums1[remainder-1]) / 2.0;
                }
                return median;
            }
        }


  
        /* for ODD LENGHT of total Median is the middle value */
        /* for EVEN LENGHT of total Median is the average of two middle value */

        int i = 0;
        int j = 0;


        // calculate mean
        double median = 0.0;

        while (count > 0)
        {

            if (nums1[i] <= nums2[j])
            {
                bool bFound = false;
                int idx = binarySearch(nums1, i, m-1, nums2[j],bFound);

                if ((idx - i) > count) // median is in nums1
                {
                    i = i + count;
                    median = (nums1[i] + nums1[i+1]) / 2.0;
                    return median;
                }
                else
                {
                    if (i != idx)
                    {
                        count = count - (idx - i);
                        i = idx;
                    }
                    else
                    {
                        count--;
                        if (count > 0)
                            i++;
                    }
                }

                if (count == 0)
                {
                        if (!bFound)
                        {
                            median = (nums1[i] + nums2[j]) / 2.0;
                        }
                        else
                        {
                            median = (nums1[i] + nums1[i+1]) / 2.0;                        
                        }
                        return median;                
                }
            }
            else if(nums1[i] > nums2[j] )
            {
                bool bFound = false;
                int idx = binarySearch(nums2, j, n-1, nums1[i],bFound);

                if ((idx - j) > count) // median is in nums1
                {
                    j = j + count;
                    median = (nums2[j] + nums2[j+1]) / 2.0;
                    return median;
                }
                else
                {
                    if (j != idx)
                    {
                        count = count - (idx - j);
                        j = idx;
                    }
                    else
                    {
                        count--;
                        if (count > 0)
                            j++;
                    }
                }

                if (count == 0)
                {
                        if (!bFound)
                        {
                            median = (nums2[j] + nums1[i]) / 2.0;
                        }
                        else
                        {
                            median = (nums2[j] + nums2[j+1]) / 2.0;                        
                        }
                        return median;                
                }
            }

        }


        return median;

    }

    int binarySearch(vector<int> & arr, int low, int high, int target, bool & found)
    {
        found = false;

        while (low < high)
        {
            int mid = low + (high + low)/2;

            if (arr[mid] == target)
            {
                found = true;
                return mid;
            }
            else if (arr[mid] < target)
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

    double findMedianSortedArraysSlow(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        if ((m == 0) && (n == 1))
            return nums2[0];

        if ((n == 0) && (m == 1))
            return nums1[0];

        int totalLen = m + n;
        bool isOdd = totalLen % 2;
        int midLen = totalLen / 2;

        /* we have at least 2 elements to work with */

        /* for ODD LENGHT of total Median is the middle value */
        /* for EVEN LENGHT of total Median is the average of two middle value */

        int count = 0;        
        int mIdx = 0;
        int nIdx = 0;

        while (((mIdx < m) && (nIdx < n)) &&
                (count < midLen))
        {
            if (nums1[mIdx] < nums2[nIdx])
            {
                 if (mIdx < (m-1))
                    mIdx++;
            }
            else
            {
                 if (nIdx < (n -1))
                    nIdx++;
            }
            count++;
        }

        bool bMedianInOneArray = false;
        bool bMedianInM = false;

        if (((count < midLen) && !isOdd) ||
            ((count <= midLen) && isOdd))
        {            
            if (mIdx == m - 1)  /* median in n array */
            {
                nIdx = midLen - m + nIdx;
            }
            else
            {
                mIdx = midLen - n + mIdx;
                bMedianInM = true;
            }
            bMedianInOneArray = true;
        }

        /* calculate median */

        double median = 0.0;

        if (bMedianInOneArray)
        {
            if (bMedianInM)
            {
                if (isOdd)
                {
                    median = (double) nums1[mIdx];
                }
                else
                {
                    median = (double) ( nums1[mIdx] + nums1[mIdx + 1]) / 2.0;                    
                }
            }
            else
            {
                if (isOdd)
                {
                    median = (double) nums2[nIdx];
                }
                else
                {
                    median = (double) ( nums2[nIdx] + nums2[nIdx + 1]) / 2.0;                    
                }
            }

        }
        else
        {
                if (isOdd)
                {
                    if (nums1[mIdx] < nums2[nIdx])
                        median = (double) nums1[mIdx];
                    else
                        median = (double) nums2[nIdx];
                }
                else
                {
                    median = (double) ( nums1[mIdx] + nums2[nIdx + 1]) / 2.0;                    
                }

        }

        return median;

    }


};


/* Confirm */

int main()
{

    Solution sol;

    vector<int> a = {1, 3 , 5};
    vector<int> b = {2, 4};

    double result  = sol.findMedianSortedArrays(a,b);

    //cout << result << endl;

    vector<int> c = {3, 4, 5};
    vector<int> d = {6, 7, 8};

    result  = sol.findMedianSortedArrays(c,d);

    cout << result << endl;


    vector<int> e = {1, 2};
    vector<int> f = {3, 4};

    result  = sol.findMedianSortedArrays(e,f);

    cout << result << endl;

//    vector<int> g = {1, 3};
  //  vector<int> h = {2};

   // result  = sol.findMedianSortedArrays(g,h);

    //cout << result << endl;

}



/*** LEETCODE ACCEPTANCE RESULTS

***/