#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<vector<char>> dial = {{},
                                {},
                                {'a','b','c'},
                                {'d','e','f'},
                                {'g','h','i'},
                                {'j','k','l'},
                                {'m','n','o'},
                                {'p','q','r','s'},
                                {'t','u','v'},
                                {'w','x','y','z'}
                            };

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.length() == 0)
            return res;
        letterCombinations(res, digits, "",0);
        return res;
    }

    void letterCombinations(vector<string> &res, string &digits, string current, int index) {
        
        if (index == digits.length())
        {
            res.push_back(current);
            return;
        }

        char digit = digits.at(index);
        int idx = digit-'0';

        vector<char> letters = dial[idx];
        
        for (int j = 0;j<letters.size(); j++)
        {
            char letter = letters[j];
            string temp = current;
            temp.push_back(letter); 
            letterCombinations(res, digits, temp,index+1);
        }

    }

    void printVector(vector<string> input)
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

    string dial = "23";

    vector<string> result;
    result = sol.letterCombinations(dial);
    sol.printVector(result);
}