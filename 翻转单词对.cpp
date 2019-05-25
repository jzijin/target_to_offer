class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str == " ")
        {
            return str;
        }
        stack<string> myStack;
        string target = "";
        string tmp = "";
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
            {
                if (tmp.size() > 0)
                    myStack.push(tmp);
                tmp = "";
                continue;
            }
            tmp += str[i];
        }
        if (tmp.size() > 0)
            myStack.push(tmp);
        while (!myStack.empty())
        {
            //cout << "top=" << myStack.top() << endl;
            target += myStack.top();
            target += " ";
            myStack.pop();
        }
        // 删除最后一个空格
        target.pop_back();
        //str = target;
        return target;
    }
};

// 正确解法
class Solution
{
public:
    string ReverseSentence(string str)
    {

        string res = "", tmp = "";
        for (unsigned int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
                res = " " + tmp + res, tmp = "";
            else
                tmp += str[i];
        }
        if (tmp.size())
            res = tmp + res;
        return res;
    }
};