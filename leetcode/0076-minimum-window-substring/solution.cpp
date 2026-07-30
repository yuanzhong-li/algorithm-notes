#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need;   // t 里每个字符需要几个
        for (char c : t) ++need[c];
        int needKinds = (int)need.size(); // 还要凑齐几种字符

        unordered_map<char, int> window;
        int valid = 0;  // 窗口里已经凑齐的字符种类数

        int left = 0;
        int start = 0;           // 最短覆盖子串的起点
        int minLen = INT_MAX;    // 最短长度

        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            // 只关心 t 里出现过的字符
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) ++valid;  // 这一种刚好凑齐
            }

            // 窗口已覆盖 t：尝试收缩左端，找更短的
            while (valid == needKinds) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left];
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;  // 这一挪就不够了
                    --window[d];
                }
                ++left;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
