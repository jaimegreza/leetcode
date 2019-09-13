#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
     vector<int> getRow(int rowIndex) {

       vector<vector<int>> result;
       vector<int> row;

        if (rowIndex == 0)
        {
            row.push_back(1);
            return row;
        }
        result = generate(rowIndex+1);

        row = result[rowIndex];
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;

        if (numRows == 0)
            return result;

        vector<int> apex;
        apex.push_back(1);
        result.push_back(apex);

        for (int i= 1;i<numRows;i++)
        {
            vector<int> row(i+1);
            row[0] = 1;
            row[row.size()-1] = 1;

            for (int j=1; j < (row.size()-1);j++)
            {
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(row);
        }

        return result;

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> result;
    int n = 5;

    result = sol.generate(n);
    vector<int> row;

    row = sol.getRow(n);

    cout << "n:" << endl;

}