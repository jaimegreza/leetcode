#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;

class Solution
{
public:

    int findNthDigit(int n) {
        // 1 2 3 4 5 6 7 8 9 10 11  - 0 is 11th
        int cnt = 0;
        while (n > 0)
        {
            int rem = n % 10;

            n = n/10;

            if (n == 0)
                return cnt;
            cnt++;
        }

        return 0;

    }

    char findTheDifference(string s, string t) {

        map<char,int> map;

        char extra;

        for (int i = 0;i < t.size();i++)
        {
            map[t[i]] = map[t[i]] + 1;
        }

        for (int i = 0;i < s.size();i++)
        {
            if (map[s[i]] > 0)
            {
               map[s[i]]--;

               if ( map[s[i]] == 0)
               {
                   map.erase(s[i]);
               }
            }
        }

        for (auto itr : map)
        {
            pair<char, int> p = (pair<char,int>) itr;
            extra = p.first;
        }
        return extra;

    }

    int firstUniqCharFast(string s) {
        
        if (s.size() == 0)
            return -1;
        
        if (s.size() == 1)
            return 0;

        unordered_map<char,int> map;

        int  idx = -1;

        for (int i = 0;i < s.size();i++)
        {
            map[s[i]] = map[s[i]] + 1;
        }

        for (int i = 0;i < s.size();i++)
        {
            if (map[s[i]] == 1)
            {
                return i;
            }

        }

        return -1;

    }

        int firstUniqChar(string s) {
        
        if (s.size() == 0)
            return -1;
        
        if (s.size() == 1)
            return 0;

        map<char,int> map;

        for (int i = 0;i < s.size();i++)
        {
            map[s[i]] = map[s[i]] + 1;
        }

        for (int i = 0;i < s.size();i++)
        {
            if (map[s[i]] == 1)
            {
                return i;
            }

        }

        return -1;

    }

    bool canConstruct(string ransomNote, string magazine) {

         if ( magazine.size() < ransomNote.size() ) {
            return false;
        }        
       map<char,int> map;

        for (int i=0;i< magazine.size();i++)
        {
            map[magazine[i]] = map[magazine[i]] + 1;
        }

        for (int i=0;i< ransomNote.length();i++)
        {
            if (map.find(ransomNote[i]) != map.end())
            {
                if (map[ransomNote[i]] > 0)
                {
                    map[ransomNote[i]] = map[ransomNote[i]] -1;
                }
                else    
                    return false;    
            }
            else
                return false;

        }

        return true;

    }

    int getSum(int a, int b) {

        int mask = 1;
        int result = 0;

        for (int i = 0;i<32;i++)
        {
            int as = a & mask;
            int bs = b & mask;

            if (as != bs) 
            {
                if (result & mask)
                {
                    result = result ^ mask;
                    result = result | (mask << 1);
                }
                else
                    result = result | mask;
                
            }

            if ((as == bs) && (as != 0))
            {
                if (result & mask)
                {
                    result = result | (mask << 1);
                    result = result | mask;
                }
                else
                    result = result | (mask << 1);
            }

            mask = mask << 1;

        }

        return result;
    }
};


int main()
{
    Solution sol;
    cout << " sum : " << sol.getSum(20,30) << endl;


}