#include <iostream>
#include <vector>
#include <string>
#include <math.h>


using namespace std;

class Solution {
public:


    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
            
        if (nums.size() <= 2)
            return result;




        

        return result;

    }


    string intToRoman(int num) {

        

    }


    int maxAreaSlow(vector<int>& height) {


        if (height.size() <= 1)
            return 0;
    
        int maxA = 0;

        for (int i = 0;i< height.size();i++)
        {
            for (int j= i+1; j < height.size();j++)
            {
                int area = 0;
                area = min(height[i],height[j]);
                area = area * (j-i);

                if (area > maxA)
                    maxA = area;
            }
        }   
        
        return maxA;
    }
    
    int maxArea(vector<int>& height) {


        if (height.size() <= 1)
            return 0;
    
        int maxA = 0;


        int i = 0;
        int j = height.size() - 1;
            
        while ( i < j)
        {
            int area = 0;
            area = min(height[i],height[j]);
            area = area * (j-i);

            if (area > maxA)
                maxA = area;
            
            //
            if (height[i] < height[j])
                i++;
            else
                j--;
        }   
        
        return maxA;
    }


    string convert(string s, int numRows) {

        if (numRows <= 1)
            return s;
        
        if (s.size() <= 1)
            return s;

        bool bDirDown = true;

        int idx = 0;

        int process = s.size();

        vector<vector<string>> dp(numRows);

        int i = 0;
        int j = 0;

        while (idx < process)
        {
            dp[i].resize(dp[i].size()+1);
            dp[i][dp[i].size()-1] = s[idx++];

            if (bDirDown)
            {
                
                if (i == numRows -1)
                {
                    i--;
                    bDirDown = false;    
                }
                else
                {
                    i++;               
                }
            }
            else
            {
                if (i == 0)
                {
             
                    i++;
                    bDirDown = true;    
                }
                else
                    i--;                
            }

        }

        string result;

        for (int i = 0;i < dp.size() ;i++)
        {
            vector<string> vec = dp[i];

            for (int j = 0;j < vec.size();j++)
            {
                result = result.append(vec[j]);
            }
        }

        return result;

    }

    string longestPalindrome(string s) {

        
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));

        string longest;


        if (s.size() == 0)
            return longest;

        if (s.size() == 1)
            return s;
        
        // l  = 1

        for (int i = 0;i < s.size();i++)
        {
            dp[i][i] = true;
        }
        int lIdx = 0;
        int ls = 1;


        // l = 2
        for (int i = 0;i < s.size()-1;i++)
        {
            if (s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                lIdx = i;
                ls = 2;
            }
        }

        // l > 2

        for (int l = 3;l <= s.size();l++)
        {
            for (int i = 0;i < s.size() - l + 1;i++)
            {
                int j = i + l - 1;

                if ((s[i] == s[j]) && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    lIdx = i;
                    ls = l;
                }

            } 
        }

        longest = s.substr(lIdx,ls);
        return longest;
        
    }
};

int main()
{

    Solution sol;

    string pal = "abaxabaxabb";

    

    //string result =   sol.longestPalindrome(pal);
    string zigzag = "PAYPALISHIRING"; //PAHNAPLSIIGYIR

    //string result = sol.convert(zigzag, 3);
    //cout << result << endl;

    vector<int> height = {1,8,6,2,5,4,8,3,7}; //49

    vector<int> nums = {-1, 0, 1, 2, -1, -4}; 

///    cout << sol.maxArea(height) << endl;
    vector<vector<int>> result =  sol.threeSum(nums);

    



}