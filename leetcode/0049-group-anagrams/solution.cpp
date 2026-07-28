#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key: 排序后的字符串（同一组异位词排序结果相同）
        // value: 属于这一组的所有原字符串
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // 例如 "eat" / "tea" / "ate" -> "aet"
            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& [key, group] : groups) {
            ans.push_back(group);
        }
        return ans;
    }
};
