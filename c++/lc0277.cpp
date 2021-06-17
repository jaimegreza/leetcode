#include <iostream>


using namespace std;

/*
n people label 0 to n -1
all n-1 people know the 1 celebrity but celebrity doesnt know anyone

hi A, do you know B?
bool knows(A, B)

if A knows B  then A cannot be a celebrity
if B knows A  then B cannot be a celebrity
if B !know A then B could be a celebrity
if A !know B then A could be a celebrity
if A knows B AND B !know A , B could be a celebrat

int findCelebrity(n)
return -1  no celebrity
*/

class Solution
{
    public:
        int find Celebrity(int n)
        {
            int candidate = 0;

            for (int i = 1;i < n;i++)
            {
                if (knows(candidate,i))
                {
                    candidate = i;
                }
            }

            for (int i = 0; i < n;i++)
            {
                if ((i != candidate) && (knows(candidate,i) || !knows(i,candidate))
                    return -1;
            }
            return candidate;
        }
};

int main()
{
    Solution sol;
}