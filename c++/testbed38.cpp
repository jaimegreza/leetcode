#include <iostream>
#include <stack>
#include <vector>
#include <deque>

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
    int maxDepth(TreeNode* root) {

        if (root == NULL) 
           return 0;
        else
        {
            int lDepth = maxDepth(root->left);
            int rDepth = maxDepth(root->right);
 
            if (lDepth > rDepth) 
                return(lDepth+1);
            else 
                return(rDepth+1);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;

    
        if (root == NULL)
           return result;
 

        deque<TreeNode*> frontier;

        int level = 0;
        int currentCount = 0;

        frontier.push_back(root);

        while (!frontier.empty())
        {
            deque<TreeNode*> next;
            vector<TreeNode*> levelNodes;

            while (!frontier.empty())
			{
                TreeNode* node = frontier.front();
                frontier.pop_front();

                levelNodes.push_back(node);

                if (node->left != NULL)
                {
                    next.push_back(node->left);
                    currentCount++;
                }

                if (node->right != NULL)
                {
                    next.push_back(node->right);
                    currentCount++;
                }
            }

            vector<int> levelVec;

//            for (int i=levelNodes.size()-1; i >= 0;i--)
            for (int i=0; i < levelNodes.size();i++)
            {
                TreeNode* cur = levelNodes[i];
                levelVec.push_back(cur->val);

            }

            result.push_back(levelVec);

            currentCount = 0;
            levelNodes.clear();
			frontier = next;
			level++;

        }
        
        int beg = 0;
        int end = result.size()-1;

        while (beg < end)
        {
            vector<int> temp;
            temp = result[beg];
            result[beg++] = result[end]; 
            result[end--] = temp;
        }

        return result;
    }

};

int main()
{
    Solution sol;

    TreeNode* p = new TreeNode(3);
    TreeNode* pl = new TreeNode(9);
    TreeNode* pr = new TreeNode(20);
    p->left = pl;
    p->right = pr;

    TreeNode* ql = new TreeNode(15);
    TreeNode* qr = new TreeNode(7);
    pr->left = ql;
    pr->right = qr;

    vector<vector<int>> result;
    result = sol.levelOrderBottom(p);

    cout << "done" << endl;

}