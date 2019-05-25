class Solution
{
public: // TODO: 尝试可以用二分来解决
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0)
            return 0;
        int i;
        for (i = 0; i < rotateArray.size() - 1; ++i)
        {
            if (rotateArray[i + 1] < rotateArray[i])
                break;
        }
        return rotateArray[i + 1];
    }
};