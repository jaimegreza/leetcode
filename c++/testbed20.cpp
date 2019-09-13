#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        

        int size = strs.size();

        string prefix = "";

        if (size == 0)
            return prefix;

        if (size == 1)
            return strs[0];

        int minLen = INT_MAX;
        int shortIndex = -1;

        for (int i = 0;i < size;i++)
        {
            string str = strs[i];
            int len = str.length();
            if (minLen > len)
            {
                minLen = len;
                shortIndex = i;
            }
        } 

        if (minLen == 0)
            return prefix;

        prefix = strs[shortIndex];

        for (int i = 0;i < size;i++)
        {
            string str = strs[i];

            for (int j = 0;j < minLen;j++)
            {
                string s = prefix.substr(0,j+1);
                string ss = str.substr(0,j+1); 

                if (ss.compare(s) == 0)
                {
                    continue;
                }
                else
                {
                    prefix = prefix.substr(0,j);
                    minLen = prefix.length();
                    break;
                }
            }
        }

        return prefix;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    //vector<string> strs = {"dog","racecar","car"};
//     vector<string> strs = {"c","c"};
   //   vector<string> strs = {"a","a","b"};
   // vector<string> strs = {"c","acc","ccc"};
   //  vector<string> strs = {"aac","acab","aa","abba","aa"};

    string result = sol.longestCommonPrefix(strs);
    cout << "prefix: " << result << endl;
    

}
