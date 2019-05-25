// 普通方法
class Solution
{
public:
    int get_max(vector<int> &tmp)
    {
        int max = tmp[0];
        for (auto i : tmp)
        {
            max = i > max ? i : max;
        }
        return max;
    }
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {

        vector<int> res;
        if (num.size() < size)
            return res;
        if (size == 0)
            return res;
        vector<int> tmp(num.begin(), num.begin() + size);
        int max_num = get_max(tmp);
        res.push_back(max_num);
        int index = 0;

        for (int i = size; i < num.size(); ++i)
        {
            index %= size;
            // 最大值被移除或者比当前最大值还大的值移入
            if (tmp[index] == max_num || num[i] > max_num)
            {
                tmp[index] = num[i];
                max_num = get_max(tmp);
            }
            else
            {
                tmp[index] = num[i];
            }
            res.push_back(max_num);
            ++index;
        }

        return res;
    }
};

// 采用双向链表的方法
class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        list<int> l_;
        vector<int> res;
        for (int i = 0; i < num.size(); ++i)
        {
            //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            while (l_.size() && num[l_.back()] <= num[i])
                l_.pop_back();
            //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            while (l_.size() && i - l_.front() + 1 > size)
                l_.pop_front();
            l_.push_back(i);
            //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            if (size && i + 1 >= size)
                res.push_back(num[l_.front()]);
        }
        return res;
    }
};