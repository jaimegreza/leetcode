#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution {
public:

     bool isPrime(int n) {
        if (n <= 1) return false;
       
        for (int i = 3; i*i <= n; i=i+2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int countPrimesSlow(int n) {
        // 2 ,3 , 5, 7 11
        int count = 0;

        if (n > 2)  count++;

        for (int i = 3; i < n; i=i+2)
        {
            if (isPrime(i)) count++;
        }
        return count;
    }

        int countPrimes(int n) {
        bool *isprime = new bool[n + 1];
        for (int i = 2; i < n + 1; i ++) {
            isprime[i] = true;
        }
        for (int i = 2; i * i < n; i ++) {
            if (isprime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i ++) {
            if (isprime[i]) {
                cnt ++;
            }
        }
        return cnt;
    }

     bool isIsomorphic(string s, string t) {
         
         if (s.length() != t.length())
            return false;

        unordered_map<char, char> map;
        unordered_map<char, char> marked;
        int size = s.length();
        // egg // add

        for (int i = 0;i < size;i++)
        {
            if (map.find(s[i]) == map.end())
            {
                if (marked.find(t[i]) != map.end())
                {
                    return false;
                }

                marked[t[i]] = s[i];
                map[s[i]] = t[i];
            }
            else if (map[s[i]] != t[i])
                return false;

        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        
    
        if ((head == nullptr) || (head->next == nullptr))
                return head;


        ListNode * rev = head;
        ListNode * cur = head->next;
        rev->next = nullptr;
        ListNode * next;

        while(cur != nullptr)
        {   
            next = cur->next;
            cur->next = rev;
            rev = cur;
            cur = next;
        }
 
        return rev;

    }

    bool containsDuplicate(vector<int>& nums) {

        int size = nums.size();

        if (size == 1 || size == 0)
            return false;

        unordered_set<int> set;

        for (int i = 0;i< size;i++)
        {
            if (set.find(nums[i]) == set.end())
            {
                set.insert(nums[i]);
            }
            else
                return true;
        }

        return false;
    }


    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int size = nums.size();

        if (size == 1 || size == 0)
            return false;

        unordered_map<int,int> map;

        for (int i = 0;i< size;i++)
        {
            if (map.find(nums[i]) == map.end())
            {
                map[nums[i]] = i;
            }
            else
            {
                int idx = map[nums[i]];
                
                if ((i - idx) <= k)
                    return true;
                else
                    map[nums[i]] = i;
            }
        }

        return false;
    }

     TreeNode* invertTree(TreeNode* root) {
        
         if (root == nullptr)
            return root;

        TreeNode * temp = root->right;
        root->right = root->left;
        root->left = temp;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;
    }

     bool isPowerOfTwo(int n) {

        if (n <= 0)
            return false;
        
       int count = 0;
        
        for (int i = 0;i< 32;i++)
        {
            int mask = 1;
            if (n&mask)
            {
                count++;
            }
            if (count > 1)
                return false;
            
            n = n >> 1;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr)
            return true;
        
        if (head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* cut;
        int count = 0;

        ListNode *next = head;
        while (next != NULL)
        {
            count++;
            next = next->next;
        }

        while ((fast != nullptr) && (fast->next != nullptr))
        {
            fast = fast->next->next;
            cut = slow;
            slow = slow->next;
        } 

        cut->next = nullptr;
        
        if (count%2 == 1)
            slow = slow->next;

        count = count/2;

        ListNode * rev = reverseList(head);

        ListNode * cur = slow;

        while (count-- > 0)
        {
            if (rev->val != cur->val)
                return false;
            
            cur = cur->next;
            rev = rev->next;

        }
        return true;
    }

   void deleteNode(ListNode* node) {

         if ((node == nullptr) || (node->next == nullptr))
                return;

        node->val = node->next->val;
        node->next = node->next->next;


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

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        if (root) helper(root, "", res);
        return res;

    }

     void helper(TreeNode* node, string out, vector<string>& res) {
        if (!node->left && !node->right) res.push_back(out + to_string(node->val));
        if (node->left) helper(node->left, out + to_string(node->val) + "->", res);
        if (node->right) helper(node->right, out + to_string(node->val) + "->", res);
    }
    
    int addDigits(int num) 
    {
          if (num == 0)
            return 0;

          while (num > 0)
          {
            if (num/10 == 0)
                return num;

            int sum = 0;

            while(num > 0)
            {
                sum = sum + num%10;
                num = num/10;
            }

            num = sum;
        
          }
          return num;
    }

     bool isUgly(int num) {
         if (num <= 0)
            return false;
        
        if (num == 1)
            return true;

        while (num > 1)
        {
            bool check = false;
            if (num%5 == 0)
            {
                num = num/5;
                check = true;
            }
            
            if (num%3 == 0)
            {
                num = num/3;
                check = true;
            }
            
            if (num%2 == 0)
            {
                num = num/2;
                check = true;
            }

            if (!check)
                return false;
        }

        return true;


    }

    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();

        if (size == 0)
            return 0;
        
        //int max = size-1;
        int s1 = 0;
        for (int i = 0;i <= size; i++)
        {
            s1 = s1 + i;
        }

        int s2 = 0;
        for (int i = 0;i < size; i++)
        {
            s2 = s2 + nums[i];
        }

        return s1 - s2;
    }


};



void printList(ListNode *list)
{
   // cout << list->val;


    ListNode *next = list;
    while (next != NULL)
    {
        cout << next->val << endl;
        next = next->next;
    }

    cout << endl;

}

const int MAX_CHAR = 26;
void sortString(string &str)
{
    // Hash array to keep count of characters.
    // Initially count of all charters is 
    // initialized to zero.
    int charCount[MAX_CHAR] = {0};
     
    // Traverse string and increment 
    // count of characters
    for (int i=0; i<str.length(); i++)
 
        // 'a'-'a' will be 0, 'b'-'a' will be 1,
        // so for location of character in count 
        // array we wil do str[i]-'a'.
        charCount[str[i]-'a']++;    
     
    // Traverse the hash array and print 
    // characters
    for (int i=0;i<MAX_CHAR;i++)
        for (int j=0;j<charCount[i];j++)
            cout << (char)('a'+i);
}

int main()
{
    Solution sol;

  /*  ListNode *num1a = new ListNode(1);
    ListNode *num1b = new ListNode(2);
    num1b->next = num1a;
    ListNode *num1c = new ListNode(2);
    num1c->next = num1b;
    ListNode *num1d = new ListNode(1);
    num1d->next = num1c;

    printList(num1b);*/

//    string s = "anagram", t = "nagaram";
    vector<int> nums = {3,0,1};
    int ret = sol.missingNumber(nums);


}