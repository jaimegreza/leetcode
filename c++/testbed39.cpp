#include <iostream>
#include <vector>
#include <deque>
#include <math.h>

using namespace std;
// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

      return toBST(nums, 0, nums.size()-1);
    }

    TreeNode* toBST(vector<int>& nums, int low, int high) {
        if (low > high) {
            return NULL;
        }
        int mid = (low + high)/2;
        TreeNode* n = new TreeNode(nums[mid]);
        n->left = toBST(nums, low, mid - 1);
        n->right = toBST(nums, mid + 1, high);
        return n;
    }


    TreeNode* sortedArrayToBSTMine(vector<int>& nums) {

     //   if (nums == NULL)
       //     return NULL;
            
        TreeNode* root;
        
        if (nums.size() == 1)
        {
            root = new TreeNode(nums[0]);
            return root;
        }

        int count = nums.size();

        int level = 1;
        root = new TreeNode(nums[0]);
        deque<TreeNode*> frontier;

        frontier.push_front(root);

        int current_count = 1;

        while (!frontier.empty())
        {
            deque<TreeNode*> next;

            int numAtLevel = 2<<(level-1);

            while (numAtLevel > 0)
            {
                TreeNode* node = frontier.front();
                frontier.pop_front();

                if (current_count < count)
                {
                    TreeNode* left = new TreeNode(nums[current_count]);
                    node->left = left;
                    current_count++;
                    next.push_front(left);
                    numAtLevel--;
                }

                if (current_count < count)
                {
                    TreeNode* right = new TreeNode(nums[current_count]);
                    node->right = right;
                    current_count++;
                    next.push_front(right);
                    numAtLevel--;
                }

                if (current_count == count)
                    return root;
            }

            frontier=next;
            level++;

        }


        return root;
    }

     bool isBalanced(TreeNode* root) {

         int isBal = isBalancedUtil(root);
         return (isBal >= 0);

    }

    int isBalancedUtil(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = isBalancedUtil(root->left);
        if (left < 0) {
            return -1;
        }
        int right = isBalancedUtil(root->right);
        if (right < 0) {
            return -1;
        }
        int diff = abs(left - right);
        return diff <= 1 ? (max(left, right) + 1) : -1;
    }
};

int main()
{
    Solution sol;

    vector<int> vec = {-10,-3,0,5,9};
    TreeNode* result;
    result = sol.sortedArrayToBST(vec);

    bool bal = sol.isBalanced(result);
    cout << "bal:" << bal << endl;


}