#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution
{
    public:


    bool wordLadder(vector<string> &words, string begin, string target)
    {

        char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        // process words into a set
        unordered_set<string> dict;

        for (string w : words)
        {
            dict.insert(w);
        }

        unordered_set<string> frontier;
        unordered_set<string> next;

        frontier.insert(begin);

        int size = target.length();
        int idx = 0;
        while (!frontier.empty())
        {

            next.clear();
            if (idx == size)
                break;

            for (string cur : frontier)
            {
                string word = cur;

                for (int j = 0; j < size;j++) 
                {               
                    for (char c : letters)
                    {  
                        word[j] = c;

                        if (word.compare(target) == 0)
                            return true;

                        if (dict.find(word) != dict.end())
                            next.insert(word);
                    }
                    word[j] = cur[j];
                }
            }
            
            frontier = next;
            idx++;
        }

        return false;

    }


};

int main()
{

    Solution sol;


    vector<string> words = { "hot","dot","dog","lot","log","cog"};
    string begin = "hit";
    string end = "cog";

    bool res = sol.wordLadder(words, begin, end);

    cout << "word ladder matched?: " << res << endl;


}