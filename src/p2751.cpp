#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Solution 
{
public:
    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, 
            std::vector<int>& healths, std::string directions)
    {
        int n {static_cast<int>(positions.size())};

        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int a, int b) {
                return positions[a] < positions[b];
        });

        std::vector<int> stack;
        stack.reserve(n);
        
        for (int i : idx)
        {
            if (directions[i] == 'R')
                stack.push_back(i);
            else
            {
                while (!stack.empty() && healths[i] > 0)
                {
                    int j {stack.back()};

                    if (healths[i] > healths[j])
                    {
                        healths[i] -= 1;
                        healths[j] = 0;
                        stack.pop_back();
                    }
                    else if (healths[i] < healths[j])
                    {
                        healths[j] -= 1;
                        healths[i] = 0;
                        // no need to check == 0, always > 1
                    }
                    else
                    {
                        healths[i] = 0;
                        healths[j] = 0;
                        stack.pop_back();
                    }
                }
            }
        }
        
        std::vector<int> remaining;
        for (int i {0}; i < n; i++)
        {
            if (healths[i] > 0)
                remaining.push_back(healths[i]);
        }
        return remaining;
    }
};

int main()
{
    Solution sol {};
    
    std::vector<int> position {{3,5,2,6}};
    std::vector<int> healths {{10,10,15,12}};
    std::string directions {{"RLRL"}};

    std::vector<int> res {sol.survivedRobotsHealths(position,healths,directions)};
    for (int x : res)
        std::cout << x << ' ';
    std::cout << '\n';

    return 0;
}

// Need to ensure that collisions occur in order
// Especially since robots lose 1 health after collision
// Need to simulate second by second?
// That has gotta be too slow
//
// Wait ngl, I forgot that robots all move at the same speed
// So collisions will only occur if move opposite directions
// So collision will occur exactly between robots in directions that go RL, that is
// after positions are sorted
//
// Sort then use stack, and pop off L when R and vice versa
// Process collision if R popped off by L, but no L by R
// If collision, adjust health, and push surviving direction
//
// e.g. for big L health -> RR -> RRL -> RL -> L
// - not a visual for the stack, but kinda the process
//
// Need to return remaining healths in order they were given
// Use idx array
//
// Actually no reason to add L's to the stack I think
// L either, sees no R's, dies before end, or makes past all R's
