#include <iostream>
#include <string>
#include <array>

class Solution 
{
public:
    bool checkStrings(std::string s1, std::string s2) 
    {
        const int letters {26};

        int n {static_cast<int>(s1.size())};

        std::array<int,letters> evenHash;
        std::array<int,letters> oddHash;

        for (int i {0}; i < n; i++)
        {
            int s1Char {s1[i] - 'a'};
            int s2Char {s2[i] - 'a'};

            if (i % 2 == 0)
            {
                evenHash[s1Char]++;
                evenHash[s2Char]--;
            }
            else
            {
                oddHash[s1Char]++;
                oddHash[s2Char]--;
            }
        }

        for (int i {0}; i < letters; i++)
        {
            if (evenHash[i] != 0 || oddHash[i] != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol {};

    std::string s1 = "abcdbd";
    std::string s2 = "cabdab";

    std::cout << sol.checkStrings(s1,s2) << '\n';

    return 0;
}

// Want to check if even idx letter counts are the same for both strings
// Same for odd idx
