#include <iostream>
#include <string>

class Solution
{
public:
    std::string decodeCiphertext(std::string encodedText, int rows)
    {

        
    }
};


int main()
{
    Solution sol {};

    std::cout << sol.decodeCiphertext("ch   ie   pr", 3) << '\n';

    return 0;
}

// Seems to never read before starting diagonal (has to be spaces or fails test case it
// seems)
// size / rows = col size
//
