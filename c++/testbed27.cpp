#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 0)
         return "";

        if (n == 1)
            return "1"; 

        string result;

        result = countAndSay(n-1);
        int len = result.length();

        if (len == 1)
        {
            return "11";
        }

        string curr;
        curr = result[0];
        int count = 1;

        string ans;

        for (int i = 1;i <= len;i++)
        {
            string ss = result.substr(i,1);

            if (i == (len-1))
            {
                if (curr.compare(ss) == 0)
                    count++;  

                string intStr;
                intStr = to_string(count);
                ans = ans.append(intStr);
                ans = ans.append(curr);
                
                if (curr.compare(ss) != 0)
                {
                    ans = ans.append("1");
                    ans = ans.append(ss);
                }
                
                break;
            } 


            if ((curr.compare(ss) == 0) &&
                ( i != (len-1)))
            {   
                count++;
            }
            else
            {
                if ((curr.compare(ss) == 0) && 
                    (i == (len-1)))
                    count++;

                string intStr;
                intStr = to_string(count);
                ans = ans.append(intStr);
                ans = ans.append(curr);
                curr = ss;
                count=1;
                     
            }

        }
        return ans;       

    }
};
/*
1.     1
2.     11
3.     21
4.     1211
5.     111221
*/
int main()
{   
    Solution sol;

    string res = sol.countAndSay(5);

    cout << "res: " << res << endl;

}