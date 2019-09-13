#include<iostream>

using namespace std;


class Solution {
private:
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


public:
    bool isPalindrome(int x) {

        if (x < 0)  return false;

        int reversed = reverse(x);

        if (x == reversed)
            return true;

        return false;
    }
};

int main()
{
    Solution sol;
    int test1 = 121;
    bool isPal = sol.isPalindrome(test1);

    cout << "palindrome: " << isPal << " : " << test1 << endl;
}