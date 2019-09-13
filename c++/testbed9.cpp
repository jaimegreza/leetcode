#include <iostream>
#include <vector>

using namespace std;


class MergeRange
{
private:

    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    void merge(vector<pair<int,int>> & input, int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
 
        /* create temp arrays */
        vector<pair<int,int>> L(n1);
        vector<pair<int,int>> R(n2);

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
            if (((pair<int,int>)(L[i])).first <= ((pair<int,int>)(R[j])).first)
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
 


    /* l is for left index and r is right index of the
    sub-array of arr to be sorted */
    void mergeSort(vector<pair<int,int>> & input, int l, int r)
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
 

public:
        MergeRange(){};


        vector<pair<int,int>> mergeSortPairs(vector<pair<int,int>> & input)
        {

            mergeSort(input,0,input.size()-1);

            return input;

        }


        vector<pair<int,int>> getMergeRange(vector<pair<int,int>> input)
        {

            vector<pair<int,int>> output;

            pair<int,int> range = input[0];
            int newFirst = range.first;
            int newSecond = range.second;

            for(int i = 1; i < input.size(); i++)
            {
                pair<int,int> item = input[i];

                // check if item falls in range 

                if (item.first <= newSecond)
                {
                    if (item.second >= newSecond)
                    {
                        newSecond = item.second;
                    }

                    if (i == (input.size()-1))
                    {
                        pair<int,int> newPair = make_pair(newFirst,newSecond);
                        output.push_back(newPair);
                    }
                }
                else
                {
                    pair<int,int> newPair = make_pair(newFirst,newSecond);
                    output.push_back(newPair);

                    if (i == (input.size()-1))
                    {
                        output.push_back(item);
                        break;
                    }    

                    newFirst = item.first;
                    newSecond = item.second;
                }
            }

            return output;
        }
};

int main()
{
    MergeRange merge;
    vector<pair<int,int>> input2 = { {3,4}, {1,2}, {2,7}, {5,6}};

    for(int i = 0; i < input2.size(); i++)
    {
         cout << input2[i].first << ":" << input2[i].second<< endl; 
    }


    vector<pair<int,int>> output2 = merge.mergeSortPairs(input2);

    for(int i = 0; i < output2.size(); i++)
    {
         cout << output2[i].first << ":" << output2[i].second << endl; 
    }
  
    return 0;

   vector<pair<int,int>> input = { {1,2}, {2,2}, {2,7}, {5,6}, {11,12}};

    for(int i = 0; i < input.size(); i++)
    {
         cout << input[i].first << ":" << input[i].second<< endl; 
    }

    vector<pair<int,int>> output = merge.getMergeRange(input);

    for(int i = 0; i < output.size(); i++)
    {
         cout << output[i].first << ":" << output[i].second << endl; 
    }
    
    return 0;
}