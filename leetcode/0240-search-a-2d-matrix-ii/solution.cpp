#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        // 从右上角出发：左边更小，下边更大
        int x = 0, y = n - 1;

        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;   // 太大，往左走（这一列下面只会更大）
            } else {
                ++x;   // 太小，往下走（这一行左边只会更小）
            }
        }
        return false;
    }
};
