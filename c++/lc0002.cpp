#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*

Five Cons:

#################

Constrain: Leetcode gives constraints in their question 
Conceive:  (up to you but best to use a white board and talk it out even to yourself or piece of paper before coding)
Contract: function signature given by LeetCode
Construct: Class created and implementation in public and private methods of Class
Confirm: (tested in main using leetcode examples, testing by passing to leetcode submission)

#################

Constrain:  you are given two non-empty linked lists representing two non-negative integers. 
            The digits are stored in reverse order and each of their nodes contain a single digit. 
            Add the two numbers and return it as a linked list.
            You may assume the two numbers do not contain any leading zero, except the number 0 itself.

            question: the number 0 is a single node linked list with integer 0 as value? yes
            reverse order:   311 = 1 -> 1 -> 3? yes so this means we start a the same place, ONE's place.
   

Conceive:   (put ideas here from whiteboard , be honest)
            we have to worry about carrying over when two numbers add up to greater than 10 but we only carry over 1
            need a helper function to print a linked list.
            question: can we just convert the lists to LONG INTEGERS (64 bit)? no, most of the numbers won't fit unless
            you come up with a mechanism for using multiple LONG INTEGERS to represent an integer and handle adding them.

            add and carry while both lists have something
            when one list is exhausted work with other list and worry about a carryover until it disappears.

            l1 or l2 exhaustion

Contract:   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)

*/

/* Construct */

/**
 * Definition for singly-linked list.
**/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };


void printList(ListNode *list)
{
   // cout << list->val;

    ListNode *li = list;
    while (li != NULL)
    {
        cout << li->val << endl;
        li = li->next;
    }

    cout << endl;

}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *result = nullptr;
        ListNode *head = nullptr;;
        /* take care of some edge cases: null lists*/

        if (l1 == nullptr)
            return l2;

        if (l2 == nullptr)
            return l1;

        ListNode * a = l1;
        ListNode * b = l2;

        bool carryOver = false;

        while ((a != nullptr) && (b != nullptr))
        {
            int sum = a->val + b-> val;
            if (carryOver)
            {
                sum += 1;
                carryOver = false;
            }

            if (sum >= 10)
            {
                carryOver = true;
                sum = sum % 10;
            }

            ListNode *node = new ListNode(sum);

            if (result == nullptr)
            {
                result = node;
                head = result;
            }
            else
            {
                result->next = node;
                result = node;
            }

            // increment pointers
            a = a->next;
            b = b->next;

            // check for special case of both lists exhausting at same time
            if ((a == nullptr) && (b == nullptr))
            {
                if (carryOver)
                {
                    ListNode *node = new ListNode(1);
                    result->next = node;
                }

                return head;    
            }

        }



        /* if l1 is exhausted */

        if (a == nullptr)
        {
            while (b != nullptr)
            {
                // we don't worry about reusing memory from passed lists
                if (!carryOver)
                {
                    result->next = b;
                    return head;
                }


                int sum = b->val + 1;
                carryOver = false;

                // can only add 1 so max is 10 for carry over
                if (sum == 10)
                {
                    carryOver = true;
                    sum = 0;
                }

                ListNode *node = new ListNode(sum);
                result->next = node;
                result = node;      

                b = b->next;                     
            }                            

            if (carryOver)
            {
                ListNode *node = new ListNode(1);
                result->next = node;
                result = node;                          
            }

            return head; // b is exhausted
            
        }


        /* if l2 is exhausted */

        if (b == nullptr)
        {
            while (a != nullptr)
            {
                // we don't worry about reusing memory from passed lists
                if (!carryOver)
                {
                    result->next = a;
                    return head;
                }


                int sum = a->val + 1;
                carryOver = false;

                // can only add 1 so max is 10 for carry over
                if (sum == 10)
                {
                    carryOver = true;
                    sum = 0;
                }

                ListNode *node = new ListNode(sum);
                result->next = node;
                result = node;                          
                            
                a = a->next;
            }

            if (carryOver)
            {
                ListNode *node = new ListNode(1);
                result->next = node;
                result = node;                          
            }

        }
        

        return head;
    }

};


/* Confirm */

int main()
{

    Solution sol;

    //Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    //Output: 7 -> 0 -> 8
    //Explanation: 342 + 465 = 807.
    //(2 -> 4 -> 3) + (5 -> 6 -> 4)

    ListNode *num1a = new ListNode(3);
    ListNode *num1b = new ListNode(4);
    num1b->next = num1a;
    ListNode *num1c = new ListNode(2);
    num1c->next = num1b;

    ListNode *num2a = new ListNode(4);
    ListNode *num2b = new ListNode(6);
    num2b->next = num2a;
    ListNode *num2c = new ListNode(5);
    num2c->next = num2b;

    printList(num1c);
    printList(num2c);

    ListNode * result = sol.addTwoNumbers(num1c,num2c);

    printList(result);

  //  89 + 1 = 90
    ListNode *num3a = new ListNode(9);
    ListNode *num3b = new ListNode(9);
    num3b->next = num3a;

    ListNode *num4a = new ListNode(1);
    printList(num3b);
    printList(num4a);

    //result = sol.addTwoNumbers(num3b,num4a);
    result = sol.addTwoNumbers(num4a,num3b);

    printList(result);

//[0,8,6,5,6,8,3,5,7]
//[6,7,8,0,8,5,8,9,7]
//output: [6,5,5,6,4,4,2,5,5,1]
    //Explanation: 753865680 + 798580876 = 1552446556.

    ListNode *aa = new ListNode(7);
    ListNode *ab = new ListNode(5);
    ab->next = aa;
    ListNode *ac = new ListNode(3);
    ac->next = ab;
    ListNode *ad = new ListNode(8);
    ad->next = ac;
    ListNode *ae = new ListNode(6);
    ae->next = ad;
    ListNode *af = new ListNode(5);
    af->next = ae;
    ListNode *ag = new ListNode(6);
    ag->next = af;
    ListNode *ah = new ListNode(8);
    ah->next = ag;
    ListNode *ai = new ListNode(0);
    ai->next = ah;

    ListNode *ba = new ListNode(7);
    ListNode *bb = new ListNode(9);
    bb->next = ba;
    ListNode *bc = new ListNode(8);
    bc->next = bb;
    ListNode *bd = new ListNode(5);
    bd->next = bc;
    ListNode *be = new ListNode(8);
    be->next = bd;
    ListNode *bf = new ListNode(0);
    bf->next = be;
    ListNode *bg = new ListNode(8);
    bg->next = bf;
    ListNode *bh = new ListNode(7);
    bh->next = bg;
    ListNode *bi = new ListNode(6);
    bi->next = bh;
    printList(ai);
    printList(bi);

    result = sol.addTwoNumbers(ai,bi);

    printList(result);

}



/*** LEETCODE ACCEPTANCE RESULTS
 SUCCESS
Runtime: 32 ms, faster than 7.35% of C++ online submissions for Add Two Numbers.
Memory Usage: 10.1 MB, less than 92.57% of C++ online submissions for Add Two Numbers.
***/