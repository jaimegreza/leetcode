#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

 class Solution {
public:
    ListNode* reverseListIterative(ListNode* head) {

        ListNode* rev = nullptr;

        ListNode* next = head;

        while (next != nullptr)
        {
            ListNode * temp;
            temp = next->next;
            next->next = rev;
            rev = next;
            next = temp;
        }
        
        return rev;
    }

    ListNode* reverseList(ListNode* head) {

        return reverseListRecursive(head, head->next);
    }

    ListNode* reverseListRecursive(ListNode* root, ListNode* next) {

        if (next == nullptr)
            return root;
        
        ListNode * temp = next->next;
        next->next = root;
        root = next;
        next = temp;        
        return reverseListRecursive(root, next);

    }



    template<class InputIterator, class Function>
    Function for_each(InputIterator first, InputIterator last, Function fn)
    {
        while (first!=last) {
            fn (*first);
            ++first;
        }
        return fn;      // or, since C++11: return move(fn);
    }

    
    void printList(ListNode *head)
    {
       ListNode *temp = head;

       while (temp != nullptr)
       {
           cout << temp->val << endl;
           temp = temp->next;
       }
    }
};

int main()
{

    Solution sol;

    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    ListNode *five = new ListNode(5);
    
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    sol.printList(one);
    ListNode *rev = sol.reverseList(one);
    sol.printList(rev);
    

}