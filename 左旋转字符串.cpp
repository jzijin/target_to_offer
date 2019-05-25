// YX = (XTY T)T

class Solution {
public:
    string LeftRotateString(string str, int n) 
    {
      int len = str.size();
        if(len == 0) return str;
        n %= len;
        for(int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = n, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = 0, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        return str;
    }
};


class Solution {
public:
    string LeftRotateString(string str, int n) {
        int i=0;
        while(i<n)
        {
            str += str[i];
            ++i;
        }
        string target(str.begin() + i, str.end());
        return target;
    }
};