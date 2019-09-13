#include <iostream>
#include <string>
using namespace std;

class ReverseWord
{
public:
    ReverseWord(){};

    void reverseWord(string str)
    {

        int n = str.length();
        
           // Swap character starting from two
           // corners
           for (int i=0; i<n/2; i++)
           {
                char temp = str[i];
                str[i] = str[n-i-1];
                str[n-i-1] = temp;
           }

           cout << str << endl;
    }


};

int main()
{

    string string1 = "abcdefg";
    string string2 = "abcdef";

    ReverseWord revWord;

    revWord.reverseWord(string1);

    return 0;
}