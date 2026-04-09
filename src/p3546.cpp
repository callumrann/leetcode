#include <vector>
#include <iostream>

class Solution
{
public:
    bool canPartitionGrid(std::vector<std::vector<int>>& grid)
    {
        int m {(int)grid.size()};
        int n {(int)grid[0].size()};

        std::vector<std::vector<long>> horiPrefix(m,std::vector<long>(n));
        std::vector<std::vector<long>> vertPrefix(m,std::vector<long>(n));
    
        // Horizontal Prefix
        long runningSum {0};
        for (int i {0}; i < m; i++)
        {
            for (int j {0}; j < n; j++)
            {
                runningSum += grid[i][j];
                horiPrefix[i][j] = runningSum;
            }
        }

        // Vertical Prefix
        runningSum = 0;
        for (int j {0}; j < n; j++)
        {
            for (int i {0}; i < m; i++)
            {
                runningSum += grid[i][j];
                vertPrefix[i][j] = runningSum;
            }
        }

        // Check cuts
        long totalSum {horiPrefix[m-1][n-1]};
        for (int i {0}; i < m - 1; i++)
        {
            if (horiPrefix[i][n-1] * 2 == totalSum)
                return true;
        }

        for (int i {0}; i < n - 1; i++)
        {
            if (vertPrefix[m-1][i] * 2 == totalSum)
                return true;
        }
        
        return false;
    }
};

int main()
{
    Solution sol {};
    std::vector<std::vector<int>> grid_1 {
        {54756, 54756}
    };
    std::cout << sol.canPartitionGrid(grid_1) << '\n';
    return 0;
}

// For horizontal cut, could have a prefix sum
// This would allow us to instantly know how much comes before and after the cut
// Could implement the same approach for vertical cuts as well
// Then check all possible cuts?
// All values in the grid are positive, so if first half > second half, stop checking that
// cut type
// Actually can just check if 2*partition sum = total sum
