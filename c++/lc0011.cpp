#include <iostream>
#include <vector>
#include "algorithm.cpp"

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

Constrain:  
   

Conceive:   (put ideas here from whiteboard , be honest)


Contract:   

*/

/* Construct */


class Solution {
public:
    int maxArea(vector<int>& height) {

        return maxArea(height.begin(), height.end(),0);
        
    }

    template <class InputIterator, class T>
    T maxArea(InputIterator first, InputIterator last, T init)
    {
        T max = init;
            
        InputIterator next = first;
    
        while (++next != last)
        {
            T cur = std::min(*first, *next);

            T dist = std::distance(first,next);
            max = std::max(cur*dist, max);

            if (*next > *first)
            {
                first = next;
            }
        }
        return max;

    }

};


/* Confirm */

int main()
{

    Solution sol;
    
    vector<int> input = {1,8,6,2,5,4,8,3,7};

    int result = sol.maxArea(input);
    cout << "max area: " << result << endl;

    input = {1,2,1};
    result = sol.maxArea(input);
    cout << "max area: " << result << endl;


}



/*** LEETCODE ACCEPTANCE RESULTS

***/