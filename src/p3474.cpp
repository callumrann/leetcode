#include <iostream>
#include <string>

class Solution {
public:
    std::string generateString(std::string str1, std::string str2)
    {
        int n {static_cast<int>(str1.size())};
        int m {static_cast<int>(str2.size())};

        std::string word(n + m - 1, '?');
        
        // Fill in T spots
        for (int i {0}; i < n; i++)
        {
            if (str1[i] == 'F')
                continue;

            for (int j {0}; j < m; j++)
            {
                if (word[i + j] != '?' && word[i + j] != str2[j])
                    return "";

                word[i + j] = str2[j];
            }
        }
        

        // Fill F spots (using fact can only be a or b
        std::string oldWord {word};
        for (char& c : word)
        {
            if (c == '?')
                c = 'a';
        }
        
        // Check F
        for (int i {0} ; i < n; i++)
        {
            if (str1[i] == 'T')
                continue;

            bool match {true};
            for (int j {0}; j < m; j++)
            {
               if (word[i + j] != str2[j])
               {
                   match = false;
                   break;
               }
            }

            if (!match)
                continue;

            for (int j {i + m - 1}; j >= i; j--)
            {
                if (oldWord[j] == '?')
                {
                    word[j] = 'b';
                    match = false;
                    break;
                }
            }

            if (match)
                return "";
        }

        return word;
    }
};

int main()
{
    Solution sol {};

    std::string str1_1 {"TFTF"};
    std::string str2_1 {"ab"};
    
    std::string str1_2 {"FFTFFF"};
    std::string str2_2 {"a"};

    std::cout << sol.generateString(str1_1, str2_1) << '\n';
    std::cout << sol.generateString(str1_2, str2_2) << '\n';


    return 0;
}

// Needs to lexicographically smalles, so prioritise a -> z
// If str1[i] = T we are forced to make the next str2.size() picks
// Hard part comes with F's
// For a brute force approach, could put in all forced characters, then 
// go back and fill empty spots with smalled lexo possible letters
// For each empty would need to check str2.size() characters
//
// Left to right or right to left for F checks
// Lexicographically means we want left to be smaller than right e.g. ab vs ba
// So then go through left to right
//
// What to check though
// If str2 is all one letter, then each empty must be different, and F can't be wedged
// between two T's (based on length of str2)
// If str2 has one letter different, then all empty's can be made a, and F's can be
// anywhere
//
// Not true, if str2 repeats itself, could end up in scenario where F is placed
// in a spot such that is crosses two T's
//
// Important to note that each empty can be filled with a or b
// No way both can fulfil str2
//
// Feel like current solution could have an edge case where changing a letter impacts
// previously fixed F spot
//
// Let a_1a_2...a_n be the string (where a_i can be any letter)
// We change some a_k (which has to be a to be changeable) to b
// Then I guess for contradiction possibility, we let this b ruin a previous
//
// The b will appear later in this previous string, and was at first a
// aabaabaab with TFFTFFT (moving to counter example xd)
// aaaaaaaaa
//
// Man idk, just run it
//
// K it works, will think of rigorous reason why later
// Probably something like, can only change a's to b's
// Since a/b is absolutely not in string at that position from first F perspective
// Any changes to later a's to b's will not change this
//
// Okay but what if a is not, but b is...
