#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> map;

        for (int i = 0;i < s.length();i++)
        {
            char c = s[i];
            if (map.find(c) == map.end())
            {
                map[c] = i;
            }
            else
            {
                map[c] = -1;
            }
        }

        int mmin = INT_MAX;

        for (auto it = map.begin(); it != map.end();it++)
        {
            auto val = (*it).second;

            if (val != -1)
            {
                mmin = min(mmin, val);
            }
        }

        return (mmin == INT_MAX) ? -1 : mmin; 
    }

};


int main()
{
    Solution sol;
    string s = "loveleetcode"; //2
    int res = sol.firstUniqChar(s);

    cout << "result: " << res << endl;

    s = "aaaaaaaaauloveleetcode"; //2
    res = sol.firstUniqChar(s);

    cout << "result: " << res << endl;

}