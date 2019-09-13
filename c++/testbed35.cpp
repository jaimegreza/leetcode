#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


    void mergeLong(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if ((m == 0) && (n == 0))
            return;
        
        if (nums1.size() != (n+m))
            return;

        for (int i=m;i<(m+n);i++)
        {
            nums1[i] = nums2[i-m];
        }

        mergeSort(nums1,0,nums1.size()-1);

    }

    void mergeSort(vector<int> & input, int l, int r)
    {
        if (l < r)
        {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l+(r-l)/2;
  
            // Sort first and second halves
            mergeSort(input, l, m);
            mergeSort(input, m+1, r);
  
            merge(input, l, m, r);
        }
     }

      void merge(vector<int> & input, int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
 
        /* create temp arrays */
        vector<int> L(n1);
        vector<int> R(n2);

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = input[l + i];
        for (j = 0; j < n2; j++)
            R[j] = input[m + 1+ j];
 
        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                input[k] = L[i];
                i++;
            }
            else
            {
                input[k] = R[j];
                j++;
            }
            k++;
        }
 
        /* Copy the remaining elements of L[], if there
        are any */
        while (i < n1)
        {
            input[k] = L[i];
            i++;
            k++;
        }
 
        /* Copy the remaining elements of R[], if there
        are any */
        while (j < n2)
        {
            input[k] = R[j];
            j++;
            k++;
        }
    }
 


    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if ((m == 0) && (n == 0))
            return;
        
        if (nums1.size() != (n+m))
            return;
        
        int idx = nums1.size()-1;
        int aIdx = 0;
        int bIdx = 0;

        while (idx >= 0)
        {
            if (aIdx >= m)
            {
                while (bIdx < n)
                {
                    nums1[idx--] = nums2[bIdx++];
                }
                break;
            }

            if (bIdx >= n) 
            {
                if (idx > 0) 
                {
                    int beg = aIdx;
                    int end = idx;

                    while (beg < end)
                    {
                        int temp = nums1[beg];
                        nums1[beg++] = nums1[end];
                        nums1[end--] = temp;
                    }
                }
                break;
            }

            int a = nums1[aIdx];
            int b = nums2[bIdx];


            if (a < b)
            {
                if (aIdx != idx)
                {
                    if (idx <= m-1)
                    {
                        int temp = nums1[idx];
                        nums1[idx] = a;
                        nums1[aIdx-1] = temp;
                        aIdx++;
                    }
                    else
                    {
                        nums1[idx] = a;
                        aIdx++;
                    }
                }

                if ( (aIdx == idx) ||
                     (aIdx == m)) 
                {

                    while (bIdx < n)
                    {
                        nums1[--idx] = nums2[bIdx++];
                    }
                    break;
                }
            }
            else
            {
                if (aIdx == idx)
                {
                    nums1[aIdx-1] = nums1[idx];                    
                    aIdx--;
                }

                if (idx <= m-1)
                {
                    int temp = nums1[idx];
                    nums1[aIdx-1] = temp;
                }
                nums1[idx] = b;
                bIdx++;

            }

            idx--;
        } 


        // reverse arr1
        int beg = 0;
        int end = nums1.size()-1;

        while (beg < end)
        {
            int temp = nums1[beg];
            nums1[beg++] = nums1[end];
            nums1[end--] = temp;
        }

    }
};

int main()
{
    Solution sol;
//    vector<int> arr1 = {1,2,3,0,0,0}; // m=3
//    vector<int> arr2 = {2,5,6};  // n = 3
//[1,2,2,3,5,6]
   
//    vector<int> arr1 = {1,2,3,0,0}; // m=3
 //   vector<int> arr2 = {2,5};  // n = 2


//    vector<int> arr1 = {4,0,0,0,0,0}; // m= 1
 //   vector<int> arr2 = {1,2,3,5,6};  // n = 5

  //  vector<int> arr1 = {-1,3,0,0,0,0,0}; // m= 2
   // vector<int> arr2 = {0,0,1,2,3};  // n = 5
//  vector<int> arr1 = {0};
  //vector<int> arr2 = {1};
   
   // vector<int> arr1 = {4,5,6,0,0,0};
   // vector<int> arr2 = {1,2,3};
   
   // vector<int> arr1 = {1,2,4,5,6,0};
  //  vector<int> arr2 = {3};
   
    vector<int> arr1 = {-1,-1,0,0,0,0}; //4
    vector<int> arr2 = {-1,0}; //2
   
    sol.mergeNotWorking(arr1, 4, arr2, 2);

    for (int i=0;i< arr1.size();i++)
    {
        cout << arr1[i] << endl;
    }





}