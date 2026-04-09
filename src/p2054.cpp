#include <vector>
#include <iostream>

class Solution {
public:
    int maxTwoEvents(std::vector<std::vector<int>>& events) {
       
        int result {0};

        std::sort(events.begin(), events.end()); // sorts by first, then second, etc
        
        // below works as events.size() > 0
        int max_choice[events.size()];
        for (std::size_t i = events.size() - 1; i >= 0; i--) {
            max_choice[i] = 



        return result;
    }
};

int main() {

    Solution sol {};

    std::vector<std::vector<int>> events_1 = {
        {1, 3, 2},
        {4, 5, 2},
        {2, 4, 3}
    };

    std::cout << sol.maxTwoEvents(events_1) << '\n';

    return 0;
}

// already done once in C, will do again without looking
// kinda forget
//
// sort by time
// now can check every combination
// binary search to next possible start time
// feel like there is some effecient way to do this
// 
// looked at previous submission, since was kinda stuck
// forgot about prefix sums
// if we want to be able to access some info from that point on 
// think prefix (or i guess suffix sum)
// essentially want to store what the max from that point onwards is
// this way we can immediately check best outcome
// 
// is there a better way to pick best first number though
// what if sorted by end times - ruins max store
// doesn't seem like it, still have to check all
