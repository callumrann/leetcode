#include <iostream>
#include <vector>
#include <string>

class Solution 
{
public:
    std::vector<int> numberOfLines(std::vector<int>& widths, std::string s)
    {
        int pixelCount {0};
        int lineCount {1};

        for (size_t i {0}; i < s.size(); i++)
        {
            int width = widths[s[i] - 'a'];
            
            if (pixelCount + width <= 100)
            {
                pixelCount += width;
            }
            else
            {
                pixelCount = width;
                lineCount++;
            }
        }

        std::vector<int> result {lineCount,pixelCount};
        return result;
    }
};

int main()
{
    Solution sol {};

    std::vector<int> widths {
        4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
    };
    std::string s {"bbbcccdddaaa"};

    std::vector<int> res {sol.numberOfLines(widths,s)};

    std::cout << "lines: " << res[0] << ", pixels: " << res[1] << '\n';

    return 0;
}

// Can greedy do each 100
// Width vector is always 26 size
// Just use s[i] - 'A' as idx
