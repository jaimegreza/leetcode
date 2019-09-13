#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

    int climbStairs(int n) {

        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        if (n == 2)
            return 2;
        
        vector<int> dp(n+1);

        dp[0]= 0;
        dp[1]= 1;
        dp[2]= 2;

        for (int i = 3;i <= n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairsSlow(int n) {
        

        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        int ret = 0;



        ret = climbStairs(n - 1) + climbStairs(n - 2);


        return ret;
    }
};
int main()
{
//    int n = 3; //3
    int n = 4; //5

    Solution sol;
    int ret = sol.climbStairs(n);

    cout << "res: " << ret << endl;

}