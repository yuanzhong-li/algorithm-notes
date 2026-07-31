#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 按区间起点从小到大排序
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < (int)intervals.size(); ++i) {
            // ans.back() 是当前已经合并好的「最后一段」
            if (intervals[i][0] <= ans.back()[1]) {
                // 有重叠：把右端点拉到更远的那边
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // 没重叠：作为新区间加入
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
