#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

   int maxProfit(vector<int>& prices) {
        
        int profit = 0;

        int size = prices.size();

        if ( (size == 0) || (size == 1) )
            return profit;

       
        for (int i = 1; i < size; i++)
        {

            int diff =  prices[i] - prices[i-1];
            
            if ((diff) >0)
                 profit = profit + diff;
            
       }

        return profit;
    }
    
   int maxProfitOneSOld(vector<int>& prices) {
        
        int profit = 0;

        int size = prices.size();

        if ( (size == 0) || (size == 1) )
            return profit;

        int prev = 0;
        
        for (int i = 1; i < size; i++)
        {

            int diff =  prices[i] - prices[i-1];
            
            if ((diff + prev) <=0)
            {
                profit = max(profit, prev);
                prev = 0;
            }
            else
            {
                profit = max(profit, diff + prev);
                prev = diff + prev;
            }
       }

        return profit;
    }

    int maxProfitTwoPass(vector<int>& prices) {
        
        int profit = 0;

        int size = prices.size();

        if ( (size == 0) || (size == 1) )
            return profit;

        int idx = 0;

        while (idx < size)
        {
            for (int j = idx; j < size;j++)
            {
                int cur =  max(profit, (prices[j] - prices[idx]));
                if ( cur > profit )profit = cur;
            }
            idx++;
        }
   
        return profit;

    }

    int maxProfitSpaceEfficient(vector<int>& prices) {
        
        int profit = 0;

        int size = prices.size();

        if ( (size == 0) || (size == 1) )
            return profit;

        for (int i = 0; i < size;i++)
        {
            int m = 0;
            for (int j = i; j < size;j++)
            {
                int cur =0;
                if (i == j)
                {
                    cur = 0;
                }
                else
                    cur =  max(m, (prices[j] - prices[i]));
         
                if ( cur > m )m = cur;
            }
            prices[i] = m;
        }

        for (int i = 0; i < size;i++)
        {
            profit = max(profit,prices[i]);
        }   
        return profit;

    }


    int maxProfitGood(vector<int>& prices) {
        
        int profit = 0;

        int size = prices.size();

        if ( (size == 0) || (size == 1) )
            return profit;

        vector<int> dp(size,0);

        for (int i=0;i < size;i++)
        {
            dp[i] = prices[i];
        }

        for (int i = 0; i < size;i++)
        {
            int m = 0;
            for (int j = i; j < size;j++)
            {
                int cur =0;
                if (i == j)
                {
                    cur = 0;
                }
                else
                    cur =  max(m, (prices[j] - prices[i]));
         
                if ( cur > m )m = cur;
            }
            dp[i] = m;
        }

        for (int i = 0; i < size;i++)
        {
            profit = max(profit,dp[i]);
        }   
        return profit;

    }


     int maxProfitMemory(vector<int>& prices) {
          int profit;

       // if (prices == NULL)
         //   return max;

        int size = prices.size() + 1;

        vector<int> row(size,0);
        vector<vector<int>> dp( (size), row);

        for (int i=1;i < size;i++)
        {
            //dp[0][i] = prices[i-1];
            dp[i][0] = prices[i-1];
        }

        for (int i = 1; i< size;i++)
        {
            for (int j = i; j < size; j++)
            {
                int m ;
                if (i ==j)
                    m =  max( dp[i-1][j], (prices[j-1] - prices[i-1]));
                else
                    m =  max( max(dp[i][j-1], dp[i-1][j]), (prices[j-1] - prices[i-1]));
                dp[i][j] = m;
            }

        }
        profit = dp[size-1][size-1];
        return profit;

    }
};

int main()
{
    Solution sol;
    vector<int> input = {7,1,5,3,6,4};
 //   vector<int> input = {7,1,6};
  //     vector<int> input = {1,2};
       
        int max = sol.maxProfit(input);

    cout << "max: " << max << endl;
}