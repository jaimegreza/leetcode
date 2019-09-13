#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        if (digits.size() == 0)
            return digits;
        
        int sum = 0;
        int carry = 0;

        int size = digits.size();
        for (int i=size-1;i >= 0;i--)
        {
                
            sum = digits[i] + carry;

            if (i == (size-1))
                sum = sum + 1;

            carry = (sum >= 10) ? 1 : 0 ;
            sum = sum % 10;

            if ((i == 0) && carry)
            {
                digits[i] = sum;
                digits.insert(digits.begin() , carry);
            }
            else
            {
                digits[i] = sum;
            }
        }          

        //   
        return  digits;
    }
};

int main()
{
//    vector<int> digs = {4,3,2,1};
    vector<int> digs = {1,9,9};

    Solution sol;

    vector<int> output = sol.plusOne(digs);

    for (int i = 0;i < output.size();i++)
    {
        cout << output[i] << endl;
    }
}