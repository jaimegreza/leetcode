#include <iostream>
#include <cstring>
#include <ctype.h>
#include <iomanip> 
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <math.h>


using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
        int mid = low + (high - low)/2;
        TreeNode* n = new TreeNode(nums[mid]);
        n->left = toBST(nums, low, mid - 1);
        n->right = toBST(nums, mid + 1, high);
        return n;
    }

    TreeNode* sortedArrayToBSTMine(vector<int>& nums) {
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
    void printVector(vector<int> input)
        {
            for (int i = 0;i< input.size();i++)
            {
                cout << input[i] << " " ;

            }
            cout << endl;
        }

        void printVector(vector<vector<int>> input)
        {
            for (int i = 0;i< input.size();i++)
            {
                printVector(input[i]);

            }
            cout << endl;
        }
     
     bool hasPathSum(TreeNode* root, int sum) {
        
        if (root == nullptr)
            return false;

        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);

        int count = root->val;

        if ((count == sum) && isLeaf)
            return true;

        if ((count != sum) && isLeaf)
            return false;
    
        return (hasPathSum(root->left,sum - count) || hasPathSum(root->right, sum - count));
    }
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        if ((root->val > p->val) && (root->val > q->val))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if ((root->val < p->val) && (root->val < q->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else        
            return root;
   
    }
    TreeNode* lowestCommonAncestorMine(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr)
            return nullptr;

        if ((root->val > p->val) && (root->val > q->val))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if ((root->val < p->val) && (root->val < q->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        if ((root->val == p->val) && ((root->right != nullptr) && (root->right->val == q->val)))
            return root;
            
        if ((root->val == p->val) && ((root->left != nullptr) && (root->left->val == q->val)))
            return root;

        if ((root->val == q->val) && ((root->right != nullptr) && (root->right->val == p->val)))
            return root;
            
        if ((root->val == q->val) && ((root->left != nullptr) && (root->left->val == p->val)))
            return root;

        return nullptr;

    }

    int sumOfLeftLeaves(TreeNode* root) {

        int sum = 0;
        if (root == nullptr)
            return sum;

        sumOfLeftLeavesHelper(root,sum, false);

        return sum;
    }

    void sumOfLeftLeavesHelper(TreeNode* root, int& sum, bool isLeft)
    {

       if(root == nullptr)
            return;

        bool isLeaf = ((root->left == nullptr) && (root->right == nullptr));

        if (isLeft && isLeaf)
        {
            sum += root->val;
        }

        sumOfLeftLeavesHelper(root->left, sum, true);
        sumOfLeftLeavesHelper(root->right, sum, false);
    
    }

    void inOrder(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		inOrder(root->left);
		cout << setw(4) << root->val;
		inOrder(root->right);
    }

     void preOrder(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		cout << setw(4) << root->val;
		preOrder(root->left);
		preOrder(root->right);
	}

	 void postOrder(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		postOrder(root->left);
		postOrder(root->right);
		cout << setw(4) << root->val;
	}

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;        
        postOrderIterative(root,res);
    
        return res;
    }

    void postOrderIterative(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr)
            return;

        stack<TreeNode*, deque<TreeNode*>> leftStack;
        stack<TreeNode*, deque<TreeNode*>> rightStack;
        
        res.push_back(root->val);

        if((root->right != nullptr))
             rightStack.push(root->right);
        
        if((root->left != nullptr))
            leftStack.push(root->left);


        while (!leftStack.empty() ||
               !rightStack.empty())
            {
                TreeNode *root;
                while(!rightStack.empty())
                {
                    root = rightStack.top();
                    rightStack.pop();
                    res.push_back(root->val);

                    if (root->right != nullptr)
                        rightStack.push(root->right);

                    if (root->left != nullptr)
                        leftStack.push(root->left);
                }

                if (!leftStack.empty())
                {
                    root = leftStack.top();
                    leftStack.pop();
                    res.push_back(root->val);

                    if (root->right != nullptr)
                        rightStack.push(root->right);

                    if (root->left != nullptr)
                        leftStack.push(root->left);
                }
               
            }

        std::reverse(res.begin(),res.end());
        
    } 


    void postOrder(TreeNode* root, vector<int>& res)
    {
		if (root == NULL) {
			return;
		}
		postOrder(root->left,res);
		postOrder(root->right,res);
		res.push_back(root->val);
    } 



    vector<vector<int>> levelOrder(TreeNode* root) 
    {

        vector<vector<int>> res;
        
        if (root == nullptr)
            return res;
        
        int level = 1;
        queue<TreeNode *, deque<TreeNode *>> frontier;
        frontier.push(root);

        int levelCount = 1;

        while (!frontier.empty())
        {
            queue<TreeNode *, deque<TreeNode *>> next;
 //           int numAtNextLevel = 2<<(level-1);
            int currentCount = 0;
        
            vector<int> levelResult;

            while (levelCount > 0)
            {
    			root = frontier.front();
	    		frontier.pop();

                levelResult.push_back(root->val);
                    
                TreeNode* left = root->left;
                if (left != nullptr)
                {
                    next.push(left);
                    currentCount++;
                }

                TreeNode* right = root->right;
                if (right != nullptr)
                {
                    next.push(right);
                    currentCount++;
                }
				levelCount--;
			}
            level++;
			levelCount = currentCount;
			currentCount = 0;
            res.push_back(levelResult);
            frontier = next;
		}

        
        return res;

    }


};

int main()
{
    Solution sol;

    vector<int> inp = {-10,-3,0,5,9};
    inp = {1,2,4,4,5,7,8,11,13};

    TreeNode * root = sol.sortedArrayToBST(inp);

    TreeNode *root2 = new TreeNode(5);

    TreeNode *four = new TreeNode(4);
    TreeNode *eight = new TreeNode(8);

    TreeNode *eleven = new TreeNode(11);
    TreeNode *thirteen = new TreeNode(13);
    TreeNode *fourR = new TreeNode(4);

    TreeNode *seven = new TreeNode(7);
    TreeNode *two = new TreeNode(2);
    TreeNode *one = new TreeNode(1);

    eleven->left = seven;
    eleven->right = two;

    four->left = eleven;
    fourR->right = one;
    eight->right = fourR;
    eight->left = thirteen;

    root2->right = eight;
    root2->left = four;

    sol.preOrder(root);
    cout << endl;
    sol.inOrder(root);
    cout << endl;
    
    vector<int> result;
    cout << "POSTORDER ITERATIVE: " << endl;
    result = sol.postorderTraversal(root);
    sol.printVector(result);

    sol.preOrder(root2);
    cout << endl;
    sol.inOrder(root2);
    cout << endl;
    sol.postOrder(root2);
    cout << endl;
   
    vector<vector<int>> output ;
    output = sol.levelOrder(root);
    sol.printVector(output);
    cout << endl;
    output = sol.levelOrder(root2);
    sol.printVector(output);
    cout << endl;

    cout << "path sum: " << sol.hasPathSum(root,22) << endl;
    cout << "path sum: " << sol.hasPathSum(root2,22) << endl;


}