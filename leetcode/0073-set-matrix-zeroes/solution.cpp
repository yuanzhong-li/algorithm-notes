#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        // 第一行 / 第一列自己会不会被置零（单独记，避免互相覆盖）
        bool firstRowZero = false;
        bool firstColZero = false;

        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) firstRowZero = true;
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) firstColZero = true;
        }

        // 用第一行、第一列当「标记」：matrix[i][0]/matrix[0][j] = 0 表示该行/列要清零
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 根据标记，把对应行、列置零（先处理非第一行/列）
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 最后处理第一行、第一列
        if (firstRowZero) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if (firstColZero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
