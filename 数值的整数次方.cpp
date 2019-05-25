class Solution {
public:
    // 主要考的是快速幂次 快速求幂
    double Power(double base, int exponent) {
        double res = 1, curr = base;
        int n;
        if(exponent > 0)
        {
            n = exponent;
        }
        else if(exponent < 0)
        {
            if(base == 0)
            {
                return 0.0;
            }
            n = -exponent;
        }
        else{
            return 1;
        }
        while (n != 0)
        {
            if((n&1)==1)
            {
                res *= curr;
            }
            curr *= curr;
            n >>= 1;
        }
        return exponent>=0?res:(1/res);
    }
};