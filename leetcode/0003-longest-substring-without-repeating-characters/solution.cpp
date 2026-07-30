#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;  // 当前窗口里出现过的字符
        int left = 0;
        int ans = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            // 右端字符已在窗口里：不断收缩左端，直到窗口无重复
            while (window.count(s[right])) {
                window.erase(s[left]);
                ++left;
            }
            window.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
