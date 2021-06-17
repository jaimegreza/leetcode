#include <iostream>
#include <unordered_set>
#include <unordered_map>


using namespace std;


class Solution {


public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> set;
        int count  = 0;

        for (char c : J)
        {
            set.insert(c);
        }

        for (char c : S)
        {
            if (set.find(c) != set.end())
            {
                count++;
            }
        }
        return count;
    }
};


int main()
{
    Solution sol;

    string J = "aA";
    string S = "aaaAAbbbA";

    cout << "num jewels: " << sol.numJewelsInStones(J,S) << endl;
}