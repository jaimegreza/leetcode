#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
      if (l1 == NULL)
        {
            return l2;
        }

        if (l2 == NULL)
        {
            return l1;
        }

        ListNode* result = NULL;
        ListNode* temp = NULL;
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        while ((t1 != NULL) && (t2 != NULL))
        {

            int smaller = 0;
            bool bT1 = false;

            if (t1->val > t2->val)
                smaller = t2->val;
            else
            {
                bT1 = true;
                smaller = t1->val;
            }
            ListNode* digit = new ListNode(smaller);

            if (result == NULL)
            {
                result = digit;
                temp = result;
            }
            else
            {
                temp->next = digit;
                temp = digit;
            }

            if (bT1)
                t1 = t1->next;
            else
                t2 = t2->next;
        }


        while ((t1 != NULL) && (t2 == NULL))
        {
            ListNode* digit = new ListNode(t1->val);
            temp->next = digit;
            temp = digit;
            t1 = t1->next;
        }

        while ((t2 != NULL) && (t1 == NULL))
        {
            ListNode* digit = new ListNode(t2->val);
            temp->next = digit;
            temp = digit;
            t2 = t2->next;
            
        }


        return result;
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

//1->2->4, 1->3->4
// 1->1->2->3->4->4

    ListNode *num1a = new ListNode(4);
    ListNode *num1b = new ListNode(2);
    num1b->next = num1a;
    ListNode *num1c = new ListNode(1);
    num1c->next = num1b;

    ListNode *num2a = new ListNode(4);
    ListNode *num2b = new ListNode(3);
    num2b->next = num2a;
    ListNode *num2c = new ListNode(2);
    num2c->next = num2b;

    printList(num1c);
    printList(num2c);

    Solution sol;
    ListNode *result = sol.mergeTwoLists(num1c,num2c);

    printList(result);
 


}