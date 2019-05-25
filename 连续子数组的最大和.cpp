class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int num=0;
        int max_num = 0x80000000; // int最小值
        for(auto i : array)
        {
            num += i;
            max_num = num > max_num ? num : max_num;
            num = num < 0 ? 0 : num;
        }
        return max_num;
    }
};