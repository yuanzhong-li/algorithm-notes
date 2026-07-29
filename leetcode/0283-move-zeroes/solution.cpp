#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // slow: 下一个非零元素应该放的位置
        int slow = 0;
        for (int fast = 0; fast < (int)nums.size(); ++fast) {
            if (nums[fast] != 0) {
                // 把非零元素挪到前面，原来的位置先不管
                // 若 slow == fast，自己和自己交换，没影响
                swap(nums[slow], nums[fast]);
                ++slow;
            }
        }
        // 循环结束后：前 slow 个是原相对顺序的非零，后面全是 0
    }
};
