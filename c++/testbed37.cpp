#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>


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

    bool isSymmetric(TreeNode* root) {

        return isMirror(root,root);

    }

    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == NULL && root2 == NULL)
           return true;
 
        if (root1 && root2 &&
             (root1->val == root2->val))
            return isMirror(root1->left, root2->right) &&
                   isMirror(root1->right, root2->left);
 
        return false;

    }


    bool isSymmetricIterative(TreeNode* root) {

        if (root == NULL)
           return true;
 
       if ((root->left == NULL) && (root->right == NULL))      
             return true;

        if ((root->left == NULL) || (root->right == NULL))      
             return false;

        bool bSym = true;

        stack<TreeNode*> frontier;

        int level = 0;
        int currentCount = 0;

        frontier.push(root);

        while (!frontier.empty())
        {
            stack<TreeNode*> next;
            vector<TreeNode*> levelNodes;

            while (!frontier.empty())
			{
                TreeNode* node = frontier.top();
                frontier.pop();

                if (level > 0)
                    levelNodes.push_back(node);

                if (node->left != NULL)
                {
                    next.push(node->left);
                    currentCount++;
                }

                if (node->right != NULL)
                {
                    next.push(node->right);
                    currentCount++;
                }
            }

            if (level > 0)
            {
               if (levelNodes.size() % 2)
                    return false;

                int half = (levelNodes.size()/2);
                int l = half-1;
                int r = half;

                while (l >= 0)
                {
                    TreeNode* lNode = levelNodes[l--];
                    TreeNode* rNode = levelNodes[r++];

                    if (lNode->val != rNode->val)
                        return false;
                }

            }
            currentCount = 0;
            levelNodes.clear();
			frontier = next;
			level++;

        }
        
    
        return bSym;
    }

/* This allows adding null elements to the queue */
        Queue<Node> q = new LinkedList<Node>();
 
        /* Initially, add left and right nodes of root */
        q.add(root.left);
        q.add(root.right);
 
        while (!q.isEmpty())
        {
            /* remove the front 2 nodes to
              check for equality */
            Node tempLeft = q.remove();
            Node tempRight = q.remove();
 
            /* if both are null, continue and chcek
               for further elements */
            if (tempLeft==null && tempRight==null)
                continue;
 
            /* if only one is null---inequality, retun false */
            if ((tempLeft==null && tempRight!=null) ||
                (tempLeft!=null && tempRight==null))
                return false;
 
            /* if both left and right nodes exist, but
               have different values-- inequality,
               return false*/
            if (tempLeft.val != tempRight.val)
                return 0;
 
            /* Note the order of insertion of elements
               to the queue :
               1) left child of left subtree
               2) right child of right subtree
               3) right child of left subtree
               4) left child of right subtree */
            q.add(tempLeft.left);
            q.add(tempRight.right);
            q.add(tempLeft.right);
            q.add(tempRight.left);
        }
 
        /* if the flow reaches here, return true*/
        return true;
};


 
int main()
{

     Solution sol;

    TreeNode* p = new TreeNode(10);
    TreeNode* pl = new TreeNode(5);
    TreeNode* pr = new TreeNode(5);
    p->left = pl;
    p->right = pr;

    bool ret = sol.isSymmetricIterative(p);

    cout << ret << endl;
}