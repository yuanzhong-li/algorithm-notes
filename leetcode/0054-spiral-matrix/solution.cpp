#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;

        int top = 0;
        int bottom = (int)matrix.size() - 1;
        int left = 0;
        int right = (int)matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 上边：左 → 右
            for (int j = left; j <= right; ++j) {
                ans.push_back(matrix[top][j]);
            }
            ++top;

            // 右边：上 → 下
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            --right;

            // 下边：右 → 左（还剩行时才走）
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    ans.push_back(matrix[bottom][j]);
                }
                --bottom;
            }

            // 左边：下 → 上（还剩列时才走）
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return ans;
    }
};
