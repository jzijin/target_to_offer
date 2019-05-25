class Solution
{
public:
    vector<int> data_stream;
    void Insert(int num)
    {
        data_stream.push_back(num);
    }

    double GetMedian()
    {
        // 需要排序 效率比较低
        sort(data_stream.begin(), data_stream.end());
        double res;
        int len = data_stream.size();
        if (len % 2 == 0)
        {
            double a = data_stream[len / 2];
            double b = data_stream[len / 2 - 1];
            res = (a + b) / 2;
        }
        else
        {
            res = data_stream[(len) / 2];
        }
        return res;
    }
};

// 这个解法用了两个优先队列避免了sort 效率可能会高一点

class Solution
{
    priority_queue<int, vector<int>, less<int>> p;
    priority_queue<int, vector<int>, greater<int>> q;

public:
    void Insert(int num)
    {
        if (p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);
        if (p.size() == q.size() + 2)
            q.push(p.top()), p.pop();
        if (p.size() + 1 == q.size())
            p.push(q.top()), q.pop();
    }
    double GetMedian()
    {
        return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};