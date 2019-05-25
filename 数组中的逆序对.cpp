class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        // 本质上是归并排序 需要复习一下归并排序
        if (data.size() == 0)
            return 0;
        vector<int> copy(data.begin(), data.end());
        int count = InversePairsSort(data, copy, 0, data.size() - 1);
        return count;
    }
    long long InversePairsSort(vector<int> &data, vector<int> &copy, int start, int end)
    {
        if (start == end)
        {
            return 0;
        }
        int mid = start + (end - start) / 2;
        long long left = InversePairsSort(data, copy, start, mid) % 1000000007;
        long long right = InversePairsSort(data, copy, mid + 1, end) % 1000000007;
        int count = 0;
        int i = mid, j = end, locCopy = end;
        while (i >= start && j > mid)
        {
            if (data[i] > data[j])
            {
                count += j - mid;
                copy[locCopy--] = data[i--];

                if (count >= 1000000007) //数值过大求余
                {
                    count %= 1000000007;
                }
            }
            else
            {
                copy[locCopy--] = data[j--];
            }
        }

        for (; i >= start; i--)
        {
            copy[locCopy--] = data[i];
        }
        for (; j > mid; j--)
        {
            copy[locCopy--] = data[j];
        }

        for (int s = start; s <= end; s++)
        {
            data[s] = copy[s];
        }
        return (left + right + count) % 1000000007;
    }
};