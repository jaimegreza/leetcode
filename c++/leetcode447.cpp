#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;


class Solution
{

public:

    int numberOfBoomerangs(vector<pair<int, int>>& points) {

        if (points.size() < 3)
            return 0;

        int count = 0;

        for (int i = 0;i<points.size();i++)
        {
            for (int j = i+1; j < points.size();j++)
            {
                for (int k = j+1;k < points.size();k++)
                {
                    if (isBoomerange(points[i],points[j],points[k]))
                        count++;
                }

            }

        }    

        return 2*count;
    }

    bool isBoomerange(pair<int,int> i, pair<int,int> j,pair<int,int> k)
    {
        if (distance(i,j) == distance(i,k))
            return true;
        else   
            return false;
    }


    int distance(pair<int,int> a, pair<int,int> b)
    {
        return sqrt( (a.first - b.first)^2  + (a.second - b.second)^2);


    }

     vector<int> findDisappearedNumbers(vector<int>& nums) {


//         4,3,2,7,8,2,3,1
  //       1,2,3,4,5,6,7,8

        
        int n = nums.size();

        vector<int> res;

        int sum = n*(n+1)/2;
        int sumArray = 0;

        for (int i = 0;i < n;i++)
        {
            int value = abs(nums[i])-1;
            if (nums[value] > 0){
                nums[value] = -nums[value];
            }
        }

        for (int i = 0; i < n; i++){
            if (nums[i] > 0){
                res.push_back(i+1);
            }
        }

        return res;
    }

     void printVector(vector<int> &input)
    {
        for (int i = 0;i< input.size();i++)
        {
            cout << input[i] << " " ;

        }
        cout << endl;
    }

    int minMoves(vector<int>& nums) 
    {
        
        if (nums.size() < 1)
            return 0;

        int count = 0;
        int maxIdx = 0;
        int max = nums[0];
        int low = max;

        for (int i = 1; i < nums.size();i++)
        {
            if (nums[i] > max)
            {
                maxIdx = i;
                max = nums[i];
            }

            if (nums[i] <  low)
            {
                low = nums[i];
            }
        }

        if (low == max)
            return 0;

        int diff = 0;
        
        for (int i = 0;i < nums.size();i++)
        {
            diff += nums[i] - low;
        }

        while (diff > 0)
        {
            int oldMaxId = maxIdx;

            for (int i = 0;i < nums.size();i++)
            {
                
                if (nums[i] > max)
                {
                    max = nums[i];
                    maxIdx = i;
                }

                if (i == maxIdx){
                    continue;
                }
                else
                {
                    nums[i]++;
                }

            }
            count++;
            diff--;
        }
        return count;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {

        int children = g.size();
        int cookies = s.size();
        
        if (cookies == 0)
            return 0;

        if (children == 0) 
            return 0;

        int max = 0;

        vector<vector<int>> dp(cookies+1,vector<int>(children+1));

        for (int i = 1 ;i <= children;i++)
        {
            dp[0][i] = g[i-1];
        }
        for (int i = 1 ;i <= cookies;i++)
        {
            dp[i][0] = s[i-1];
        }
        // 0 1 2
        // 1 1 0
        // 2 1 2
        // 3 1 2

        for (int i = 1; i <= cookies;i++)
        {
            for (int j = 1; j <= children;j++)
            {

                int canHave = 0;
                if (dp[i][0] >= dp[0][j])
                    canHave = dp[i][0];

                if (i == 1)
                {
                    dp[i][j] = canHave;
                }
                else{
                    if (canHave > 0)
                    {
                        dp[i][j] = (dp[i-1][j] < canHave) ? dp[i-1][j] : canHave ; 
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }

        }

        // process map
        map<int,int> map;

        for (int i = 0;i< s.size();i++)
        {
            map[s[i]] += 1;
            cout << "map: " << map[s[i]] << " s[i]: " << s[i] << endl;
        }


        for (int i = 1;i <= children;i++)
        {
            if (map[dp[cookies][i]] > 0)
            {
                cout << "res: " << map[dp[cookies][i]] << " dp[cookies][i]: " << dp[cookies][i] << endl;

                map[dp[cookies][i]] -= 1;
                max += 1;
            }
        }

        return max;

    }

    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

        int cnt = 0;
        vector<int> bucks(buckets, 15);
        
        cnt = (buckets*minutesToDie)/minutesToTest;

        return cnt;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        int cnt = 0;

        for (int i = 0 ; i < r;i++)
        {
            for (int j = 0;j < c ;j++)
            {
                if (grid[i][j])
                {
                    //check top
                    if (i == 0)
                    {
                        cnt++;
                    } else if (!grid[i-1][j]) {
                        cnt++;
                    }
                    //check bottom
                    if (i == r-1)
                    {
                        cnt++;
                    } else if (!grid[i+1][j]) {
                        cnt++;
                    }
                    //check left 
                    if (j == 0)
                    {
                        cnt++;
                    } else if (!grid[i][j-1]) {
                        cnt++;
                    }
                    
                    //check right
                    if (j == c-1)
                    {
                        cnt++;
                    } else if (!grid[i][j+1]) {
                        cnt++;
                    }

                }
            }
        }
        return cnt;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int min = 0;
        
        for (int i = 0;i< houses.size();i++)
        {
            int diff = INT_MAX;
            bool bFoundLeft = false;
            bool bFoundRight = false;
            
            for (int j = 0;j<heaters.size();j++)
            {
                int sep = abs(houses[i] - heaters[j]);
                
                if (heaters[j] <= houses[i])
                    bFoundLeft = true;
                
                if (heaters[j] > houses[i])
                    bFoundRight = true;
                
                if (houses[i] <= heaters[j])
                    bFoundLeft = true;
                
                if (sep < diff)
                    diff = sep;
                
                if (bFoundLeft && bFoundRight)
                    break;
            }
            
            if (min < diff)
            {
                min = diff;
            }
            
        }
        return min;
        
    }

    int findComplement(int num) {
        int cnt = 0;
        int comp = num;
        while (comp > 0)
        {
            comp = comp>>1;
            cnt++;
        }
        
        comp = ~num;
        
        for (int i =0;i < 32-cnt;i++)
        {
            comp = comp << 1;
        }
        
        for (int i =0;i < 32-cnt;i++)
        {
            comp = comp >> 1;
        }
        
        return comp;        
    }
};

int main()
{
  //  vector<pair<int,int>> input = {{0,0},{1,0},{2,0}};

   // vector<int> in = {4,3,2,7,8,2,3,1};
    Solution sol;

//    vector<int> res = sol.findDisappearedNumbers(in);

   // sol.printVector(res);

    //vector<int> in2 = {1,2,3};
    // sol.printVector(in2);

    //cout << " min moves: " <<  sol.minMoves(in2)<< endl;
    //vector<int> s = {1,1};
    //vector<int> g = {1,2,3};
    


    //sol.printVector(g);
   // cout << " max cookies: " <<  sol.findContentChildren(g,s)<< endl;
    
     //sol.printVector(s);

    vector<vector<int>> in = {  {0,1,0,0},
                                {1,1,1,0},
                                {0,1,0,0},
                                {1,1,0,0}   };

    //cout << " perims: " <<  sol.islandPerimeter(in) << endl;
    
    cout << " comp: " <<  sol.findComplement(5) << endl;
    

}