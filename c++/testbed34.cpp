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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL)
            return NULL;

        ListNode* temp = head;

        while (temp->next != NULL)
        {
            int cur = temp->val;
            int dup = (temp->next)->val;
            if (cur == dup)
            {
                // delete node
                ListNode* node = temp->next;
                temp->next = (temp->next)->next;

                free(node);
            }
            else
            {
                cur = dup;
                temp = temp->next;
            }

        }

        return head;
    }
};


void printList(ListNode *list)
{
   // cout << list->val;
   if (list == NULL)
    return;

    ListNode *next = list;
    while (next != NULL)
    {
        cout << next->val << endl;
        next = next->next;
    }

    cout << endl;

}


ListNode* reverseList(ListNode* list) {


    if (list == NULL)
        return list;

    if (list->next == NULL)
        return list;

    ListNode* reversed = new ListNode(list->val);
    
    ListNode* next = list->next;
    while (next != NULL)
    {
        ListNode* forward = next->next;
        next->next = reversed;
        reversed = next;
        next = forward;
    }

    return reversed;
}

int main()
{

    ListNode *dups1 = new ListNode(3);

    ListNode *dups2 = new ListNode(2);
    dups2->next = dups1;
    ListNode *dups3 = new ListNode(2);
    dups3->next = dups2;

    ListNode *dups4 = new ListNode(1);
    dups4->next = dups3;
    ListNode *dups5 = new ListNode(1);
    dups5->next = dups4;

    Solution sol;

    printList(dups5);

    ListNode* result = sol.deleteDuplicates(dups5);
    printList(result);

}