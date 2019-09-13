#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {

        if (s.length() == 0)
            return 0;

        if ((s.length() == 1) && (s.compare(" ") == 0))
            return 0;

        if (s.length() == 1)
            return 1;

        int cur = 0;
    	int beg = -1;
	    int end = -1;

        int lenLastWord = 0;
        bool startWord = false;
    	while (cur < s.size())
	    {
			if (cur == (s.size() - 1)) // end of string
			{ 
                if (s[cur] != ' ')
                {
                    if (beg == -1)
                    {
                        beg = cur;
                        startWord = true;
                    }
                    end = cur;
                }   
                if (startWord)
                {
                    lenLastWord = (end - beg + 1);
                }
            }

            if  (s[cur] == ' ')
            {
                if (startWord)
                {
                    lenLastWord = (end - beg +1);
                    beg = cur;
                    end = cur;
                    startWord = false;
                }
            }
            else
            {
                if (!startWord)
                {
                    beg = cur;
                    end = cur;
                    startWord = true;
                }
                if (startWord)
                    end=cur;
            }

        	cur++;
	    }

        return lenLastWord;
    }
};
int main()
{
    Solution sol;
//    string str = "This   is   Amazon";
    //string str = "  123  ";
//    string str = "  1  ";
    //string str = "  1";
    int ret = sol.lengthOfLastWord(str);

    cout << "ret: " << ret << endl;

}