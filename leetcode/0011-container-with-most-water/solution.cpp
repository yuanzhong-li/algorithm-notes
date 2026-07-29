#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int ans = 0;

        while (left < right) {
            // 面积 = 宽度 * 较短那根柱子的高度
            int h = min(height[left], height[right]);
            ans = max(ans, h * (right - left));

            // 移动较矮的一侧：只有它变高，面积才可能变大
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};
