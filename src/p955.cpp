#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
    int minDeletionSize(std::vector<std::string>& strs) {

        int deleted_cols {0};
        
        const std::size_t col_count {strs[0].size()};
        const std::size_t str_count {strs.size()};
        
        std::vector<bool> perfect_lexo(str_count);
        int perfect_count {0};

        for(std::size_t col {0}; col < col_count; col++) {

            bool delete_col {0};

            for(std::size_t str_idx {0}; str_idx < str_count - 1; str_idx++) {
                if(perfect_lexo[str_idx] == 0 && 
                        strs[str_idx][col] > strs[str_idx + 1][col]) {
                    delete_col = 1;
                    break;
                }
            }

            if(delete_col) {
                deleted_cols++;
                continue;
            }


            for(std::size_t str_idx {0}; str_idx < str_count - 1; str_idx++) {
                if(strs[str_idx][col] < strs[str_idx + 1][col]) {
                    perfect_lexo[str_idx] = 1;
                }
            }

            if(perfect_count == static_cast<int>(str_count)) {
                break;
            }
        }

        return deleted_cols;        

    }
};

int main() {
    
    Solution sol {};

    std::vector<std::string> s_1 {"ca","bb","ac"};
    std::vector<std::string> s_2 {"abx","agz","bgc","bfc"};
    std::vector<std::string> s_3 {"vdy","vei","zvc","zld"};

    std::cout << sol.minDeletionSize(s_1) << '\n';    
    std::cout << sol.minDeletionSize(s_2) << '\n';    
    std::cout << sol.minDeletionSize(s_3) << '\n';    

    return 0;
}

// very similar to problem yesterday
// lexo means word comes before other in dictionary?
// so go col by col left to right
// if first col is lexo by < not <=, then done
// can remove rows that are considered complete
//
// will call it perfect lexo if < relation between the two
// if we have idx 0 < 1 <= 2 we will say 0 has a perfect lexo and no longer needs
// to be considered
