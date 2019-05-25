class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        // 普通思路
        vector<vector<int>> target; // 返回有多少个符合的
        int init = 0;
        int sum_temp = 0;
        for (int i = 1; i <= sum / 2 + 1; ++i)
        {
            int j = i;
            vector<int> tmp;
            while (1)
            {
                tmp.push_back(j);
                sum_temp = accumulate(tmp.begin(), tmp.end(), init); // 对vector进行求和
                if (sum_temp == sum)
                {
                    if (tmp.size() >= 2)
                        target.push_back(tmp);
                    break;
                }
                else if (sum_temp > sum)
                    break;
                ++j;
            }
        }
        return target;
    }
};

// 用滑动窗口的思路去实现
class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> target; // 返回有多少个符合的
        int plow = 1, phigh = 2;
        while (phigh > plow)
        {
            int cur = (plow + phigh) * (phigh - plow + 1) / 2;
            if (cur == sum)
            {
                vector<int> tmp;
                for (auto i = plow; i <= phigh; ++i)
                    tmp.push_back(i);
                target.push_back(tmp);
                plow++;
            }
            else if (cur < sum)
            {
                phigh++;
            }
            else
            {
                plow++;
            }
        }
        return target;
    }
};