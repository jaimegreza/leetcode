#include <iostream>
#include <string>
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

Constrain:  Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
   

Conceive:   


Contract:   string longestPalindrome(string s)

*/

/* Construct */


class Solution {
public:
    string longestPalindrome(string s) {

        if (s.size() == 0)
            return s;

        if (s.size() == 1)
            return s;        

        if ( (s.size() == 2) && 
            (s[0] == s[1]))
            return s;        


        int bigLength = 1;
        string biggest = s.substr(0,1);

        int max  = 1;

        for (int i = 0;i < s.size()-1;i++)
        {
            for (int j=i+1;j < s.size();j++)
            {

                int curLen = j - i + 1;

                if (s[i] == s[j])
                {
                    if ((curLen == (bigLength + 2)) ||
                        (j - i) == bigLength )
                    {
                        biggest = s.substr(i,curLen);
                        bigLength = curLen;

                    }
                }
            }

        }

        return biggest;
    }

    int reverse(int x) {
        int res = 0;

        while (x != 0)
        {
            int ones = x % 10;
                        
            if (res > INT_MAX/10)  // Check for overflow before multiplying
            { 
                  return 0;        
            }
            
            res = res*10;
            
            if (res > (INT_MAX - ones))   // Check for overflow before adding
            {
                return 0; // Will overflow
            }   // + val;

            res = res + ones;
            x = x / 10;
        }    
        return res;
    }
};


/* Confirm */

int main()
{

    Solution sol;

   // string input = "babad";
   //string input = "cbbd";
    //string input = "bbb";
    string input = "abcba";
   
    string result = sol.longestPalindrome(input);

    cout << result << endl;

    int res = sol.reverse(-321111111333);

    cout << "rev: " << res << endl;
}



/*** LEETCODE ACCEPTANCE RESULTS

***/