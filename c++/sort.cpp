#include <iostream>
#include <vector>
#include "algorithm.cpp"
//#include <algorithm>
//#include <numeric>
using namespace std;


class Solution {
public:

/*** Simple Sort ***/

    void sort(vector<int> &input)
    {
        if (input.size() <= 1)
            return;

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

    //template<typename BidirectionalIterator, typename T>
  //  void sort(BidirectionalIterator first, BidirectionalIterator last, T init)
    template<typename BidirectionalIterator>
    void sort(BidirectionalIterator first, BidirectionalIterator last)
    {
        while (first != last)
        {
            BidirectionalIterator it = first;
//            typename std::iterator_traits<BidirectionalIterator>::difference_type count, step;
    
            while (it != last)
            {
                if (*it < *first)
                {
                   std::iter_swap(it,first);
                }
                it++;
            }
            first++;
        }
    }


//    template<typename ForwardIterator, typename T>
  //  ForwardIterator first_less_than (ForwardIterator first, ForwardIterator last, T value) {
	  //  auto it = std::lower_bound (first, last, value);
	//    return (it == first ? last : --it);
    //}



/*** Selection Sort ***/
/** find minimum and put it in place , reduces swaps **/
    void selectionSort(vector<int> &input)
    {
        if (input.size() <= 1)
            return;

        for (int i = 0;i<input.size();i++)
        {
            int min = INT_MAX;
            int idx = -1;
            for (int j = i;j < input.size();j++)
            {
                if (input[j] < min)
                {
                    min = input[j];
                    idx  = j;
                }
            }

            int temp = input[idx];
            input[idx] = input[i];
            input[i] = temp;
            
        }
    }


/*** Insertion Sort ***/
/** shifting, single trickle  **/

    void insertionSort(vector<int> &input)
    {
        if (input.size() <= 1)
            return;

        for (int i = 1;i<input.size();i++)
        {

            int index = i;
            int value =  input[i];

            while (index > 0 && (input[index-1] > value))
            {
                input[index] = input[index-1];
                index--;
            }

            input[index] = value;
        }

    }


/*** Bubble Sort ****/
/** works on two elements next to each other **/
/** double bubble not shifting one value into a position **/
/** getting maximum into its final position picking up the max as bubble **/

    void bubbleSort(vector<int> &input)
    {
 
        if (input.size() <= 1)
            return;


        for (int i = input.size()-1;i >= 0;i--)
        {
            for (int j = 1; j <= i;j++)
            {
                if (input[j] < input[j-1])
                {
                    int temp = input[j];
                    input[j] = input[j-1];
                    input[j-1] = temp;
                }
            }
        }

    }

    template<typename BidirectionalIterator, class BinaryPredicate>
    void bubbleSort(BidirectionalIterator first, BidirectionalIterator last, BinaryPredicate pred)
    {
        while (first != last)
        {
            BidirectionalIterator cur = first;
            BidirectionalIterator next = first+1;
            while (next != last)
            {
                if (pred(*cur, *next))
                {
                   std::iter_swap(cur,next);
                }
                cur++;
                next++;
            }
            last--;
        }
    }

    template<typename BidirectionalIterator>
    void bubbleSort(BidirectionalIterator first, BidirectionalIterator last)
    {
        while (first != last)
        {
            BidirectionalIterator cur = first;
            BidirectionalIterator next = first+1;
            while (next != last)
            {
                if (*cur > *next)
                {
                   std::iter_swap(cur,next);
                }
                cur++;
                next++;
            }
            last--;
        }
    }

  /*  template <class RandomAccessIterator, class T>
    void bubbleSort(RandomAccessIterator first, RandomAccessIterator last, const T& value)
    {
        while (first != last)
        {
            RandomAccessIterator it = first;

        }

    }*/



/*** Quick Sort ****/
/** use a pivot / partition **/
/** divide and conquer ***/
/*** recursive ***/
/** lobbing stuff over the fence **/

    void quickSort(vector<int> &input)
    {

        if (input.size() <= 1)
            return;

        quickSort(input, 0 ,input.size()-1);
    

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
        
        int p = high+1;

        for (int j=high;j > low;j--)
        {
            if (input[j] >= input[low])
            {
                p--;
                int temp = input[p];
                input[p] = input[j];
                input[j] = temp;
            }
        }
 
        // swap pivot
        int temp = input[p-1];
        input[p-1] = input[low];
        input[low] = temp;
 
        return p-1;
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

int op_increase (int i) { return ++i; }
int compare (int a, int b) { return (a > b) ? a : b; }
bool greaterThan (int a, int b) { return (a > b) ? true : false; }
bool lessThan (int a, int b) { return (a < b) ? true : false; }
bool IsOdd (int i) {  return ((i%2)==1);}

int main()
{
    
    vector<int> input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    vector<int> result;
    result.resize(input.size());

    Solution sol;
    cout << "reduce " << endl;

    sol.printVector(input);
    int res =  JIMMY::reduce(input.begin(),input.end(),(int) 10);
    cout << "res: " <<  res << endl;
    cout << "transform: " << endl;
    JIMMY::transform_reduce(input.begin(),input.end(),result.begin(),10);
    sol.printVector(result);
    sol.printVector(input);
    JIMMY::transform(input.begin(),input.end(),result.begin(),op_increase);    
    sol.printVector(result);

    cout << "transform: plus (2 index)" << endl;
    sol.printVector(input);
    JIMMY::transform(input.begin(),input.end(), result.begin(), input.begin(), std::plus<int>());   
    sol.printVector(input);
    sol.printVector(result);

    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    cout << "transform: compare " << endl;
    sol.printVector(input);
    JIMMY::transform(input.begin(),input.end()-1, input.begin()+1, input.begin(), compare);   
    sol.printVector(input);

    cout << "simple sort: " << endl;
    sol.printVector(input);
    sol.sort(input);
    sol.printVector(input);

    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    cout << "simple iterator sort: " << endl;
    sol.printVector(input);
    sol.sort(input.begin(), input.end());
    sol.printVector(input);


    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    cout << "selection sort: " << endl;
    sol.printVector(input);
    sol.selectionSort(input);
    sol.printVector(input);


    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    cout << "insertion sort: " << endl;
    sol.printVector(input);
    sol.insertionSort(input);
    sol.printVector(input);



    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};


    cout << "bubble sort: " << endl;
    sol.printVector(input);
    sol.bubbleSort(input);
    sol.printVector(input);

    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    cout << "bubble iter sort: " << endl;
    sol.printVector(input);
    sol.bubbleSort(input.begin(), input.end());
    sol.printVector(input);

    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    cout << "bubble iter sort PRED: " << endl;
    sol.printVector(input);
    sol.bubbleSort(input.begin(), input.end(), greaterThan);
    sol.printVector(input);

    input = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    cout << "quick sort: " << endl;
    sol.printVector(input);
    sol.quickSort(input);
    sol.printVector(input);

 /*   vector<int> v = {5, 3, 2, 3, 4, 2, 1, 0, -1};

    auto it  = sol.first_less_than (v.begin (), v.end (), 3);
	auto it2 = sol.first_less_than (v.begin (), v.end (), 4);
	auto it3 = sol.first_less_than (v.begin (), v.end (), 8);

	cout << (it  != v.end () ? to_string (*it)  : "Not Found") << endl; // outputs 1
	cout << (it2 != v.end () ? to_string (*it2) : "Not Found") << endl; // outputs 3
	cout << (it3 != v.end () ? to_string (*it3) : "Not Found") << endl; // outputs 7
*/
}

