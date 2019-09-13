#include <iostream>
#include <vector>

using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        int sum = 0;
       

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

        
        while ((l1->next != NULL) && (l2->next != NULL))
        {
            sum = l1->val + l2->val + carry;
            cout << "sum: " << sum << endl;
            carry = (sum >= 10) ? 1 : 0 ;
            
            sum = sum % 10;
            cout << "sum: " << sum << endl;
            cout << "carry: " << carry << endl;

            ListNode* digit = new ListNode(sum);

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

            l1 = l1->next;
            l2 = l2->next;
        }
    
        sum = l1->val + l2->val + carry;
        carry = (sum >= 10) ? 1 : 0 ;
        sum = sum % 10;

        ListNode* digit = new ListNode(sum);

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

        while ((l1->next != NULL) && (l2->next == NULL))
        {
            l1 = l1->next;

            sum = l1->val + carry;
            carry = (sum >= 10) ? 1 : 0 ;
            sum = sum % 10;

            ListNode* digit = new ListNode(sum);

            temp->next = digit;
            temp = digit;

        }

        while ((l2->next != NULL) && (l1->next == NULL))
        {
            l2 = l2->next;

            sum = l2->val + carry;
            carry = (sum >= 10) ? 1 : 0 ;
            sum = sum % 10;

            ListNode* digit = new ListNode(sum);

            temp->next = digit;
            temp = digit;

        }


        if (carry)
        {    
            ListNode* digit = new ListNode(carry);
            temp->next = digit;
            temp = digit;
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
    Solution s;
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
//(2 -> 4 -> 3) + (5 -> 6 -> 4)

   // ListNode *num1a = new ListNode(3);

//    ListNode *num1b = new ListNode(4);
   // num1b->next = num1a;
    ListNode *num1c = new ListNode(5);
   // num1c->next = num1b;

   // ListNode *num2a = new ListNode(4);
   // ListNode *num2b = new ListNode(6);
  //  num2b->next = num2a;
    ListNode *num2c = new ListNode(5);
  //  num2c->next = num2b;

    printList(num1c);
    printList(num2c);

    ListNode *result = s.addTwoNumbers(num1c,num2c);

    printList(result);
    
    /*ListNode* reversed1 = reverseList(num1c);
    printList(reversed1);

    ListNode* reversed2 = reverseList(num2c);
    printList(reversed2);
*/
    return 0;
}