#include <iostream>


using namespace std;


class Solution
{
    public:

    template <class InputIterator1, class InputIterator2>
    std::pair<InputIterator1, InputIterator2>
        mismatch (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while ( (first1!=last1) && (*first1==*first2) )  // or: pred(*first1,*first2), for version 2
        { ++first1; ++first2; }
        
        return std::make_pair(first1,first2);
    }


    template <class InputIterator1, class InputIterator2>
        bool is_permutation (InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2)
    {
        std::tie (first1,first2) = mismatch (first1,last1,first2);
        
        if (first1==last1) return true;
        
        InputIterator2 last2 = first2; 
        std::advance (last2,std::distance(first1,last1));
        
        for (InputIterator1 it1=first1; it1!=last1; ++it1) {
            if (std::find(first1,it1,*it1)==it1) {
                auto n = std::count (first2,last2,*it1);
                if (n==0 || std::count (it1,last1,*it1)!=n) return false;
            }
        }
        return true;
    }
    
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        return isAnagram(std::begin(s), std::end(s), std::begin(t));
    }


    template <class InputIterator1, class InputIterator2>
    bool isAnagram(InputIterator1 first1,  InputIterator1 last1, InputIterator2 first2)
    {

        int arr[26] = {0};

        std::tie (first1,first2)  = mismatch(first1, last1, first2);
        if (first1==last1) return true;
        
        InputIterator2 last2 = first2; 
        std::advance (last2,std::distance(first1,last1));
        
        for (InputIterator1 it1=first1; it1!=last1; ++it1) 
        {
            int idx = *it1 - 'a';
            arr[idx] += 1;
        }

        for (InputIterator2 it2=first2; it2!=last2; ++it2) 
        {
            int idx = *it2 - 'a';
            arr[idx] -= 1;
        }

        for (int i = 0; i < 26;i++)
        {
            if (arr[i] != 0)
                return false;
        }

        return true;

       // return is_permutation(std::begin(s), std::end(s), std::begin(t));

    }

    bool isPalindrome(string s) {
        int beg = 0;
        int end = s.length()-1;
        
        while (beg <= end)
        {
            if (!std::isalnum(s[beg]))
            {
                beg++;
                continue;
            }
            if (!std::isalnum(s[end]))
            {
                end--;
                continue;
            }
            
            if (std::tolower(s[beg]) != std::tolower(s[end]))
                return false;           
            
            end--;
            beg++;
        }
                
        return true;
        
    }


};

int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s,t) << endl;

    string pal = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(pal) << endl;

}