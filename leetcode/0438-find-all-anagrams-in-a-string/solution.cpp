#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = (int)s.size(), m = (int)p.size();
        if (n < m) return ans;

        // 统计 p 和当前窗口的字母出现次数（只含小写字母）
        vector<int> need(26, 0), window(26, 0);
        for (char c : p) ++need[c - 'a'];

        // 固定长度窗口：长度为 m
        for (int right = 0; right < n; ++right) {
            ++window[s[right] - 'a'];           // 右端进入
            if (right >= m) {
                --window[s[right - m] - 'a'];   // 左端离开（保持窗口长度 = m）
            }
            // 窗口已满，且字母计数与 p 完全相同 → 是异位词
            if (right >= m - 1 && window == need) {
                ans.push_back(right - m + 1);
            }
        }
        return ans;
    }
};
