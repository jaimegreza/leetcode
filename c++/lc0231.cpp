#include <iostream>
#include <vector>

using namespace std;


class Solution
{
    public:
         bool isPowerOfTwo(int n) {
        
             while (n > 1)
             {
                 int rem = n % 2;

                 if (rem > 0)
                    return false;
                 n = n >> 1;
             }
             return true;
        }

};


int main()
{   
    Solution sol;
    int input = 1;
    cout << input << " is power of 2? " << sol.isPowerOfTwo(input) << endl;

    input = 16;
    cout << input << " is power of 2? " << sol.isPowerOfTwo(input) << endl;

    input = 218;
    cout << input << " is power of 2? " << sol.isPowerOfTwo(input) << endl;

    input = 256;
    cout << input << " is power of 2? " << sol.isPowerOfTwo(input) << endl;

    input = 1024;
    cout << input << " is power of 2? " << sol.isPowerOfTwo(input) << endl;

}