#include <iostream>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {

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
};
int main()
{
    Solution sol;

    int ret;
    int x = 2147395599; //46339
//    int x = 4; // 2
    ret = sol.mySqrt(x);
    cout << "sqrt: " << x << endl;
    cout << "ret: " << ret << endl;

}