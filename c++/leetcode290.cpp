#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;


class Solution{
public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<string,char> map;
        set<char> set;

        int indx = 0;
        
        int count = 0;

        for (int i = 0;i< pattern.length();i++)
        {
            string temp;

            if (str[indx] == '\0')
                break;
            
            if (str[indx] == ' ')
                indx++;

            while((str[indx] != ' ') && (indx <= (str.length()-1)))
            {
                temp = temp + str[indx];
                indx++;
            }

            count++;

            if (map.find(temp) == map.end())
            {
                if(set.find(pattern[i]) == set.end())
                {
                    map[temp] = pattern[i];
                    set.insert(pattern[i]);
                }
                else
                    return false;
            }
            else
            {
                char p = map[temp];

                if (p != pattern[i])
                    return false;

            }
           

        }
        cout << "count: " << count << endl;

        if (count != pattern.length())
            return false;

        cout << "idx: " << indx << endl;

        if (indx != str.length() )
            return false;

        return true;
    }   

};
int main()
{
    string pat = "abc";
    string str = "b c a";

    Solution sol;

    cout << "pattern match: " << sol.wordPattern(pat,str) << endl;


}