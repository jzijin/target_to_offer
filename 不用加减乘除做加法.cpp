class Solution {
public:
    int Add(int num1, int num2)
    {
        if(num2 == 0)
            return num1;
        int total = num1 ^ num2;
        int carry = (uint)(num1 & num2)<<1;
        return Add(total, carry);
    }
};
