#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());  // 去重 + 快速判断某个数在不在
        int best = 0;

        for (int x : s) {
            // 只从「一段的起点」开始数：没有 x-1，说明 x 是起点
            if (s.count(x - 1)) {
                continue;
            }

            int cur = x;
            int len = 1;
            while (s.count(cur + 1)) {
                ++cur;
                ++len;
            }
            best = max(best, len);
        }
        return best;
    }
};
