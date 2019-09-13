#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <string>


using namespace std;

class ReverseWord
{
private:
    char * str;

    void reverseWord()
    {
        int size = 0;

        while (*str++ != '\0')
        {
            size++;
        }

        str = str-size-1;
        char * begin = str;
        char * end = str+size-1;
        while (begin < end)
        {
            char temp = *begin;
            *begin++ = *end;
            *end-- = temp;
        }
    }

public:

    ReverseWord(string word)
    {
        str = word.c_str();
        reverseWord();
    }

    char * getWord()
    {
        return str;
    }


};


int main()
{

    ReverseWord word("hiya");
    char * reversed = word.getWord();

    cout << reversed << endl;

    vector<int> vec =  {1, 2, 3, 4, 5};
    vector<int>::iterator itr = vec.begin();
   // cout << vec;

   while (itr != vec.end())
	{
		cout << *itr++ << endl;
	}

    return 0;
}

