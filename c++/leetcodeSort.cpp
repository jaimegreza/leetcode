#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class MinStack {


private:
    vector<int> heap;
    int cur;
    int size;

    void min_heapify(int idx){

        if (idx <= 0)
            return;

        if (idx > size)
            return;


        int par = heap[idx];

        if (idx*2 > size)
            return;

        if (par > heap[idx*2])
        {
            int temp = heap[idx];
            heap[idx] = heap[idx*2];
            heap[idx*2] = temp;
            min_heapify(idx*2);
        }

        if (par > heap[idx*2+1])
        {
            int temp = heap[idx];
            heap[idx] = heap[idx*2+1];
            heap[idx*2+1] = temp;
            min_heapify(idx*2+1);

        }

    }

    void insert(int x){

        if (size+1 > heap.size()+1)
            heap.resize(heap.size()*2);


        size++;
        int idx = size;
        heap[size] = x;
        
        while (idx >= 1)
        {
            int par = idx/2;

            if (heap[par] > (heap[idx]))
            {
                int temp = heap[par];
                heap[par] = heap[idx];
                heap[idx] = temp;
                idx = idx/2;
            }
            else
                break;
        }
            
    }

    void extract_min(){
        int min = heap[1];

        heap[1] = heap[size];
        size--;

        min_heapify(1);
    };

public:
    /** initialize your data structure here. */
    // root = i = 1
    // parent = i/2
    // left = 2i
    // right 2i+1
    // the key of a node is < = key of its children

    MinStack() : heap(10), cur(0), size(0) {
    }
    
    void push(int x) {
        insert(x);
    }
    
    void pop() {
        extract_min();
    }
    
    int top() {
        return heap[1];
    }
    
    int getMin() {
        return heap[1];
    }
};


class Solution
{
public:

/*** Bubble Sort ****/
/** works on two elements next to each other **/
/** double bubble **/

    void bubbleSort(vector<int> &input)
    {
        for (int i = 0;i<input.size();i++)
        {
            for (int j = i;j < input.size();j++)
            {
                if (input[j] < input[i])
                {
                    int temp = input[j];
                    input[j] = input[i];
                    input[i] = temp;
                }
            }
        }
    }

/*** Quick Sort ****/
/** use a pivot / partition **/
/** divide and conquer ***/
/*** recursive ***/
/** lobbing stuff over the fence **/

    void quickSort(vector<int> &input)
    {
        quickSort(input, 0, input.size()-1);        
    }

    void quickSort(vector<int> &input, int low ,int high)
    {
        if (low < high)
        {
            int p = partitionQuickSort(input,low, high);

            quickSort(input, low, p-1);
            quickSort(input, p+1, high);
            
        }        
    }
    
// pivot location is one less than counter index

    int partitionQuickSort(vector<int> &input, int low ,int high)
    {
        
        int i = low-1;

        for (int j=low;j < high;j++)
        {
            if (input[j] <= input[high])
            {
                i++;
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
 
        // swap pivot
        int temp = input[i+1];
        input[i+1] = input[high];
        input[high] = temp;
 
        return i+1;
    } 

    void printVector(vector<int> &input)
    {
        for (int i = 0;i< input.size();i++)
        {
            cout << input[i] << " " ;

        }
        cout << endl;
    }

/*** Merge Sort ****/
/*** divide and conquer **/
/** recursive **/


    void mergeSort(vector<int> &input)
    {

        mergeSort(input,0,input.size()-1);
    }

    void mergeSort(vector<int> &input, int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high)/2;
            mergeSort(input,low, mid);
            mergeSort(input,mid+1, high);
            mergeHalves(input,low, high);
        }
    }

