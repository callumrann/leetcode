#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int minDominoRotations(std::vector<int>& tops, std::vector<int>& bottoms) {

        int res = -1;
        
        const int face_count {7};
        int unique_counts[face_count] {};
        
        int dom_count {static_cast<int>(tops.size())};
        for (int i {0}; i < dom_count; i++) {
            unique_counts[tops[i]]++;
            if (tops[i] != bottoms[i])
                unique_counts[bottoms[i]]++;
        }
        
        for (int i {1}; i < face_count; i++) {
            if (unique_counts[i] < dom_count) {
                continue;
            }
            
            int top_needed {0};
            int bot_needed {0};
            bool possible = true;

            for (int j {0}; j < dom_count; j++) {

                if (tops[j] != i && bottoms[j] != i) {
                    possible = false;
                    break;
                }

                if (tops[j] != i)
                    top_needed++;
                if (bottoms[j] != i)
                    bot_needed++;
            }

            if (possible)
                res = top_needed < bot_needed ? top_needed : bot_needed;

        }

        return res;
    }

};

// note that [] conversions are fine as all > 0
// idea of single return point + using INT_MAX from solutions

int main() {

    Solution sol {};
    
    std::vector<int> tops_1 = {1,2,1};
    std::vector<int> bots_1 = {4,4,4};

    int res = sol.minDominoRotations(tops_1, bots_1);
    std::cout << res << '\n';

    return 0;
}

// need to watch out for multiple possibilities?
// - not necessary
// number that we go for will be greater than or equal to half of tops or bots
// if half may need to test both numbers
// keep track of sums of all numbers bot and tops
// if sum of number = .size() then pick smaller count as answer
//
// what if more of a num then needed
// should actually pick .size() - larger count as answer
//
// issue with approach, if add, counting double occurances (on same domino)
// so might not be possible
// add a unique counts map
//
// watch for type conversions between signed and unsigned
//
// got code working (see leetcode submission), but was slow
// will use arrays instead of maps, and find possible result first before getting flips
// also limit return spots for clarity
