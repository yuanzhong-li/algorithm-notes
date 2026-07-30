#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;  // 存下标；对应的值从大到小（队头最大）

        for (int i = 0; i < (int)nums.size(); ++i) {
            // 1. 队尾：比 nums[i] 小的都没用了，弹出（保持单调递减）
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // 2. 队头：下标已经滑出窗口左边界，弹出
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // 3. 窗口已形成（长度至少 k），队头就是当前最大值
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
