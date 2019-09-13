#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if ((p == NULL) && (q == NULL))      
             return true;

        if ((p == NULL) || (q == NULL))      
            return false;

        bool bLeft = isSameTree(p->left,q->left);
        bool bVisit = visit(p,q);
        bool bRight = isSameTree(p->right,q->right);

        return (bLeft && bVisit && bRight);
    }

    bool visit(TreeNode* p, TreeNode* q)
    {
        if ((p == NULL) && (q == NULL))      
             return true;

        if ((p == NULL) || (q == NULL))      
            return false;


        return (p->val == q->val) ? true : false;

    }
};
int main()
{
    Solution sol;

    TreeNode* p = new TreeNode(10);
    TreeNode* pl = new TreeNode(5);
    TreeNode* pr = new TreeNode(15);
    p->left = pl;
    p->right = pr;

    TreeNode* q = new TreeNode(10);
    TreeNode* ql = new TreeNode(5);
    TreeNode* qr = new TreeNode(15);
    q->left = ql;
    ql->right = pr;
    
    bool ret = sol.isSameTree(p,q);

    cout << ret << endl;

}