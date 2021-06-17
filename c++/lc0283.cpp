#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:


    template <class BidirectionalIterator, class UnaryPredicate>
    BidirectionalIterator partition (BidirectionalIterator first,
                                   BidirectionalIterator last, UnaryPredicate pred)
    {
        while (first!=last) {
            while (pred(*first)) {
                ++first;
                if (first==last) return first;
            }
    
            do {
                --last;
                if (first==last) return first;
            } while (!pred(*last));
    
            std::swap (*first,*last);
            ++first;
        }
        return first;
    }

    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        //std::stable_partition(nums.begin(), nums.end(), [&](auto a){ return a != 0;});

        int index = 0;

        for (int i = 0;i< nums.size();i++)
        {   
            if (nums[i] != 0)
            {
                nums[index++]= nums[i];
            }
        }

        for (int i = index;i < nums.size();i++)
        {
            nums[i] = 0;
        }

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


int main ()
{
    vector<int> input = {0,1,0,3,12};
    Solution sol;
    sol.printVector(input);
    sol.moveZeroes(input);
    sol.printVector(input);
    
}