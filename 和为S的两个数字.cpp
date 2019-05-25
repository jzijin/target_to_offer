class Solution
{
public:
    // 常规思路
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> target;
        for (int i = 0; i < array.size(); ++i)
        {
            for (int j = array.size() - 1; j >= i + 1; --j)
            {
                if (array[i] + array[j] == sum)
                {
                    target.push_back(array[i]);
                    target.push_back(array[j]);
                    return target;
                }
            }
        }
        return target;
    }
};

// 简化思路
class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> target;
        int i = 0;
        int j = array.size() - 1;
        while (i < j)
        {

            if (array[i] + array[j] == sum)
            {
                target.push_back(array[i]);
                target.push_back(array[j]);
                break;
            }
            while (i < j && array[i] + array[j] > sum)
                --j;
            while (i < j && array[i] + array[j] < sum)
                ++i;
        }
        return target;
    }
};