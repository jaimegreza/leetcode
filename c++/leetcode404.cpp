#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
     vector<string> fizzBuzz(int n) {

            vector<string> res;

            if (n ==0)
                    return res;

        res.resize(n);
        
         for (int i = 1 ;i <= n;i++)
{
             if ((i%5 == 0) && (i%3 == 0))
             {
                 res[i-1] = "FizzBuzz";
             }
             else if (i%5 == 0)
             {
                 res[i-1] = "Buzz";
             }
             else if (i%3 == 0)
             {
                 res[i-1] = "Fizz";
             }
             else{
                 res[i-1] = to_string(i);
             }

         }

        return res;
    }


    int longestPalindrome(string s) {
        
       map<char, int> map;

        bool bHasOne = false;

        for (int i = 0;i < s.length();i++)
        {           
            map[s[i]] += 1;
        }

        int count = 0;

        for (auto itr : map)
        {
            pair<char, int> p = (pair<char,int>) itr;
            
            if (p.second  == 1)
            {
                if (bHasOne == false)
                {
                    bHasOne = true;
                    count += p.second;
                }
            }
            else if((p.second % 2) == 1)
            {

                if (!bHasOne)
                {
                    count += p.second;
                    bHasOne = true;
                }
                else
                    count += p.second -1;                    
            }
            else
            {
                count += p.second;
            }

        }

        return count;
    }

    int sumOfLeftLeaves(TreeNode* root) {

        if (root == nullptr)
            return 0;
        
    	if ((root->left != nullptr)  && (root->left->right == nullptr) && (root->left->left == nullptr))
        {
		    return root->left->val + sumOfLeftLeaves(root->right);
	    }
	            
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    }

};

int main()
{


}