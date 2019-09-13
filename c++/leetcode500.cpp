#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
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
 
class MinStack {


private:
    vector<int> heap;
    int cur;
    int size;

    void min_heapify(int idx){

        if (idx <= 0)
            return;

        if (idx > size)
            return;


        int par = heap[idx];

        if (idx*2 > size)
            return;

        if (par > heap[idx*2])
        {
            int temp = heap[idx];
            heap[idx] = heap[idx*2];
            heap[idx*2] = temp;
            min_heapify(idx*2);
        }

        if (par > heap[idx*2+1])
        {
            int temp = heap[idx];
            heap[idx] = heap[idx*2+1];
            heap[idx*2+1] = temp;
            min_heapify(idx*2+1);

        }

    }

    void insert(int x){

        if (size+1 > heap.size()+1)
            heap.resize(heap.size()*2);


        size++;
        int idx = size;
        heap[size] = x;
        
        while (idx >= 1)
        {
            int par = idx/2;

            if (heap[par] > (heap[idx]))
            {
                int temp = heap[par];
                heap[par] = heap[idx];
                heap[idx] = temp;
                idx = idx/2;
            }
            else
                break;
        }
            
    }

    void extract_min(){
        int min = heap[1];

        heap[1] = heap[size];
        size--;

        min_heapify(1);
    };

public:
    /** initialize your data structure here. */
    // root = i = 1
    // parent = i/2
    // left = 2i
    // right 2i+1
    // the key of a node is < = key of its children

    MinStack() : heap(10), cur(0), size(9) {
        
    }
    
    void push(int x) {
        insert(x);
    }
    
    void pop() {
        extract_min();
    }
    
    int top() {
        return heap[1];
    }
    
    int getMin() {
        return heap[1];
    }
};

    bool wayToSort(int i, int j) { return i > j; };


class Solution
{
public:
    vector<string> findWords(vector<string>& words) {
        

        vector<string> res;

        if (words.size() == 0)
            return res;

        set<char> top = {'q','w','e','r','t','y','u','i','o','p'};
        set<char> middle = {'a','s','d','f','g','h','j','k','l'};
        set<char> bottom = {'z','x','c','v','b','n','m'};

        
        for (int i = 0;i < words.size();i++)
        {
            bool isUsingTop = false;
            bool isUsingMiddle = false;
            bool isUsingBottom = false;

            string word = words[i];

            for (char c : word)
            {
                if (top.find(c) != top.end())
                {
                    isUsingTop = true;    
                }
                
                if (middle.find(c) != middle.end())
                {
                    isUsingMiddle = true;    
                }

                if (bottom.find(c) != bottom.end())
                {
                    isUsingBottom = true;    
                }

            }

            if (!((isUsingTop && isUsingMiddle) ||
                (isUsingMiddle && isUsingBottom) ||
                (isUsingTop && isUsingBottom) ))
            {
                res.push_back(word);
            }

        }

        return res;

    }
     
    void printVector(vector<string> &input)
    {
        for (int i = 0;i< input.size();i++)
        {
            cout << input[i] << " " ;

        }
        cout << endl;
    }

    
    vector<string> findRelativeRanks(vector<int>& nums) {
    
         vector<string> res(nums.size());
        
        if (nums.size() == 0)
            return res;

        vector<int> unsorted = nums;

        for (int i = 0;i<nums.size();i++)
        {
            res[i] = std::to_string(nums[i]);   
        }
 
        sort(nums.begin(),nums.end(),wayToSort);
        
        for (int i = 0;i < nums.size();i++)
        {
            int idx = linearSearch(unsorted,0,unsorted.size()-1,nums[i]);
            
            if (i == 0)
                res[idx] = "Gold Medal";
            
            if (i == 1)
                res[idx] = "Silver Medal";
            
            if (i == 2)
                res[idx] = "Bronze Medal";
            
            if (i >= 3)
                res[idx] = std::to_string(i+1);
        }
            
        return res;
        
    }

    int linearSearch(vector<int> &input,int low, int high, int target)
    {
        for (int i = low;i<=high;i++)
        {
            if (input[i] == target)
                return i;
        }

        return low;

    }


    int binarySearch(vector<int> &input,int low, int high, int target)
    {

        while (low < high)
        {
            int mid = (low + high) /2;
            if (input[mid] == target)
                return mid;     
            
            if (input[mid] > target)
            {
                high = mid -1;
            }
            else
                low = mid +1;                
        }
        
        return low;
        
    }

     bool detectCapitalUse(string word) {
        
         int cnt = 0;
        int size = word.length();
        
        for (char c : word)
        {            
            if ((c -'A') <= 26)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
        
        if (cnt == size)
            return true;

        if (cnt == 0)
            return true;

        
        if (cnt == 1)
        {
            if ((word[0] -'A') <= 26)
                return true;
            else
                return false;
        }
        return false;
    }

 int maxDepth(Node* root) {
        
        if (root == nullptr)
            return 0;
        
        int level = 0;
        
        unordered_set<Node *> frontier; // nodes at level i - 1
		unordered_set<Node *> next; // nodes at level i
        frontier.insert(root);
        
        while (!frontier.empty())
        {
            unordered_set<Node *> next; // nodes at level i
            
            for (Node * node : frontier)
            {
                for (Node * child : node->children)
                {
                    next.insert(child);
                }
            }
            frontier = next;
            level++;            
        }
        
        
        return level;

    }
      
      
      bool isSubtree(TreeNode* s, TreeNode* t) {

        if (s == t) //both null 
            return true;

        if (s == nullptr)
            return false;

        if (t == nullptr)
            return false;

        if ((s->val == t->val) && 
            ((s->right == nullptr) && 
             (s->left == nullptr))   &&
            ((t->right == nullptr) && 
             (t->left == nullptr)))
            {
                return true;
            }

        if ((s->val == t->val) && 
            ((s->left != nullptr) && (t->left != nullptr) &&
                (s->left->val == t->left->val)) &&
            (s->right == nullptr)   &&
            (t->right == nullptr))
            {
                return true;
            }   

        if ((s->val == t->val) && 
            ((s->right != nullptr) && (t->right != nullptr) &&
                (s->right->val == t->right->val)) &&
            (s->left == nullptr)   &&
            (t->left == nullptr))
            {
                return true;
            }   




        if ((s->val == t->val) && 
            ((s->left != nullptr) && (t->left != nullptr) &&
                (s->left->val == t->left->val)) &&
            ((s->right != nullptr) && (t->right != nullptr) &&
                (s->right->val == t->right->val)) &&
            ((s->right->right == nullptr) && 
             (s->left->left == nullptr))   &&
            ((t->right->right == nullptr) && 
             (t->left->left == nullptr)))   

            {
                return true;
            }

        return isSubtree(s->left, t) || isSubtree(s->right,t);

    }


};


int main()
{
     vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

     vector<string> res;

     Solution sol;
   //  res = sol.findWords(words);

    //sol.printVector(res);

   // vector<int> input = {10,3,8,9,4};

 //   res = sol.findRelativeRanks(input);

   // sol.printVector(res);

    string word = "USA";

    cout << sol.detectCapitalUse(word) << endl;
}