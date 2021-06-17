#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

class Solution
{
    public:
        int countBattleships(vector<vector<char>>& board) {
        
            bool onShip = false;
            int max_row_idx = board.size() -1;
            int max_col_idx = board[0].size() - 1;

            int count = 0;

            for (int row = 0; row<= max_row_idx;row++)
            {
                for (int col = 0; col<= max_col_idx;col++)
                {                    
                    if (board[row][col] == 'X')
                    {
                        if (onShip && checkBounds(board, row, col+1)) //check right
                        {
                            if (board[row][col+1] == '.')
                            {
                                count++;
                                onShip = false;
                            }
                            else // must be an 'x'
                            {
                                continue;
                            }
                        } else if (onShip && !checkBounds(board, row, col+1)) // boundar at right
                        {
                            count++;
                            onShip = false;
                        }
                        else 
                        {
                            if (checkBounds(board, row, col+1) &&
                                (board[row][col+1] == 'X'))// check right
                            {
                                onShip = true;
                            }
                            else if (!checkBounds(board, row, col+1))  //check right border
                            {
                                if (!checkBounds(board, row+1, col)) // check down border
                                {
                                    count++;
                                }
                                else if (board[row+1][col] == '.')
                                {
                                    count++;
                                }
                            }
                            else if (checkBounds(board, row+1, col))// check down
                            {
                                if (board[row+1][col] == '.')
                                {
                                    count++;                                
                                }
                            }
                            else if (!checkBounds(board, row+1, col))
                            {
                                count++;
                            }
                        }
                    }
                    else // on a dot
                    {
                        onShip = false;
                        continue;
                    }                
                }
            }
        
            return count;
        }
    private:

        int dfs(vector<vector<char>>& grid, int r, int c) {
            //return dfs_visit(grid, r, c) >= 1 ?  1 : 0;
            return dfs_visit(grid, r, c);
        }

        int dfs_visit(vector<vector<char>>& grid, int r, int c)
        {

            if (checkBounds(grid, r, c))
            {
                if (grid[r][c] == '0')
                {
                    return 0;
                }               

                grid[r][c] = '0';
                int size = 1;
                size += dfs_visit(grid, r + 1, c);
                size += dfs_visit(grid, r - 1, c);
                size += dfs_visit(grid, r, c - 1);
                size += dfs_visit(grid, r, c + 1);
                return size;
            }

            return 0;
        }

        bool checkBounds(vector<vector<char>>& grid, int r, int c)
        {
            int max_row_idx = grid.size() -1;
            int max_col_idx = grid[0].size() - 1;

            if ( (r > max_row_idx) || (r < 0) )
                return false;

            if ( (c > max_col_idx) || (c < 0) )
                return false;

            return true;
        }


    public:

        int numIslands(vector<vector<char>>& grid) {

            if (grid.size() == 0)
                return 0;

            int result=0;
            // rows, cols

            cout << "num rows: " << grid.size() << endl;
            cout << "num cols: " << grid[0].size() << endl;

            int mmax = 0;

            for (int r = 0;r < grid.size();r++)
            {
                for (int c = 0; c < grid[0].size();c++)
                {
                    cout << grid[r][c] << " ";
                    if (grid[r][c] == '1')
                    {
                         mmax = max(mmax, dfs(grid,r,c));
                        //result += dfs(grid,r,c);
                    }
                }
                cout << endl;
            }

        
            return mmax;
        }

};

int main()
{
    Solution sol;

    vector<vector<char>> input = {
                                {'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}
                                };

     input = {
                                {'1','1','1','1','0'},
                                {'1','1','0','0','0'},
                                {'1','0','1','0','0'},
                                {'0','0','0','1','1'}
                                };

    int res = sol.numIslands(input);
    cout << "nun islands: " << res << endl;

    vector<vector<char>> bs = {
                                {'X','.','.','X'},
                                {'.','.','.','X'},
                                {'.','.','.','X'}
                                };
    bs =                    {
                                {'X','.','X'},
                                };

    bs =                    {
                                {'.','X'},
                                {'X','.'}
                                };
   cout << "nun battleships: " <<  sol.countBattleships(bs) << endl;

}