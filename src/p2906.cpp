#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> constructProductMatrix(
            std::vector<std::vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> products(n,std::vector<int>(m));

        // Forward pass
        long long runningProduct = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                products[i][j] = runningProduct;
                runningProduct = (runningProduct * grid[i][j]) % 12345;
            }
        }
        
        // Backward pass
        runningProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                products[i][j] = (products[i][j] * runningProduct) % 12345;
                runningProduct = (runningProduct * grid[i][j]) % 12345;
            }
        }
        return products;
    }
};

int main()
{
    return 0;
}

// Is it just get total, then divide by each one and store?
// Should be a medium problem so not sure
// Just watch for int overflow is all
//
// Multiplying up is fine with modulo, but think division doesn't work
// Another issue is if a 0 appears in one spot only
//
// Looked at solutions... need prefix + suffix product grids
// Actually just pass through twice, one forward, one back
