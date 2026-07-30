#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // key: 前缀和；value: 该前缀和出现过几次
        unordered_map<int, int> prefixCnt;
        prefixCnt[0] = 1;  // 空前缀和为 0，出现 1 次

        int sum = 0;
        int ans = 0;
        for (int x : nums) {
            sum += x;  // 当前前缀和：nums[0..i] 之和
            // 若存在前缀和 sum - k，说明中间那段子数组和为 k
            if (prefixCnt.count(sum - k)) {
                ans += prefixCnt[sum - k];
            }
            ++prefixCnt[sum];
        }
        return ans;
    }
};
