// TODO: 这他娘的也太强了吧， 还能用动态规划
/*
链接：https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c
来源：牛客网

动态规划
如果 pattern[j] == str[i] || pattern[j] == '.', 此时dp[i][j] = dp[i-1][j-1];
如果 pattern[j] == '*'
    分两种情况:
    1: 如果pattern[j-1] != str[i] && pattern[j-1] != '.', 此时dp[i][j] = dp[i][j-2] //a*匹配0次
    2: 如果pattern[j-1] == str[i] || pattern[j-1] == '.'
        此时dp[i][j] = dp[i][j-2] // a*匹配0次
        或者 dp[i][j] = dp[i][j-1] // a*匹配1次
        或者 dp[i][j] = dp[i-1][j] // a*匹配多次
*/
class Solution
{
public:
    bool match(char *str, char *pattern)
    {
        vector<vector<int>> dp(strlen(str) + 1, vector<int>(strlen(pattern) + 1));
        dp[0][0] = true;
        for (int i = 1; i < dp[0].size(); ++i)
        {
            if (pattern[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 1; j < dp[0].size(); ++j)
            {
                if (pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                if (pattern[j - 1] == '*')
                {
                    if (pattern[j - 2] != str[i - 1] && pattern[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }
        return dp[strlen(str)][strlen(pattern)];
    }
};