#include <iostream>
#include <vector>

using namespace std;

class SubSetsTo16
{
private:

public:
    SubSetsTo16(){};

    int NumSubsetsTo16(vector<int> input, int target)
    {
        int count = 0;
        
        vector< vector<int> > dp(input.size(), vector<int>(target+1));

        for (int i = 0; i < input.size();i++){
            dp[i][0] = 1;   
        }

        //  [       0   1   2   3   4   5   6 ]
        //  [ 1     T   T   F   F   F   F   F]
        //  [ 2     T   T   T       ]
        //  [ 3     T  ]  
        //  [ 6     T   ]

        for (int i = 0; i < input.size();i++){
            for (int j = 0;j < target+1;j++){

                if (input[i-1] <= j)
                {
                   if (i != 0)
                        dp[i][j] = dp[i-1][j - input[i-1]];
                    else if (input[i-1] == j)
                        dp[i][j] = 1;
                }
                else 
                {
                    if (i != 0)
                        dp[i][j] = dp[i-1][j];
                }

            }
        }

        for (int i = 0; i < input.size();i++){
            for (int j = 0;j < target+1;j++){
                cout << dp[i][j] << " " ;
            }
            cout << endl;
        }

        return dp[input.size()-1][target+1];
    }



};

int main()
{
    SubSetsTo16 sub16;

//    vector<int> input = {2,4,6,10,16,32};
    vector<int> input = {1,2,3,6};
    
    int count =  sub16.NumSubsetsTo16(input,6);

    cout << count << endl;
    return 0;
}