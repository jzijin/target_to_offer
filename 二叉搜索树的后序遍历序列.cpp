// 复制的方法， 效率不高
class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        return valid(sequence);
    }
    bool valid(vector<int> &sequence)
    {
        // 递归的出口
        if (sequence.size() <= 2)
            return true;
        // 得到最后一个节点
        // 如果连续比最后一个节点的值小就是左子树 反之就是右子树1
        int root = sequence.back();
        vector<int> sequence_left;
        int i;
        for (i = 0; i < sequence.size() - 1; ++i)
        {
            if (sequence[i] < root)
                sequence_left.push_back(sequence[i]);
            else
                break;
        }
        vector<int> sequence_right(sequence.begin() + i, sequence.end() - 1);
        for (auto i : sequence_right)
        {
            if (i < root)
                return false;
        }
        return valid(sequence_left) && valid(sequence_right);
    }
};


// 不需要复制的方法
class Solution {
    bool judge(vector<int>& a, int l, int r){
        if(l >= r) return true;
        int i = r;
        while(i > l && a[i - 1] > a[r]) --i;
        for(int j = i - 1; j >= l; --j) if(a[j] > a[r]) return false;
        return judge(a, l, i - 1) && (judge(a, i, r - 1));
    }
public:
    bool VerifySquenceOfBST(vector<int> a) {
        if(!a.size()) return false;
        return judge(a, 0, a.size() - 1);
    }
};