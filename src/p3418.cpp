#include <iostream>
#include <vector>
#include <climits>

class Solution
{
public:
    int maximumAmount(std::vector<std::vector<int>>& coins)
    {
        const int rows {static_cast<int>(coins.size())};
        const int cols {static_cast<int>(coins[0].size())};
        const int neutraliseOptions {3};

        std::vector<int> dp(rows * cols * neutraliseOptions, INT_MIN);

        dp[0] = coins[0][0];
        
        for (int i {0}; i < rows; i++)
        {
            for (int j {0}; j < cols; j++)
            {
                // add robber thing for loop here probs
                // right check
                if (coins[i][j+1] < 0)
                {
                    //
                }
                int newRight {dp[(i*cols) + j] + coins[i][j+1]};

                if (dp[(i*cols) + (j+1)] < newRight)
                    dp[(i*cols) + (j+1)] = newRight;


    }
};

int main()
{
    Solution sol {};

    std::vector<std::vector<int>> coins_1 {
        {0,1,-1},
        {1,-2,3},
        {2,-3,4}
    };

    std::cout << sol.maximumAmount(coins_1) << '\n';

    return 0;
}

// Seems like a DP problem
// OPT(i,j) = best path to that cell
// Either come from left or the top
// So OPT(i,j) = max{OPT(i-1,j), OPT(i,j-1)}
// Base case: OPT(0,0) = whatever start square is

// But how to choose to neutralise robbers
// Introduce third dimension k

// Now have to think of bottom up method
// Work from (0,0) and update right and below squares
// If one is negative update k-1 table (will let k be steals left)
// Now just do this for each cell
//
// Apparently 1D implementation of the 3D array will be much faster
// This is due to both the cache, and the number of steps to access the variable
//
// Will do k = robbers neutralised for 1D approach
// Should be all k options for each cell next to each other to reduce jumps
