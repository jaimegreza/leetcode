#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

//        unordered_map<string,int> map;

        int len = s.length();
        int result = 0;
        int value = 0;
        string previous = "";

        for (int i = 0;i < len;i++)
        {
            string ss = s.substr(i,1); 

                if (ss.compare("I") == 0)
                {
                    value = 1;
                }    
                else if (ss.compare("V") == 0)
                {
                    value = 5;
                }
                else if (ss.compare("X") == 0)
                {
                    value = 10;
                }    
                else if (ss.compare("L") == 0)
                {
                    value = 50;
                }    
                else if (ss.compare("C") == 0)
                {
                    value = 100;
                }    
                else if (ss.compare("D") == 0)
                {
                    value = 500;
                }    
                else if (ss.compare("M") == 0)
                {
                    value = 1000;
                }    

                result = result+value;

                if (previous.compare("I") == 0)
                {
                    if (ss.compare("V") == 0)
                    {
                        result =  result - 1 - 5;
                        result = result + 4;
                    }
                    else if (ss.compare("X") == 0)
                    {
                        result =  result - 1 - 10;
                        result = result + 9;
                    }    
                }    
                else if (previous.compare("X") == 0)
                {
                    if (ss.compare("L") == 0)
                    {
                        result =  result - 10 - 50;
                        result = result + 40;
                    }
                    else if (ss.compare("C") == 0)
                    {
                        result =  result - 10 - 100;
                        result = result + 90;
                    }
                }
                else if (previous.compare("C") == 0)
                {
                    if (ss.compare("D") == 0)
                    {
                        result = result - 100 - 500;
                        result = result + 400;
                    }
                    else if (ss.compare("M") == 0)
                    {
                        result =  result - 100 - 1000;
                        result = result + 900;
                    }
                }    

                previous = ss;

        }

        return result;
    }
};
/*

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

*/

int main()
{
    Solution sol;
    //string s = "III"; //3
   // string s = "IX"; //9
    //string s = "LVIII";//58
    string s = "MCMXCIV"; //1994
   // string s = "DCXXI"; // 621


    int result = sol.romanToInt(s);

    cout << "valu: " << result << " : " << s << endl;

}