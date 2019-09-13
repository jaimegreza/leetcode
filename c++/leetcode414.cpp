#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;


class Node {
public:
    int val = 0;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution
{
private:
        int count;
public:
    

    int compress(vector<char>& chars) {
        
        if (chars.size() == 0)
            return 0;

        if (chars.size() == 1)
            return 1;

        int len = 0;

        int idx = 0;

        for (int i = 0;i < chars.size();i++)
        {
            char c  = chars[i];
            int count = 1;
            idx = i;
            len++;
            while (i < chars.size()-1)
            {
                char n = chars[++i];
                
                if (c == n)
                {
                    count++;
                }
                else
                {
                    i--;
                    break;
                }
            }


            string num = std::to_string(i-idx+1);

            cout << num << " " << num.size() << endl;

                // 0 3  (count - placeholders - 1)

            int numToShift = 0;

            for (int j = 0;j< (i-idx+1); j++)
            {
                numToShift++;
                chars[++idx] = num[j]; 
            }

            numToShift = (i-idx+1) - numToShift;

            for (int j = idx;j < i;j++)
            {
                chars[j] = chars[j+1];
                len++;
            }

        }

        return len;
    }

     void printVector(vector<char> &input)
    {
        for (int i = 0;i< input.size();i++)
        {
            cout << input[i] << " " ;

        }
        cout << endl;
    }

      int arrangeCoins(int n) {
        
      if (n ==0)
            return 0;
  
        int count = 1;

        while (n > 0)
        {
            if ((n/count) > 0)
            {
                n = n - count;
                count++;
            }
            else
                break;
        }

        return count-1;          
    }
    
     bool isAnagram(string s, string t) {
          if (s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s.compare(t) != 0)
            return false;  

        return true;
    }

    vector<int> findAnagrams(string s, string p) {

       vector<int> res;

        if (s.size() == 0)
            return res;
        
        vector<int> vs(26,0);
        vector<int> vp(26,0);

        for (char c : p)
        {
            vp[c -'a'] +=1;
        }

        int size = p.size();
       
        for (int i = 0; i < s.size();i++)
        {
            if (i >= size) 
                vs[s[i-size]-'a'] -= 1;

            vs[s[i] - 'a'] += 1;

            if (vs == vp)
                res.push_back(i - size + 1);

        }

        return res;
    }
    
   int pathSum(TreeNode* root, int sum) {

        if (root == nullptr)
            return 0;

        pathSumHelper(root,sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum); 
   
        return count;
    }

    void pathSumHelper(TreeNode* root, int sum) {

         if (root == nullptr)
         {
            return; 
         }
                    
        if (0 == (sum - root->val))
        {
            count += 1;
        }

        pathSumHelper(root->left,  sum - root->val);
        pathSumHelper(root->right, sum - root->val); 
     
    }
    int countSegments(string s) {

        if (s.size() < 1) 
            return 0;

        if (s.size() == 1) 
        {
            if (s[0] != ' ')
                return 1;
            else
                return 0;
        }

        int count = 0;
        bool bSeg = false;

        for (int i = 0;i< s.size();i++)
        {
            if (s[i] != ' ')
            {
                if (!bSeg)
                {
                    bSeg = true;
                }
               
                if (i == s.size()-1)
                {
                    count++;
                }
                
            }
            else
            {
                if (bSeg)
                {
                    bSeg = false;
                    count++;
                }
            }
        }

        return count;
    }

    vector<vector<int>> levelOrder(Node* root) 
    {

        vector<vector<int>> res;
        
        if (root == nullptr)
            return res;
        
        queue<Node *, deque<Node *>> q;

        int levelCount = 1;
		int currentCount = 0;
		q.push(root);

		while (!q.empty()) {

            vector<int> level(levelCount);
            int count = 0;

			while (levelCount > 0) {
				root = q.front();
				q.pop();
		
                level[count++] = root->val;
                    
                for (Node* itr : root->children)
                {
                    q.push(itr);
                    currentCount++;
                }

				levelCount--;
			}
			levelCount = currentCount;
			currentCount = 0;
            res.push_back(level);
		}

        
        return res;

    }


    int thirdMax(vector<int>& nums) {

        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        

        for (int i = 0;i< nums.size();i++)
        {
        //      1st  2nd      3rd
        //       3    2       1  
        // 1st   2nd  3rd
                if (nums[i] >= first) 
                {
                    int temp = first;
                    first = nums[i];

                    if ((temp >= second) && (temp != first))
                    {
                        int temp2 = second;
                        second = temp;

                        if ((temp2 >= third) && (temp2 != second))
                        {
                            third = temp2;                            
                        }
                    }
                           
                }
                else if (nums[i] >= second)
                {
                    int temp = second;
                    second = nums[i];

                    if ((temp >= third) && (temp != second))
                    {
                        third = temp;
                    }
                }
                else if ((nums[i] >= third) && (nums[i] != second))
                {
                    third = nums[i];
                }

        }
        
        if (second == LONG_MIN)
            return first;

        if (third == LONG_MIN)
            return first;

        return third;
             
    }   


};


int main()
{
    Solution sol;
    vector<int> arr = {2, 2, 3, 1};
  //  cout << "3rd max : " << sol.thirdMax(arr) << endl;

    string s = "cbaebabacd";
    string p = "abc";
    //sol.findAnagrams(s,p);

   // cout << "count: " << sol.arrangeCoins(3) << endl;
    vector<char> chars = {'a','a','b','b','b','c','c','c'};
    sol.printVector(chars);

    cout << "count: " << sol.compress(chars) << endl;
    sol.printVector(chars);


}