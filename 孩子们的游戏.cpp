class Solution {
public:
    // 用vector来添加元素，模拟约瑟夫环，其实还可以用数学的方法
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1)
            return -1;
        vector<int> target;
        for(int i=0; i<n; ++i)
            target.push_back(i);
        int last = -1;
        int start = 0;
        while(!target.empty())
        {
            int k = (start + m - 1) % n;
            last = target[k];
            target.erase(target.begin() + k);
            n -= 1;
            start = k;
        }
        return last;
        
    }
};
// 用数学方推出来的。
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        // invalid input
      if(n <= 0 || m < 0)
            return -1;

      // if there are only one integer in the circle initially,
      // of course the last remaining one is 0
      int lastinteger = 0;

      // find the last remaining one in the circle with n integers
      for (int i = 2; i <= n; i ++)
            lastinteger = (lastinteger + m) % i;

      return lastinteger;

    }
};
