class Solution {
public:
    int jumpFloorII(int number) {
        if(number<=0)
            return 0;
        // 主要是找规律得到最优解
        
        return 1<<(number-1);
    }
};