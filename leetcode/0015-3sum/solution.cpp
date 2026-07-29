#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();

        for (int i = 0; i < n; ++i) {
            // 第一个数已经 > 0，后面全是正数，不可能凑成 0
            if (nums[i] > 0) break;
            // 跳过重复的第一个数，避免重复三元组
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    // 跳过重复的左右指针值
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                } else if (sum < 0) {
                    ++left;   // 太小，左指针右移增大
                } else {
                    --right;  // 太大，右指针左移减小
                }
            }
        }
        return ans;
    }
};
