#include <iostream>
#include <vector>
using namespace std;

class MyClass
{
public:
    MyClass(){};

    int fib(int n)
    {   
        if (n <=1)
            return n;

        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n;i++)
        {
            dp[i] = dp[i-2] + dp[i - 1];
        }

        return dp[n]; 
    }

    int fib2(int n) {
        static std::vector<int> table; // our cache
        if (n <= 1) {
            return n;
        }
        else if (n >= table.size()) {
            table.resize(n+1);
        }
    
        if (table[n] == 0) {
            // only recalc if we don't have a value
            table[n] = fib(n-1) + fib(n-2);
        }
        return table[n];
    }

private:
    
};


int main()
{
    MyClass mine;

    cout << mine.fib2(7) << endl;

    return 0;
}
