class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> target;
        if (k > input.size())
            return target;
        sort(input.begin(), input.end());
        vector<int> tmp(input.begin(), input.begin() + k);
        target = tmp;
        return target;
    }
};