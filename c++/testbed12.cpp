#include <iostream>
#include <vector>


using namespace std;

class FrogJump
{
private:

    int NumWaysTempVars(int n)
    {
        if (n == 0)
            return 1;

        if (n == 1)
            return 2;


        int ts = 1;
        int tb = 2;
        int t;
        for (int i = 2; i <= n;i++)
        {
            t = ts + tb;
            ts = tb;
            tb = t;
        }

        return t; 

    }


    int NumWaysIterative(int n)
    {
        return NumWaysTempVars(n);


        if (n == 0)
            return 1;

        if (n == 1)
            return 2;

        vector<int> dp(n+1);

        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= n;i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n]; 

    }

    int NumWays(int n)
    {
        return NumWaysIterative(n);

        static std::vector<int> table; // our cache
        if (n <= 1) {

            // no stones - only 1 way
            if (n == 0)
                return 1;

            // 1 stone - only 2 ways
            if (n == 1)
                return 2;
        }
        else if (n >= table.size()) {
            table.resize(n+1);
        }
    
        if (table[n] == 0) {
            // only recalc if we don't have a value
            table[n] = NumWays(n-1) + NumWays(n-2);
        }
        return table[n];
    

    }


public:
    int NumWaysFrogJump(int stones)
    {

        return NumWays(stones);
        // [  -   .   -  .  -  .  - .  - ]
        
        
        // no stones - only 1 way
        if (stones == 0)
            return 1;

        // 1 stone - only 2 ways
        if (stones == 1)
            return 2;
        
        return  NumWaysFrogJump(stones - 2 ) + NumWaysFrogJump(stones - 1);

    }

};

int main()
{

    FrogJump frog;

    int num = frog.NumWaysFrogJump(11);
    cout << "mum ways: " << num << endl;

    return 0;
}