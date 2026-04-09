#include <iostream>
#include <string>
#include <array>
#include <algorithm>

class Solution 
{
public:
    int characterReplacement(std::string s, int k)
    {
        int maxLength {0};

        int n {static_cast<int>(s.size())};

        int maxFreq {0};
        std::array<int,26> freq {0};
        
        int l {0};
        for (int r {0}; r < n; r++)
        {
            freq[s[r] - 'A']++;
            maxFreq = std::max(maxFreq, freq[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLength = std::max(maxLength, r - l + 1);
        }
        
        return maxLength;
              
    }
};

int main()
{
    Solution sol {};

    std::string s {"AABABBA"};
    int k {2};

    std::cout << sol.characterReplacement(s,k) << '\n';

    return 0;
}

// Maybe sliding window + hashtable
// As sliding save how much of each letter is seen
// But this would require checking every letter at each idx
//
// Need some way to track majority element within window
// Do you just +1 see it, -1 anything else
// I thought this just gave majority candidate
// Maybe that is when majority means > n/2
// But say we have AABCD, would see D as majority by end
//
// Back to first idea of using hashtable, would only need to know number of max freq
// No need to check every single one to see if it is bigger, can just store elsewhere num
// since letter that freq belongs to doesn't matter
// Then use windowSize - maxFreq to get k
// Will have to shrink window if bigger than k
//
// Actually might need letter tied to maxFreq so it can be decreased
// Adds quite a few issues lol
//
// Wait might never need to decrease, since maxFreq determines what max windowSize can be
// So when we get our max freq, will also be getting our max windowSize around it
//
// Not entirely convinced there is no edge case, but will give it a go
