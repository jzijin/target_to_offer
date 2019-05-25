class Solution {
public:
    int rectCover(int target) {
        // 本质上还是找规律 发现原来还是斐波那契数列
 if (target < 1) {
            return 0;
        } else if (target == 1 || target == 2) {
            return target;
        } else {
            return rectCover(target-1) + rectCover(target-2);
        }
    }
};