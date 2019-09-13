#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:

 bool isPerfectSquare(int num)
     {
         double sqrt = mySqrt(num);
         int sq = (int) sqrt*sqrt;

         return (sq == num) ? true : false;
     }
    
    double mySqrt(int num) {
        int x = num;
        
         if (x == 0)
            return 0;
   
        if (x == 1) 
            return 1;

        if (x == 4)
            return 2;

        double est = 0.0;
        double avg  = 0.0;

        est = mySqrt(x/2);

        avg = ((est + x/est))/2.0;

        double prev;
        prev = avg;

        while (1)
        {
            avg = ((prev + x/prev))/2.0;
            
            if ((int) avg != (int) prev)
                prev = avg;
            else
                break;
        }
        return avg;
    }

     string reverseVowels(string s) {
     if (s.length() <= 1)
            return s;
        
        int end = s.length()-1;
        int beg = 0;
        
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        
        while (end > beg)
        {
            
            bool bEndFound = false;
            bool bBegFound = false;
            
            char tempEnd = s[end];
            
            while (!bEndFound)
            {
                if (vowels.find(tempEnd) != vowels.end())
                {
                    bEndFound= true;
                }
                else
                    end--;
                
                if (end < beg)
                {
                    return s;
                }
                
                
                tempEnd = s[end];
            }

            char tempBeg = s[beg];

            while (!bBegFound)
            {
                if (vowels.find(tempBeg) != vowels.end())
                {
                    bBegFound= true;
                }
                else
                {
                    beg++;

                }
                    
                if (beg > end)
                {
                    return s;
                }

                tempBeg = s[beg];                
            }

            if (bBegFound && bBegFound) 
            {
                s[end] = tempBeg;
                s[beg] = tempEnd;
            }
            end--;
            beg++;
            
        }
        return s;     
    }
     
     
     bool isPowerOfThree(int n) {

        if (n == 1)
            return true;        
        
        if (n <= 2)
            return false;       

        while(n >= 3)
        {
            
            if (!(n%3 == 0))
                return false;
            
            n = n/3;
        }
            
        return (n == 1) ? true : false;

    }

    bool canWinNim(int n) {
        
        int rem = n%4;

        return (rem >  0) ? true : false;

        if (n <= 3)
            return true;
        
        if (n == 4)
            return false;

        vector<int> dp(n+1);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 0;

        for (int i = 5; i <=n ;i++)
        {
            dp[i] = (dp[i-1] || dp[i-2] | dp[i-3]);

        }

        return dp[n];

    }


};

class NumArrayLarge{
private:
     vector< vector<int> > dp;
    

public:
    NumArrayLarge(vector<int> nums) {

        if (nums.size() == 0)
        {
            return;
        }

        dp.resize(nums.size());

        dp[0].resize(nums.size());

        dp[0] = nums;

        for (int i = 0;i < nums.size();i++)
        {
            if (i != 0)
                dp[i].resize(nums.size());
            
            for (int j = i; j < nums.size();j++)
            {
                if (i == j)
                    dp[i][j] = nums[j];
                else
                    dp[i][j] = dp[i][j-1] + nums[j];
            }

        }
        
    }
    
    int sumRange(int i, int j) {

        if (dp.size() == 0)
            return 0;

        return dp[i][j];
    }
};

class NumArray{
private:
     vector<int> dp;
    

public:
    NumArray(vector<int> nums) {

        if (nums.size() == 0)
        {
            return;
        }

        dp = nums;
        
        for (int i = 1;i < nums.size();i++)
        {
            dp[i] += dp[i-1];
        }
        
    }
    
    int sumRange(int i, int j) {

        if (dp.size() == 0)
            return 0;

        int sum = 0;
        if ( i == 0)
            sum = dp[j];
        else
            sum = dp[j] - dp[i-1];

        return sum;
    }
};

int main()
{

    Solution sol;
//19682
    //cout << "win? " << sol.isPowerOfThree(6) << endl;
cout << "win? " << sol.isPerfectSquare(16) << endl;

  //  string s1 = "hello";
    //cout << "win? " << sol.reverseVowels(s1) << endl;



    return 0;
    /**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    NumArray *obj = new NumArray(nums);
    int param_1 = obj->sumRange(0,2);

    cout << "sum: " << param_1 << endl;
    
    int param_2 = obj->sumRange(2,5);
    cout << "sum2: " << param_2 << endl;
    
    int param_3 = obj->sumRange(0,5);
    cout << "sum3: " << param_3 << endl;

//sumRange(0, 2) -> 1
//sumRange(2, 5) -> -1
//sumRange(0, 5) -> -3


}