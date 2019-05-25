/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution
{
public:
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> vec;
        if (pRoot == NULL)
            return vec;

        queue<TreeNode *> q;
        q.push(pRoot);

        while (!q.empty())
        {
            // 用一个变量来控制循环就可以了
            int lo = 0, hi = q.size();
            vector<int> c;
            while (lo++ < hi)
            {
                TreeNode *t = q.front();
                q.pop();
                c.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            vec.push_back(c);
        }
        return vec;
    }
};