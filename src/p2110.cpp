#include <iostream>
#include <vector>

class Solution {
public:
    long long getDescentPeriods(std::vector<int>& prices) {
        std::size_t l = 0;
        std::size_t r = 1;
        long long smooth_descents {static_cast<long long>(prices.size())};

        while (r < prices.size()) {
            if (prices[r] == prices[r - 1] - 1) {
                smooth_descents += r - l;
                r++;
            }
            else {
                l = r;
                r++;
            }
        }

        return smooth_descents;
    }
};

int main() {
    
    Solution s{};

    std::vector<int> p1 {3,2,1,4};
    std::vector<int> p2 {8,6,7,7};
    std::vector<int> p3 {1};

    std::cout << s.getDescentPeriods(p1) << '\n';
    std::cout << s.getDescentPeriods(p2) << '\n';
    std::cout << s.getDescentPeriods(p3) << '\n';

    return 0;
}