    void mergeHalves(vector<int> &input, int lowStart, int highEnd)
    {
        if (lowStart > highEnd)
            return;

        int mid = (lowStart + highEnd)/2;

        int lowEnd = mid;
        int highStart = mid+1;

        int size = highEnd - lowStart + 1;

        int left = lowStart;
        int right = highStart;
        int idx = 0;

        vector<int> temp(size);


        while ((left <= lowEnd) && (right <= highEnd))
        {
            if (input[left] < input[right])
            {
                temp[idx] = input[left];
                left++;
            }
            else
            {
                temp[idx] = input[right];
                right++;
            }
            idx++;
        }

        for (int i = left;i <= lowEnd;i++)
        {
            temp[idx++] = input[i];
        }

        for (int i = right;i <= highEnd;i++)
        {
            temp[idx++] = input[i];
        }


        for (int i = 0;i < temp.size();i++)
        {
            input[i+lowStart] = temp[i];
        }

    }


/*** Insertion Sort ****/
/*** cost is on the left side (insertion) **/
/** sorted part on left start from 0 index***/

    void insertionSort(vector<int> &input)
    {
        if (input.size() <= 1)
            return;

        int sorted = input[0];
        for (int i = 1;i< input.size();i++)
        {
            if (input[i] < sorted)
            {
               // int idx = getIndexToInsert(input,i-1,input[i]);
                int idx = binarySearchForIndex(input,0,i-1,input[i]);
                if (idx == -1)
                    continue;

                int temp = input[i];

                int j = i;
                while (j  > idx)
                {
                    input[j] = input[j-1];
                    j--;
                }
                input[idx] = temp;
            }

            sorted = input[i];
        }

    }

    int getIndexToInsert(vector<int> &input, int high, int value)
    {
        for (int i = 0;i<=high;i++)
        {
            if (input[i] >= value)
            {
                return i;
            }

        }

        return high;

    }

    int binarySearchForIndex(vector<int> &input, int low, int high, int value)
    {

        while (low < high)
        {
            int mid = (high + low)/2;

            if (input[mid] == value)
            {
                return mid;
            }

            if (input[mid] > value)
            {
                high = mid -1;
            }
            else
                low = mid +1;         
        }
        return low;
    }

/*** Selection Sort ****/
/*** cost is on the right side (selection) **/
/** sorted part on left starting from index 0**/
/** pick from the right **/

    void selectionSort(vector<int> &input)
    {
        if (input.size() <= 1)
            return;

        for (int i = 0;i< input.size();i++)
        {
            int min = input[i];

            int j = i;
            int idx = i;

            while (j < input.size())
            {
                if (input[j] < input[idx])
                {
                    idx = j;
                }
                j++;
            }

            int temp = input[i];
            input[i] = input[idx];
            input[idx] = temp;
        }

    }

/*** Heap Sort ****/

    void heapSort(vector<int> &input)
    {
        
        MinStack st;

        for (int i=0;i<input.size();i++)
        {
            st.push(input[i]);
        }

        for (int i = 0;i<input.size();i++)
        {
            input[i] = st.getMin();
            st.pop();
        }

    }

/*** Radix Sort ****/

    void radixSort(vector<int> &input)
    {
        int m = getMax(input);

        for (int exp = 1; m/exp > 0;exp *=10)
        {
            countingSort(input);
        }

    }

    int getMax(vector<int> &input)
    {
        int max = INT_MIN;
        for (int i =0;i< input.size();i++)
        {
            if (input[i] > max)
            {
                max = input[i];
            }
        }
        return max;
    }


/*** Counting Sort ****/

    void countingSort(vector<int> &input)
    {
        // keys 0-9

        vector<int> keys(10,0);
        vector<int> places(input.size());

        for (int i =0; i< input.size();i++)
        {
            keys[input[i]]++;
        }

        for (int i = 1;i< keys.size();i++)
        {
            keys[i] += keys[i-1];
        }
        
        for (int i=0;i<input.size();i++)
        {
            places[keys[input[i]]] = input[i];
            keys[input[i]]--; 
        }

        for (int i = 0;i< places.size();i++)
        {
            input[i] = places[i];
        }

    }





};




int main()
{

    Solution sol;

//    vector<int> input = {5, 3, 2, 3, 4, 2, 1};
    
  //  sol.heapSort(input);
    
    
//    vector<int> input = {1, 3, 1, 7, 5, 2, 4};
  //  sol.countingSort(input);
    
    
    vector<int> input = {170, 45, 75,  90, 802, 24, 2, 66};
    sol.radixSort(input);
    
    sol.printVector(input);

}