class Solution
{
    stack<int> mystack;
    priority_queue<int, vector<int>, greater<int>> mypq;

  public:
    void push(int value)
    {
        mystack.push(value);
        mypq.push(value);
    }
    void pop()
    {
        if (mypq.top() == mystack.top())
            mypq.pop();
        mystack.pop();
    }
    int top()
    {
        return mystack.top();
    }
    int min()
    {
        return mypq.top();
    }
};

// 辅助栈的方法
class Solution
{
    stack<int> mystack;
    stack<int> exter;

  public:
    void push(int value)
    {
        mystack.push(value);
        if (exter.empty())
            exter.push(value);
        else if (value <= exter.top())
            exter.push(value);
    }
    void pop()
    {
        if (mystack.top() == exter.top())
            exter.pop();
        mystack.pop();
    }
    int top()
    {
        return mystack.top();
    }
    int min()
    {
        return exter.top();
    }
};