class Solution
{
public:
    int StrToInt(string str)
    {
        int length = str.size();
        int num = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == '+' || str[i] == '-')
            {
                continue;
            }
            if (str[i] >= '0' && str[i] <= '9')
            {
                num += static_cast<int>(str[i] - '0') * pow(10, length - i - 1);
            }
            else
                return 0;
        }
        if (str[0] == '-')
            return -1 * num;
        return num;
    }
};