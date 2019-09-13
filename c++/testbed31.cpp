#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        string s;

        int lenA = a.length();
        int lenB = b.length();
 

        int sum = 0;
        int carry = 0;

        int diff = (lenA > lenB) ? (lenA - lenB) : (lenB - lenA);
        int big =  lenA > lenB ? lenA : lenB;
        int com = big - diff;

        bool useA = (lenA > lenB);

        string revA = reverse(a);
        string revB = reverse(b);
        
        for (int i = 0; i < com;i++)
        {
            int a1 = atoi(revA.substr(i,1).c_str());
            int b1 = atoi(revB.substr(i,1).c_str());

            sum = a1 + b1 + carry;

            carry = (sum >= 2) ? 1 : 0 ;
            sum = sum % 2;

            s.append(to_string(sum));

        }
        // carry;
        if (useA)
        {
            for (int i = com; i < lenA;i++)
            {
                int a1 = atoi(revA.substr(i,1).c_str());;
                sum = a1 + carry;

                carry = (sum >= 2) ? 1 : 0 ;
                sum = sum % 2;

                s.append(to_string(sum));
            }
        }

        if (!useA)
        {
            for (int i = com; i < lenB;i++)
            {
                int b1 = atoi(revB.substr(i,1).c_str());
                sum = b1 + carry;

                carry = (sum >= 2) ? 1 : 0 ;
                sum = sum % 2;

                s.append(to_string(sum));
            }
        }

        if (carry)
        {
            s.append("1");
        }

        return reverse(s);
    }

    string  reverse(string str)
    {

        string rev = str;

        int n = rev.length();
        
           // Swap character starting from two
           // corners
           for (int i=0; i<n/2; i++)
           {
                char temp = rev[i];
                rev[i] = rev[n-i-1];
                rev[n-i-1] = temp;
           }

           return rev;
    }
};

int main()
{
    Solution sol;
    string ret;
//    string str1 = "11";
 //   string str2 = "1"; ///100
    
//    string str1 = "1010"; //10101
 //   string str2 = "1011"; 
      string str1 = "1111"; //11110
      string str2 = "1111"; 
    
    ret = sol.addBinary(str1,str2);
    cout << "ret: " << ret << endl;
}