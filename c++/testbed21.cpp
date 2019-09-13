#include <iostream>
#include <stack>
#include <string>

using namespace std;


class Solution {
public:
    bool isValid(string s) {

        stack<string> st;

        if (s == "")
            return true;
        
        if (s.length()%2 == 1)
            return false;

        for (int i = 0; i < s.length();i++)
        {
            string ss = s.substr(i,1);

            if (    (ss.compare("{") == 0) ||
                    (ss.compare("[") == 0) ||
                    (ss.compare("(") == 0) )
            {
                st.push(ss);
            }

            if (    (ss.compare("}") == 0) ||
                    (ss.compare("]") == 0) ||
                    (ss.compare(")") == 0) )
            {
                if (st.empty())
                    return false;

                string parend = st.top();
                st.pop();

                if (ss.compare("}") == 0) 
                {
                    if (parend.compare("{") != 0)
                        return false;
                } else if (ss.compare("]") == 0) 
                {
                    if (parend.compare("[") != 0)
                        return false;
                } else if (ss.compare(")") == 0) 
                {
                    if (parend.compare("(") != 0)
                        return false;
                }
                else
                    return false;

            }




        }
         if (!st.empty())
                return false;

        return true;

    }
};

int main()
{
    Solution sol;
   // string test1 = "{[]}"; // true;
    //string test1 = "()[]{}"; // true
//    string test1 = "([)]";// false
    string test1 = "((";// false

    bool isValid = sol.isValid(test1);

    cout << "isValid: " << isValid << endl;

    

}