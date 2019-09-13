#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        
        if (r == 0)
            return nums;

        if (c == 0)
            return nums;

        int rows = nums.size();
        int cols = nums[0].size();

        int numElements = rows*cols;

        if (numElements != r*c)
            return nums;

        int newC = numElements/r;
        int newR = numElements/c;
        
        vector<vector<int>> res(newR,vector<int>(newC));

        for (int i = 0;i< numElements;i++)
        {
           res[i/newC][i%newC] = nums[i/cols][i%cols];
        }

        return res;
    }

    void printMatrix(vector<vector<int>> &input)
    {
        for (int i = 0;i< input.size();i++)
        {
            for (int j = 0;j< input[0].size();j++)
            {
                cout << input[i][j] << " " ;

            }
            cout << endl;

        }
    }


    int distributeCandies(vector<int>& candies) {

       // sort(candies.begin(),candies.end());

        set<int> s (candies.begin(),candies.end());
        return s.size() <= candies.size()/2 ? s.size() : candies.size()/2;
    }

    int findUnsortedSubarray(vector<int>& nums) {

        int sum  = 0;
        int begin = INT_MIN;
        int end = INT_MIN;
        int minMin = INT_MAX;

        bool bIncrease  = false;

        for (int i = 0;i< nums.size();i++)
        {
            if (end <= nums[i])
            {
                end = nums[i];
                continue;
            }

            if (end >= nums[i])
            {
                bIncrease = true;
            }

            if (nums[i] < end)
            {
                begin = nums[i];
                sum = begin - end;
                int min = 0;

                if (bIncrease)
                    min=1;

                while (end >= sum)
                {
                    i++;
                    min++;
                    begin = nums[i];
                    sum = begin - end;
                    if (i == nums.size()-1)
                        break;
                }
                if (minMin > min)
                {
                    minMin = min;
                }
            }
        }
        if (minMin ==  INT_MAX)
            return 0;
        
        return minMin;
    }

    int findLHS(vector<int>& nums) {


        map<int,int> map;

        for (int i=0;i < nums.size();i++)
        {
            map[nums[i]]++;
        }

        int big = 0;

      //  map<int,int>::iterator itr = map.begin():

        int maxl =0;
            
         for(auto x : map)
         {
                maxl = max( maxl, 
                            max(    map.count(x.first+1) ? map[x.first] + map[x.first+1] : 0, 
                                    map.count(x.first - 1)? map[x.first] + map[x.first - 1] : 0));
         }

        return maxl; 

    }


     bool canPlaceFlowers(vector<int>& flowerbed, int n) {

         if (n == 0)
            return true;
          
        int oneFlag = false;
        int zeroFlag = false;
        int canPlace = false;
        for (int i = 0;i < flowerbed.size();i++)
        {
            if (flowerbed[i] ==1 )
            {
                oneFlag = true;
                zeroFlag = false;
                canPlace = false;
                continue;
            }

            if (flowerbed[i] == 0 )
            {
                if (oneFlag)
                {
                    zeroFlag =  true;
                    oneFlag = false;
                    canPlace = false;
                    continue;
                }
                else 
                {
                    canPlace = true;
                    zeroFlag =  true;
                    oneFlag = false;
                }

                if (canPlace)
                {
                    if (i < flowerbed.size()-2)
                    {
                        if (flowerbed[i+1] == 0)
                        {
                            n--;
                            i++;
                            if (n == 0)
                                return true;
                            continue;
                        }

                    }

                    if (i == flowerbed.size()-1)
                    {
                        n--;
                        if (n == 0)
                            return true;
                    }

                    canPlace = false;

                    
                }

            }


        }
                       
        return false;
    }

    int calPoints(vector<string>& ops) {
        
        if (ops.size() == 0)
            return 0;
        
        int a = 0;
        int b = 0;



    }


    vecto<int> getMarathon(int n)
    {
        vector<int> res;
        for (int i = 0;i <= n;i++)
        {
            if (isTricky(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isTricky(int n)
    {
        string num;
        set<int> reg  = {2,3,4,5,7}

        bool bMostSignif = true;
        while (n > 0)
        {
            int t = n%10;

            if ((bMostSignif && (t == 0)) // leading zero
                return true;
            else
                bMostSignif = true;

            if (reg.find(t) != reg.end())
            {
                return false;
            }

            num.push_back(to_string(t));

        }

        if (!isSymetric(num))
        {
            return true;
        }

        return false;

    }

    bool isSymetric(string num)
    {
        set<int> sym  = {0,1,8};
        set<int> nsym  = {6,9};

        int low = 0;
        int high = num.length() -1;

        while (low < high)
        {

            bool bLowSym = (sym.find(num[low]) != sym.end());
            bool bHighSym = (sym.find(num[high]) != sym.end());

            if (bLowSym && bHighSym)
            {
                low++;
                high--;
                continue;
            }

            bool bLowNSym = (nsym.find(num[low]) != nsym.end());
            bool bHighNSym = (nsym.find(num[high]) != nsym.end());

            if (bLowNSym && bHighNSym)
            {   
                low++;
                high--;
                continue;
            }

            if (num[low] != num[high])
                return false;

        }

        return false;
    }


};

int main()
{
    //vector<vector<int>> nums = {{1,2},
      //                          {3,4}};
    
    
    Solution sol;
  //  cout << 0%1 << endl;

    //sol.printMatrix(nums);
    //vector<vector<int>> res = sol.matrixReshape(nums,2,2);
    //sol.printMatrix(res);

//    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
   // vector<int> nums = {1,3,2,2,5,2,3,7};
    vector<int> nums = {0,1,0,1,0,1,0,0};
    vector<string> ops = {"5","2","C","D","+"};

    cout << sol.calPoints(ops) << endl;

}