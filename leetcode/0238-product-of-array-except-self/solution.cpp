#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans(n, 1);

        // 第一遍从左到右：ans[i] 先放「左边所有数的乘积」
        int left = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = left;
            left *= nums[i];
        }

        // 第二遍从右到左：再乘上「右边所有数的乘积」
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};
