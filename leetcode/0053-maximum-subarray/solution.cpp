#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // cur: 以当前元素结尾的最大子数组和
        // ans: 全局最大子数组和
        int cur = nums[0];
        int ans = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i) {
            // 要么接在前面那段后面，要么从自己重新开始
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};
