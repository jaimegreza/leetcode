#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;



bool hasRepeatingChars(string s)
{

    int len = s.length();

    if (len == 1)
        return false;

    for (int i = 0;i < len ;i++)
    {
        string ss = s.substr(i,1); 
        size_t pos = s.find(ss,i+1); 

        if( !(static_cast<int>(pos) < 0))
        {
            return true;
        }   
    }
    return false;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<string,int> map;

        int len = s.length();
        int mmax = 0;
        int start = 0;

        for (int i = 0;i < len;i++)
        {
            string ss = s.substr(i,1); 
            

            if ((map.find(ss) != map.end()) &&
                (map[ss] >= start))
            { 
                start = map[ss] + 1;
            }

            map[ss] = i;
            mmax = max(mmax, i - start + 1);

        }

        return mmax;
    }   
};

class SolutionSlow {
public:
    int lengthOfLongestSubstring(string s) {
        
        int count = 0;
        int len = s.length();
            
        int maxLen = 0;

        for (int i = 1;i <= len;i++)
        {
            for (int j=0;j<=len-i;j++)
            {

                int curLen =0;
                string ss = s.substr(j,i); 
                curLen = ss.length();
                cout << "substr: " << ss << endl;

                bool bRepeat = hasRepeatingChars(ss);
 

                if (!bRepeat)
                    maxLen = curLen;
            }
        }
        return maxLen;
    }
};


int main()
{
//    string s1 = "abcabcbb";
    string s1 = "abcabcbb";

    Solution sol;

    int num = sol.lengthOfLongestSubstring(s1);
       
    cout << "num: " << num << endl;
    return 0;
}