#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (left < right) {
            // 哪边矮，哪边就是瓶颈：矮的一侧能确定当前位置能接多少水
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];  // 更新左侧最高，这里接不了水
                } else {
                    ans += leftMax - height[left];
                }
                ++left;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    ans += rightMax - height[right];
                }
                --right;
            }
        }
        return ans;
    }
};
