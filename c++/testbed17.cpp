#include <iostream>
#include <stack>
#include <algorithm> 
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        if (x == 0)
            return 0;

        bool isNeg = (x < 0) ? true : false;
        int reversed = 0;

        while (abs(x) > 0)
        {
            int val = abs(x) % 10;

            if (reversed > INT_MAX/10)  // Check for overflow before multiplying
            { 
                  return 0;        
            }
            reversed = reversed*10;
            
            if (reversed > (INT_MAX - val))   // Check for overflow before adding
            {
                return 0; // Will overflow
            }   // + val;
            reversed = reversed + val;

            x = x / 10;
        
        }

  
        if (isNeg)
            reversed = -1*reversed;
        return reversed;

    }
};


int main()
{
    Solution sol;

    //int test1 = 1534236469;
    int test1 = 321;

    int result = sol.reverse(test1);
    
    cout << "forward: " << test1 << endl;
    cout << "reverse: " << result << endl;
    return 0;
}