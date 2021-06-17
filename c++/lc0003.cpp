#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

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

Constrain:  Given a string, find the length of the longest substring without repeating characters.
            substring is continuous part of the string, not a subsequence

            question: is z and Z the same character? do we worry about Capital letters?
            assume all lowercase.
   

Conceive:   (put ideas here from whiteboard , be honest)
            first i thought of using bits to store if i ran into the letter before but that only told me
            of their existence. I also need to know what position in the string they occurred so i will 
            try to use a map instead.


Contract:   int lengthOfLongestSubstring(string s) 

*/

/* Construct */


class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> map;

        if (s.length() <= 1)
            return s.length();

        int mmax = 0;
        int cur = 0;

        int start = 0;
        for (int i = 0;i< s.length();i++)
        {

            if ((map.find(s[i]) != map.end()) &&
                (map[s[i]] >= start))
            { 
                start = map[s[i]] + 1;
            }

            map[s[i]] = i;
            mmax = max(mmax, i - start + 1);

        }

        return mmax;

    }

    /* this worked but was very slow, i was reseting the index and clearing out my map so basically similar to n squared */

    int lengthOfLongestSubstringSlowButWorks(string s) {
        
        unordered_map<char,int> map;

        if (s.length() <= 1)
            return s.length();

        int max = 0;
        int cur = 0;

        for (int i = 0;i< s.length();i++)
        {
            if (map.find(s[i]) == map.end())
            {
                cur++;
                map[s[i]] = i;
                
                if (cur > max)
                    max = cur; 
            }
            else
            {
                i = map[s[i]];
                map.clear();
                cur = 0;                
            }

        }

        return max;

    }
};


/* Confirm */

int main()
{

    Solution sol;

    string a = "abcabcbb";

    int result = sol.lengthOfLongestSubstring(a);

    cout << a  << " - " << result << endl;


    string b = "bbb";

    result = sol.lengthOfLongestSubstring(b);

    cout << b << " - " << result << endl;


    string c = "pwwkew";

    result = sol.lengthOfLongestSubstring(c);

    cout << c <<  " - " << result << endl;


    string d = "aab";

    result = sol.lengthOfLongestSubstring(d);

    cout << d <<  " - " << result << endl;


    string e = "dvdf";
    result = sol.lengthOfLongestSubstring(e);

    cout << e <<  " - " << result << endl;

}



/*** LEETCODE ACCEPTANCE RESULTS
Runtime: 732 ms, faster than 7.29% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 143.5 MB, less than 8.96% of C++ online submissions for Longest Substring Without Repeating Characters.
***/