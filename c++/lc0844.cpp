#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    template<class InputIterator>
    auto backspaceProcess(InputIterator first, InputIterator last)
    {
        InputIterator next, current;
        current = first;
        next = first;

        if (first!=last) 
        {            
            next++;

            while (next != last) 
            {
                int cnt = 0;
                while ( *next == '#')
                {
                    cnt++;
                    next++;
                }
                InputIterator temp = current;
                while (cnt > 0)
                {
                    if ((current >= first))
                    {
                        *current = '#';
                        current--;
                        if (current == first)
                        {
                            *current = '#';
                            break;    
                        }

                        cnt--;
                    }
                }
                current = temp;

                if (next != last)
                {
                    current++;
                    next++;
                }
            }          

            current = first;
            next = first;
            next++;

            while (next !=last) 
            {
                if ( *next != '#')
                {
                    while (*current != '#')
                            current++;
                    std::iter_swap(current,next);
                    current++;
                }
                next++;
            } 
        }
        
        return std::distance(first,current);
    }

    bool backspaceCompare(string S, string T) {
        int s = backspaceProcess(std::begin(S), std::end(S));
        int t = backspaceProcess(std::begin(T), std::end(T));

        if (s != t)
            return false;
        
        for (int i = 0;i< s;i++)
        {
            if (S[i] != T[i])
            {
                return false;
            }
        }

        return true;
    }
};


int main()
{
    Solution sol;

    string s = "a##c";
    string t = "#a#c";

    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    
    bool res = sol.backspaceCompare(s,t);

    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    cout << res << endl;


}