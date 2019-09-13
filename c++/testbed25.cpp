#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        

        int hayLen = haystack.length();
        int needleLen = needle.length();

        if (hayLen == 0 && needleLen == 0)
            return 0;

        if (needleLen > hayLen)
            return -1;
        
        for (int i = 0;i < (hayLen-needleLen+1);i++)
        {
            string ss = haystack.substr(i,needleLen); 
            
            if (ss.compare(needle) == 0)
            {
                return i;
            }

        }
        return -1;
    }
};

int main()
{
    Solution sol;

//    string hay = "hello";
  //  string needle = "ll"; //2
    string hay = "";
    string needle = ""; //2

    int ret = sol.strStr(hay,needle);

    cout << "ret: " << ret << endl;

}