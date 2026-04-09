#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {

        int min_deletion {0}; 

        return min_deletion;
    }
};

int main() {
    
    Solution sol {};

    std::vector<std::string> s_1 {"babca","bbazb"};

    std::cout << sol.minDeletionSize(s_1) << '\n';

    return 0;
}

// deleting cols to get rows in order
// hard since can no longer be greedy i believe
// wait maybe can, if we have eaf, deleting either a or e will both work
// but will have to check lower to see which is better
// in that case need to only make moves we are certain will be in final
// what case is one better than the other however?
// afc, fac - will need to do second
// dae, fac - both work
// is there a case where we want to delete the first
// yes, fac, fac - second bad
// 
// Focus on just one row for now
// I guess want to save all combinations of deletions
// Maybe just optimal?
