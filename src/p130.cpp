#include <iostream>
#include <vector>

#define FLAG '#'

class Solution 
{
public:
    void dfs(std::vector<std::vector<char>>& board, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;

        board[i][j] = FLAG;

        dfs(board, i - 1, j, m, n);
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i, j + 1, m, n);
    }

    void solve(std::vector<std::vector<char>>& board)
    {
        int m {static_cast<int>(board.size())};
        int n {static_cast<int>(board[0].size())};
        
        // top check
        for (int j {0}; j < n; j++)
        {
            dfs(board, 0, j, m, n);
        }
        
        // bottom check
        for (int j {0}; j < n; j++)
        {
            dfs(board, m - 1, j, m, n);
        }
        
        // left check
        for (int i {0}; i < m; i++)
        {
            dfs(board, i, 0, m, n);
        }
        
        // right check
        for (int i {0}; i < m; i++)
        {
            dfs(board, i, n - 1, m, n);
        }

        for (int i {0}; i < m; i++)
        {
            for (int j {0}; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == FLAG)
                    board[i][j] = 'O';
            }
        }
    }
};

int main()
{
    Solution sol {};

    std::vector<std::vector<char>> board {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    sol.solve(board);

    return 0;
}

// Union find question
// Haven't done union find in ages
// Something about join and union
// O must be on edge to be not surrounded
// K, even though got this question from union find problem set, seems like
// can just dfs from borders
