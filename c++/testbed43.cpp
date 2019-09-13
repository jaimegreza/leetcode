#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
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

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;


    }

     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            if (headA == nullptr)
                return nullptr;

            if (headB == nullptr)
                return nullptr;

            int lenA = 0;
            int lenB = 0;

            ListNode * temp = nullptr;
            temp = headA;

            while (temp != nullptr)
            {
                temp = temp->next;
                lenA++;
            }

            temp = headB;

            while (temp != nullptr)
            {
                temp = temp->next;
                lenB++;
            }

            int diff = abs(lenA - lenB);

            ListNode * lA = headA;
            ListNode * lB = headB;

            if (lenA > lenB)
            {
                while (diff-- > 0 )
                {
                    lA = lA->next;
                }
            }
            else
            {
                while (diff-- > 0 )
                {
                    lB = lB->next;
                }
            }

            while (lA != nullptr)
            {
                if (lA == lB)
                    return lA;
                else
                {   
                    lA = lA->next;
                    lB = lB->next;
                }
            }

            return nullptr;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output(2);
        unordered_map<int,int> map;

        for (int i = 0;i< numbers.size();i++)
        {
            if (map.find(numbers[i]) == map.end())
                map[numbers[i]] = i+1;

            if (map.find(target-numbers[i]) != map.end() )
            {
                int a = i+1;
                int b = map[target-numbers[i]];
                output[0] = (b < a) ? b : a;
                output[1] = (b < a) ? a : b;
                break;
            }
        }
        return output;
    }

    vector<int> twoSumSlow(vector<int>& numbers, int target) {
        vector<int> output(2);
        unordered_map<int,int> map;

        for (int i = 0;i< numbers.size();i++)
        {
            if (map.find(numbers[i]) == map.end())
                map[numbers[i]] = i+1;
        }

        for (int i = 0;i < numbers.size();i++)
        {
            if (map.find(target-numbers[i]) != map.end() )
            {
                int a = i+1;
                int b = map[target-numbers[i]];
                output[0] = (b < a) ? b : a;
                output[1] = (b < a) ? a : b;
            }
        }
        return output;
    }

    void rotateNoSpace(vector<int>& nums, int k) {

            int size = nums.size();

            k = k%size;

            if (size == 1)
                return;
            
            if (size == 2)
            {
                while (k-- > 0)
                {
                    int temp = nums[0];
                    nums[0] = nums[1];
                    nums[1] = temp;
                }
                return;
            }

            while (k-- > 0)
            {
                int temp = nums[size-1];

                for (int i = size-2; i >= 0;i--)
                {
                    nums[i+1] = nums[i];
                }
                nums[0] = temp;
            }

    }
    void rotate(vector<int>& nums, int k) {

            int size = nums.size();

            k = k%size;

            if (size == k)
                return;

            if (size == 1)
                return;
            
            if (size == 2)
            {
                while (k-- > 0)
                {
                    int temp = nums[0];
                    nums[0] = nums[1];
                    nums[1] = temp;
                }
                return;
            }

            vector<int> temp(k);

            for (int i = 0; i < k ; i++)
            {
                temp[i] = nums[(size-i-1)];
            }
      
                for (int i = 0; i < size-k ; i++)
                {
                    int l = (size-k)-i-1;
                    int r = size-i-1;
                    nums[r] = nums[l];
                }

            for (int i = 0; i < k ; i++)
            {
                nums[i] = temp[k-i-1];
            }

    }


    int trailingZeroes(int n) {

        if (n == 0)
            return 0;

       int count = 0;
 
       // Keep dividing n by powers of 
        // 5 and update count
         for (int i = 5; n / i >= 1; i *= 5)
            count += n / i;
 
        return count;


    }

     int titleToNumber(string s) {

        int r = 0;

       for (int i = 0; i < s.length(); i ++) {
            r = r * 26 + s[i] - 'A' + 1;
        }
        return r;

    }
    
    string convertToTitle(int n) {
            
             string r = "";
            
            while (n > 0) {
//                r = (char)(65 + (n - 1) % 26) + r;
                  r = (char)('A' + (n - 1) % 26) + r;
                  n = (n - 1) / 26;
            }
            return r;
            
            
            
    }
    
      int majorityElement(vector<int>& nums) {
          unordered_map<int,int> map;

          for (int i = 0;i< nums.size();i++)
          {
              map[nums[i]] = map[nums[i]] + 1;
          }

        int max = 0;
        int most;
        for (pair<int,int> n : map)
        {
            int cur = n.second;

            if (cur > max)
            {
                max = cur;
                most = n.first;
            }
        }
        return most;
    }

 int majorityElementSlow(vector<int>& nums) {
          unordered_map<int,int> map;

          for (int i = 0;i< nums.size();i++)
          {
              map[nums[i]] = map[nums[i]] + 1;
          }

        int max = 0;
        int most;
        for (pair<int,int> n : map)
        {
            int cur = n.second;

            if (cur > max)
            {
                max = cur;
                most = n.first;
            }
        }
        return most;
    }

    uint32_t reverseBits(uint32_t n) {
        
        if (n == 0)
            return 0;

        int res = 0;
        for(int i = 0;i< 32;i++)
        {
            res <<= 1;

            if ((n & 1) == 1)
                res++;
            n >>= 1;

        }

        return res;
    }

     int hammingWeight(uint32_t n) {

        if (n == 0)
            return 0;

        int count = 0;
        while (n > 0)
        {
            if ((n & 1) == 1)
                count++;
         
            n >>= 1;
        }

        return count;
  
    }

     int rob(vector<int>& nums) {

         int size = nums.size();

         if (size == 0)
            return 0;
        
        vector<int> dp(size);
        
        dp[0] = nums[0];
        dp[1] =  max(nums[0],nums[1]);

         for (int i = 2;i < size;i++)
         {
            dp[i] = max(dp[i-1] , nums[i] +  dp[i-2]);
         }
        return dp[size-1];
    }

    bool isHappy(int n) {
    

        unordered_set<int> set;

        while (set.find(n) == set.end())
        {
            set.insert(n);

            int sum = 0;

            while (n > 0)
            {
                int r = n%10;

                sum = sum + r*r;
                n = n/10;
            }

            if (sum == 1)
                return true;
            n = sum;

        }

        return false;

    }

    ListNode* removeElements(ListNode* head, int val) {
        
        if (head == nullptr)
            return nullptr;
        
        ListNode * curr = head;
        ListNode * newHead = head;

        while (curr == newHead)
        {
            if (curr->val == val)
            {
                newHead = curr->next;
                ListNode * temp = curr;
                curr = newHead;
                free(temp);

                if (newHead == nullptr)
                    return nullptr;
            }
            else
            {
                curr = curr->next;
            }

        }

        ListNode *prev = newHead;

        while (curr != nullptr)
        {

            if (curr->val == val)
            {
                ListNode * temp = curr;
                prev->next = curr->next;
                curr = prev->next;
                free(temp);
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return newHead;
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



int main()
{


    Solution sol;
//    vector<int> in = {2,7,11,15};
//        vector<int> in = {2,2,1,1,1,2,2};
    //vector<int> out = sol.twoSum(in,9);
    //    vector<int> in = {6,5,5};
      vector<int> in = {2,7,9,3,1}; //3
  
//    int ret = sol.isHappy(2); //964176192

  //  cout << sol.trailingZeroes(1808548329) << endl;

    ListNode *num1a = new ListNode(6);
    ListNode *num1b = new ListNode(1);
    num1b->next = num1a;
    ListNode *num1c = new ListNode(2);
    num1c->next = num1b;
    ListNode *num1d = new ListNode(6);
    num1d->next = num1c;
    ListNode *num1e = new ListNode(1);
   // num1e->next = num1d;
    ListNode *num1f = new ListNode(2);
    num1f->next = num1e;
    ListNode *num1g = new ListNode(2);
    num1g->next = num1f;
    ListNode *num1h = new ListNode(1);
    num1h->next = num1g;

    printList(sol.removeElements(num1h,2));
  /*  MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    int min = st.getMin();
    st.pop();
    int top = st.top();
    int min2 = st.getMin();
*/
//    ["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]


}