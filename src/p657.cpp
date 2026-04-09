#include <string>
#include <array>

class Solution 
{
public:
    bool judgeCircle(std::string moves)
    {
        std::array<int,2> stacks {{0,0}};

        for (size_t i {0}; i < moves.size(); i++)
        {
            switch (moves[i])
            {
            case 'L':
                stacks[0]--;
                break;
            case 'R':
                stacks[0]++;
                break;
            case 'D':
                stacks[1]--;
                break;
            case 'U':
                stacks[1]++;
                break;
            }            
        }

        return !(stacks[0] | stacks[1]);
    }
};
