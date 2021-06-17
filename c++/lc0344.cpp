#include <iostream>
#include <vector>

using namespace std;


class Solution
{
    public:

    template<class InputIterator1>
    void reverse(InputIterator1 first1, InputIterator1 last1)
    {
            while (first1 < --last1)
            {
                std::iter_swap(first1,last1);
                first1++;
            }
    }

     void reverseString(vector<char>& s) 
     {

         reverse(s.begin(),s.end());
     } 

      void printVector(vector<char> input)
    {
        for (int i = 0;i< input.size();i++)
        {
            cout << input[i] << " " ;

        }
        cout << endl;
    }

};

int main()
{
    Solution sol;
    vector<char> input1 = {'h','e','l','l','o'};
    sol.printVector(input1);
    sol.reverseString(input1);
    sol.printVector(input1);

    string s  = "mothersucker";
    vector<char> input2(s.begin(),s.end());
    sol.printVector(input2);
    sol.reverseString(input2);
    sol.printVector(input2);

}