#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int maxProductPath(std::vector<std::vector<int>>& grid)
    {
        int m = {(int)grid.size()};
        int n = {(int)grid[0].size()};

        std::vector<std::vector<long long>> maxDP(m,std::vector<long long>(n));
        std::vector<std::vector<long long>> minDP(m,std::vector<long long>(n));
        
        maxDP[0][0] = minDP[0][0] = grid[0][0];

        // Fill first col
        for (int i {1}; i < m; i++)
        {
            maxDP[i][0] = minDP[i][0] = maxDP[i-1][0] * grid[i][0];
        }

        // Fill first row
        for (int i {1}; i < n; i++)
        {
            maxDP[0][i] = minDP[0][i] = maxDP[0][i-1] * grid[0][i];
        }

        for (int i {1}; i < m; i++)
        {
            for (int j {1}; j < n; j++)
            {
                long long val = grid[i][j];
        
                long long topMax = maxDP[i-1][j] * val;
                long long topMin = minDP[i-1][j] * val;
                
                long long leftMax = maxDP[i][j-1] * val;
                long long leftMin = minDP[i][j-1] * val;

                maxDP[i][j] = std::max({topMax,topMin,leftMax,leftMin});
                minDP[i][j] = std::min({topMax,topMin,leftMax,leftMin});
            }
        }

        printDP(grid);
        printDP(maxDP);
        printDP(minDP);
        
        long long result {maxDP[m-1][n-1]};

        if (result < 0)
            return -1;

        return result % 1'000'000'007LL;
    }

private:
    template <typename T>
    void printDP(const std::vector<std::vector<T>>& dp)
    {
        std::cout << "---------\n";
        for (std::size_t i {0}; i < dp.size(); i++)
        {
            for (std::size_t j {0}; j < dp[0].size(); j++)
            {
                std::cout << dp[i][j] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "---------\n";
    }
};

int main()
{
    Solution sol {};

    std::vector<std::vector<int>> grid_1{
        {-1,-2,-3},
        {-2,-3,-3},
        {-3,-3,-2}
    };

    std::cout << sol.maxProductPath(grid_1) << '\n';

    return 0;
}

// Can only move right and down
// Issue is that there is no way to know best choice at that moment
// Recurse from end to start, and take largest pos and smallest number up to that point
