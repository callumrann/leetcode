#include <vector>

class Solution
{
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix)
    {
        for (int diagsChecked {0}; diagsChecked < 
                matrix.size() + matrix[0].size() - 1; diagsChecked++)
        {
            int startRow {static_cast<int>(matrix.size()) - diagsChecked - 1};
            int startCol {0};

            if (startRow < 0)
            {
                startCol = -startRow;
                startRow = 0;
            }
            
            int prev {matrix[startRow][startCol]};
            for (int row {startRow+1}, col {startCol+1};
                    row < matrix.size() && col < matrix[0].size(); row++, col++)
            {
                if (matrix[row][col] != prev)
                    return false;
            }
        }
        return true;
    }
};

int main
{
    Solution sol {};

}

// start bottom left?
