#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int mostBooked(int n, std::vector<std::vector<int>>& meetings) {
        
        int result {0};

        std::sort(meetings.begin(), meetings.end()); // might not be neccessary



        return result;
    }
};

int main() {
    
    Solution sol {};

    int n_1 {2};
    std::vector<std::vector<int>> meetings_1 {
        {0,10},{1,5},{2,7},{3,4}
    };
    
    std::cout << sol.mostBooked(n_1, meetings_1);
    return 0; 
} 
// put meetings in lowest number room
// delay (giving queue) 
// return room with most meetings 
//
// seems easy to brute force? 
// so must be hard due to effeciency 
// note that each start time is unique so definite order
//
// First idea is to have a vector that represents each room and store when
// that room becomes available
// Want to change lowest value end time with newest
// - Since this will be the first to accept the new meeting
// Use min heap?
// Need to deal with ties however, if tie use lower value room
// Or do I use a queue? (not a queue, a sorted array)
// 
// Problem with array is that inserting is O(n)
// Try and do min heap 
// 
//
