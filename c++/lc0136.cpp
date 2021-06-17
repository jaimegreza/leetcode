#include <iostream>
#include <vector>

using namespace std;


class Solution
{

    public:

    template <class BidirectionalIterator>
    void reverse (BidirectionalIterator first, BidirectionalIterator last)
    {
        while ((first!=last)&&(first!=--last)) {
            std::iter_swap (first,last);
            ++first;
        }
    }

    template <class InputIterator, class OutputIterator, class UnaryOperator>
    OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op)
    {
        while (first1 != last1) {
            *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
            ++result; ++first1;
        }
        return result;
    }

   template <class InputIterator, class T, class BinaryOp>
    T   reduce(InputIterator first, InputIterator last, T init, BinaryOp b)
    {
        for (; first != last; ++first)
            init = b(init, *first);
        return init;
    }

    template <class InputIterator1, class InputIterator2, class T, class BinaryOp1, class BinaryOp2>
    T   transform_reduce2(   InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, T init,  BinaryOp1 b1, BinaryOp2 b2)
    {
        for (; first1 != last1; ++first1, (void) ++first2)
            init = b1(init, b2(init, *first2));
        return init;
    }

    template <class InputIterator1, class InputIterator2, class OutputIterator, class BinaryOperation>
    OutputIterator transform (InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, OutputIterator result,
                            BinaryOperation binary_op)
    {
        while (first1 != last1) {
            *result=binary_op(*first1,*first2++);
            ++result; ++first1;
        }
        return result;
    }



    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int result = 0;
        return reduce(nums.begin(), nums.end(), result, [&](int a, int b){return a ^ b;});    
        
    }
    int singleNumber2(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        printVector(nums);
        transform(nums.begin(), nums.end(), nums.begin(),nums.begin(), [&](int a, int b){return a ^ b;}); 
        printVector(nums);
        int result = 0;
        return reduce(nums.begin(), nums.end(), result, [&](int a, int b){return (a ^ b) | b;});
    }


    template <class InputIterator, class OutputIterator>
    OutputIterator adjacent_difference (InputIterator first, InputIterator last,
                                       OutputIterator result)
    {
        if (first!=last) {
            typename std::iterator_traits<InputIterator>::value_type val,prev;
            *result = prev = *first;
    
            while (++first!=last) {
                val = *first;
                *++result = prev  - val;  // or: *++result = binary_op(val,prev)
                prev = val;
            }
            ++result;
        }
        return result;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 1)
            return res;

        int n = nums.size();
        int actual = n * ( n + 1) / 2;

        adjacent_difference(nums.begin(),nums.end(),nums.begin());
        nums[0] = 0;

        for (int i= 0;i<nums.size();i++)
        {
            if (std::find(res.begin(), res.end(), abs(nums[i])) == res.end())
            {
                if (nums[i] != 0)
                    res.push_back(abs(nums[i]));
            }
        }

        

        return res;
    }

     int removeDuplicates(vector<int>& nums) {

         if (nums.size() == 0)
            return 0;

         if (nums.size() == 1)
            return 1;

         int index  = 1;
         for (int i = 0;i < nums.size() - 1;i++)
         {
             if (nums[i] != nums[i+1])
             {
                 nums[index] = nums[i+1];
                 index++;
             }
         }

         return index;

     }


     int removeDuplicates2(vector<int>& nums) {
 
         int size = nums.size();

        if (size == 0)
            return 0;

        if (size == 1)
            return 1;
        
         if (size == 2)
         {
            return (nums[0] == nums[1]) ? 1 : size;
         }
        int leftIndex = 0; // valid 
        int rightIndex = 1;
        int nextIndex = 1;  

        int newSize = 1;
        while (rightIndex < size)
        {
            if (nums[leftIndex] != nums[rightIndex])
            {
                leftIndex++;
                rightIndex++;
                newSize++;
                if (leftIndex == nextIndex)
                    nextIndex++;
                continue;
            }
            else
            {
                bool bExit = false;
                while (nums[leftIndex] == nums[rightIndex])
                {
                    rightIndex++;
                    if (rightIndex == size)
                    {
                        bExit = true;
                        break;
                    }
                }
                if (bExit)
                    break;
            
// 0 1 2  1 0 3 4 5
//     l      r 
//        n               
                nums[nextIndex] = nums[rightIndex];
                leftIndex++;
                nextIndex++;
                rightIndex++;
                newSize++;
            }
        }
        cout << "left: " << leftIndex << endl;
        cout << "right: " << rightIndex << endl;
        cout << "next: " << nextIndex << endl;
        cout << "size: " << newSize << endl;
        

        return newSize;

    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

            vector<vector<int>> res;

            for (int r =0;r< A[0].size();r++)
            {
                vector<int> row = A[r];
                reverse(row.begin(),row.end());
                vector<int> flipped = row;
                transform(flipped.begin(),flipped.end(), flipped.begin(), [&](int a){ return a ^1;});
                res.push_back(flipped);
            }
        
            return res;
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
    
    vector<int> input = {2,2,1};

    cout << "single number: " << sol.singleNumber(input) << endl;
    input = {2,2,8,3,4,4,3};

    cout << "single number: " << sol.singleNumber(input) << endl;

 //   input = {0,1,0,1,0,1,99};
  //  cout << "single number: " << sol.singleNumber(input) << endl;
   // sol.printVector(input);

//    input = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
    
//    cout << "single number: " << sol.singleNumber(input) << endl;
 //   sol.printVector(input);


    vector<int> res;
    input = {1,2,2,3,5};
    sol.printVector(input);
    res = sol.findDisappearedNumbers(input);
    sol.printVector(input);
    sol.printVector(res);

    cout << "remove dups: " << endl;
    input = {1,1,2,3};
   // input = {0,0,1,1,1,2,2,3,3,4};
   // input = {1,1,1};
    sol.printVector(input);
    cout << endl;
    cout << "size: " << sol.removeDuplicates(input) << endl;
    cout << endl;
    sol.printVector(input);
    
}


