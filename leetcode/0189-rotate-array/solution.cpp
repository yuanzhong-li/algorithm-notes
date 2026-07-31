#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;  // k 可能大于 n，转一圈等于没转
        if (k == 0) return;

        // 三次反转：整体 → 前 k 个 → 后面剩下的
        reverse(nums.begin(), nums.end());           // 全翻过来
        reverse(nums.begin(), nums.begin() + k);     // 前 k 个翻回来
        reverse(nums.begin() + k, nums.end());       // 后面再翻回来
    }
};
