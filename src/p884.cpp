#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        string s = s1 + " " + s2;

        unordered_map<string, int> um;
        string tmp = "";
        for (auto& c : s) {
            if (c == ' ') {
                um[tmp]++;
                tmp = "";
            }
            else {
                tmp += c;
            }
        }

        if (tmp != "") {
            um[tmp]++;
            tmp = "";
        }

        vector<string> result {};
        for (auto& pair : um) {
            if (pair.second == 1) {
                result.emplace_back(pair.first);
            }
        }
        return result;
    }
};

void printResult(vector<string>& result) {
    for (auto& word : result) {
        cout << word << ' ';
    }
    cout << '\n';
}

int main() {
    
    Solution sol{};
    
    string s1_1 = "this apple is sweet";
    string s2_1 = "this apple is sour";

    vector<string> res = sol.uncommonFromSentences(s1_1, s2_1);
    printResult(res);    

    return 0;
}

// need to create map
// use map_type<type1, type2> name;
// map types include:
// map, ordered, undordered, multimap (can also be ordered vs unordered)
// multimap and map can have duplicate keys
// map is ordered
