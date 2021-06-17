#include <iostream>
#include <vector>
#include <math.h>


using namespace std;


class Solution
{

    private:
    template <class InputIterator, class OutputIterator>
    OutputIterator adjacent_difference (InputIterator first, InputIterator last,
                                       OutputIterator result)
    {
        if (first!=last) {
            typename std::iterator_traits<InputIterator>::value_type val,prev;
            *result = prev = *first;
    
            while (++first!=last) {
                val = *first;
                *++result = val - prev;  // or: *++result = binary_op(val,prev)
                prev = val;
            }
            ++result;
        }
        return result;
    }

    public:
     int maxProfitOnce(vector<int>& prices) {

         if (prices.size() <= 1)
            return 0;

        adjacent_difference(prices.begin(),prices.end(),prices.begin());

        int result = 0;
        int mmax = 0;
        for (int i = 1;i < prices.size() ;i++)
        {
            if ((result + prices[i]) <= 0)
            {
                result = 0;
                continue;
            }  
            else
            {
                result += prices[i];
                mmax = max(mmax, result);
            }
        }

        return mmax;        
    }

    int maxProfit(vector<int>& prices) {

         if (prices.size() <= 1)
            return 0;

        adjacent_difference(prices.begin(),prices.end(),prices.begin());

        int sum = 0;
        for (int i = 1;i < prices.size() ;i++)
        {
            if (prices[i] > 0)
            {
                sum += prices[i];
            }
        }

        return sum;        
    }

        void printVector(vector<int> input)
        {
            for (int i = 0;i< input.size();i++)
            {
                cout << input[i] << " " ;

            }
            cout << endl;
        }
        int hammingDistance(int x, int y) {
        
        int ham = x ^ y;
        
        // or |  1 0 = 1   1 1 = 1
        // and & 1 0 = 0   1 1 = 1
        // xor ^ 1 0 = 1   1 1 = 0
        
        int count = 0;
        
        while (ham > 0)
        {
            count += ham & 1;
            ham = ham >> 1;
        }
        
        return count;
    }
    
     int findComplement(int num) {

        if (num == 1)
            return 0;

        int size = 0;
        int tmp = num;
        while (tmp > 0)
        {
            tmp = tmp >> 1;
            size++;
        }
        
        num = num << (32 - size);
        
        num = num ^ 0xFFFFFFFF;
        
        num = num >> (32 - size);
        
        return abs(num);
        
    }
};

int main()
{
    Solution sol;

    vector<int> input = {7,1,5,3,6,4};

//    7 1 5 3 6 4
 //   0 -6 4 -2 3 -2

    cout << "max profit: " << sol.maxProfit(input) << endl;

    input = {7,6,4,3,1};

    cout << "max profit: " << sol.maxProfit(input) << endl;
    input = {8,1,6,4,3,8, 99, 44,2000};

    cout << "max profit: " << sol.maxProfit(input) << endl;
    cout << "hamming ( 1 , 4 ): " << sol.hammingDistance(1,4) << endl;

    cout << "complement: 1 " << sol.findComplement(1) << endl;
    cout << "complement: 5 " << sol.findComplement(5) << endl;
 }