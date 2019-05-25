class Solution
{
public: // TODO: understand it
    vector<string> Permutation(string str)
    {
        vector<string> res;
        int n = str.length();
        if (n == 0)
        {
            return res;
        }
        sort(str.begin(), str.end());
        vector<bool> visited(n, false);
        string res_str = "";
        dfs_helper(res, str, res_str, visited);
        return res;
    }

    void dfs_helper(vector<string> &res, string &str, string &res_str, vector<bool> &visited)
    {
        if (res_str.length() == str.length())
        {
            res.push_back(res_str);
            return;
        }
        for (int i = 0; i < str.length(); ++i)
        {
            if (visited[i])
            {
                continue;
            }
            if (i != 0 && !visited[i - 1] && str[i] == str[i - 1])
            {
                continue;
            }
            visited[i] = true;
            res_str.push_back(str[i]);
            dfs_helper(res, str, res_str, visited);
            res_str.pop_back();
            visited[i] = false;
        }
    }
};