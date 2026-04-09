#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution
{
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix)
    {
        int max {0};

        int rowCount {static_cast<int>(matrix.size())};
        int colCount {static_cast<int>(matrix[0].size())};

        std::vector<std::vector<int>> prefixMatrix(rowCount, 
                std::vector<int>(colCount));

        for (int y {0}; y < rowCount; y++)
        {
            int distToLeft {1};
            for (int x {0}; x < colCount; x++)
            {
                int& prefix {prefixMatrix[y][x]};
                prefix = matrix[y][x] - '0';

                if (prefix == 0)
                {
                    distToLeft = 1;
                    continue;
                }
                prefix = distToLeft++;
            }
        }

        printTable(prefixMatrix);

        for (int x {0}; x < colCount; x++)
            for (int y {0}; y < rowCount; y++)
            {
                int width {prefixMatrix[y][x]};

                if (width == 0)
                    continue;
                
                // expand downward
                int currWidth = width;
                for (int yOffset = y; yOffset < rowCount &&
                        prefixMatrix[yOffset][x] > 0; yOffset++)
                {
                    currWidth = std::min(currWidth, prefixMatrix[yOffset][x]);
                    int height = yOffset - y + 1;
                    max = std::max(max, currWidth * height);
                }

                // expand upward
                currWidth = width;
                for (int yOffset = y; yOffset >= 0 &&
                        prefixMatrix[yOffset][x] > 0; yOffset--)
                {
                    currWidth = std::min(currWidth, prefixMatrix[yOffset][x]);
                    int height = y - yOffset + 1;
                    max = std::max(max, currWidth * height);
                }
            }
        return max;        
    }

    void printTable(const std::vector<std::vector<int>>& matrix)
    {
        for (auto& row : matrix)
        {
            for (auto& c : row)
            {
                std::cout << c << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
};


int main()
{
    Solution sol {};

    std::vector<std::vector<char>> m_1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    std::cout << sol.maximalRectangle(m_1) << '\n';
}

// Considered a hard problem
// Most likely due to effeciency
// 
// Maybe create two new arrays, where each element is:
// - number of ones from itself downwards
// - number of ones from itself rightwards
// Might only need one
// Even creating the one is pretty expensive
// No point creating it then checking, instead check as going
// Check number down, if smaller or equal across reduce to it
// Else keep same
// Issue is, what if there is a bunch that are larger
// such that including the first is non effecient
// Don't want to have to recheck
// I feel like I have done a problem like this before
//
// Looked at topics
// One is monotonic stack
// Hints at idea of say 5,6,7,8,5
// When we hit the second 5, can check if those middle three amount to something greater
// If not then we can continue knowing we are checking the max
//
// This works great if only one row to check, but imagine repeating for all is
// ineffecient
//
// Looked at a solution. We were very close.
// Do the idea where we recreate the array with information based on how
// many ones are in some direction
// Then the monotonic stack comes in when going over this array
//
// My idea of doing this prefix array being ineffecient was wrong
// Having this fixes my issue of moving down a row and having to do it all agian
//
// Not really monotonic stack down...
// Still fine, just means another solution must exist
//
// Okay issue with current. Does not check if the cut off bit equals more.
// Maybe I divert from the solution given and try a monotonic stack
// Then check if cut off bits equate to more
//
// Might just do simpler approach, check every spot, expand up and down
// Don't have much time and a big issue for me is not finishing projects
//
// K finished, but in bottom 5%
