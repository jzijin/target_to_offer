class Solution {
public:
    // 三指针法解决这个问题 和 leetcode 的题目是类似的
    int get_min(int a, int b, int c)
    {
        if(a < b)
        {
            return a < c ? a : c;
        }
        else 
        {
            return b < c ? b : c;
        }
    }
    int GetUglyNumber_Solution(int index) {
        int* res = new int[index];
        int index2 = 0, index3=0, index5 = 0;
        res[0] = 1;
        for(int i=1; i<index; ++i)
        {
            res[i] = get_min(res[index2]*2, res[index3]*3, res[index5]*5);
            if(res[i] == res[index2]*2)
                ++index2;
            if(res[i] == res[index3]*3)
                ++index3;
            if(res[i] == res[index5]*5)
                ++index5;
        }
        return res[index-1];
    }
};