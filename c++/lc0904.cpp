#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:

    int numDecodings(string s) {

        if (s.length() == 0)
            return 0;
        
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n));
        int ways = 0;

        for (int i = 0;i < n;i++)
        {
            dp[0][i] = i+1;
        }

        for (int r = 1;r < n;r++)
        {
            for (int c = r;c < n;c++)
            {


                if (r == c)
                {
                    dp[r][c] = dp[r-1][c] + validate(s.substr(0,c));
                }
                else
                {
                    dp[r][c] = dp[r-1][c] + dp[r][c-1];    
                }
            }
        }


        return dp[n-1][n-1];


    }

    int validate(string s)
    {
        int num = std::atoi(s.c_str());

        if (num <= 26)
            return 1;
        else
            return 0;

    }

    int totalFruit(vector<int>& tree) {

        if (tree.size() == 0)
            return 0;

        if (tree.size() == 2)
            return 2;

        int n = tree.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1));

        for (int i = 1;i <= n;i++)
        {
            dp[0][i] = tree[i-1];
            dp[i][0] = tree[i-1];
        }

        // trees at row 0, cols 1 to n
        // trees at col 0, rows 1 to n

        for (int r = 1;r <= n;r++)
        {
            int bk1 = -1;
            int bk2 = -1;
            bool bStop = false;

            for (int c = r;c <= n;c++)
            {

                if (r == n)
                {
                    dp[r][c] = dp[r-1][c];
                }
                if (r == c)
                {
                    dp[r][c] = 1;
                    bk1 = dp[r][0];
                    bk2 = bk1;
                    continue;
                }

                if (bStop)
                {
                    if (r != 1)
                        dp[r][c] = max(dp[r][c-1], dp[r-1][c]);
                    else
                        dp[r][c] = dp[r][c-1];
                    continue;
                }

                // currrent type fruit in [0][c]
                // fruit comparing in [r][0]
                if (bk1 == bk2)
                {
                    if (dp[0][c] != bk1)
                    {
                        bk2 = dp[0][c];
                    }                        
                    dp[r][c] = dp[r][c-1]+1;
                }
                else if (dp[0][c] == bk2)
                {
                    if (c != n)
                        dp[r][c] = dp[r][c-1]+1;
                    else
                    {
                        dp[r][c-1] = dp[r][c-1] + 1;
                        bStop = true;
                    }
                }
                else if (dp[0][c] == bk1)
                {
                    if (r != 1) 
                        dp[r][c] = max(dp[r][c-1], dp[r-1][c]);
                    else
                        dp[r][c] = dp[r][c-1] +1;
                    continue;
                }
                else
                {
                    bStop = true;
                }
            }

        }
        return dp[n][n];

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int oldColor = image[sr][sc];

        if (oldColor == newColor)
            return image;

        dfsImageRecursive(image,sr,sc,oldColor,newColor);
        return image;
    }

    void dfsImageRecursive(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {

        if (checkBounds(image, r,c))
        {
            if (image[r][c] == oldColor)
            {
                image[r][c] = newColor;
     
                dfsImageRecursive(image,r,c-1,oldColor,newColor);
                dfsImageRecursive(image,r,c+1,oldColor,newColor);
                dfsImageRecursive(image,r-1,c,oldColor,newColor);
                dfsImageRecursive(image,r+1,c,oldColor,newColor);
            }
        }
    }

    bool checkBounds(vector<vector<int>>& image, int r, int c)
    {
        int max_row_idx = image.size() -1;
        int max_col_idx = image[0].size() - 1;

        if ( (r > max_row_idx) || (r < 0) )
            return false;

        if ( (c > max_col_idx) || (c < 0) )
            return false;

        return true;
    }

    void printVectorVectors(vector<vector<int>> input)
    {
        for (auto r : input)
        {
            for (int i = 0;i< r.size();i++)
            {
                cout << r[i] << " " ;
            }
            cout << endl;            

        }
    }

    void printVector(vector<string> input)
    {
            for (int i = 0;i< input.size();i++)
            {
                cout << input[i] << " " ;

            }
            cout << endl;
    }

};

int main()
{
    Solution sol;
    vector<int> trees = {1,2,1};

    cout << "num: "  <<  sol.totalFruit(trees) << endl;

    vector<vector<int>> image = {   {1,1,1},
                                    {1,1,0},
                                    {1,0,1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;

    sol.printVectorVectors(image);
    sol.floodFill(image,sr,sc,newColor);
    sol.printVectorVectors(image);

    string s = "ABC";

    cout << "num ways: " << sol.numDecodings(s) << endl;

}