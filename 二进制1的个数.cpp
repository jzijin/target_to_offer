class Solution {
public:
     int  NumberOf1(int n) {
         // 一行解法
         return bitset<32>(n).count();
     }
};

class Solution {
        int NumberOf1(int n) {
            int count = 0;
            while(n!= 0){
                count++;
                n = n & (n - 1);
            }
            return count;
    }
}