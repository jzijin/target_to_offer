class Solution
{
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> target;
        queue<TreeNode *> qu;
        if (root == nullptr)
            return target;
        qu.push(root);
        while (!qu.empty())
        {
            TreeNode *node = qu.front();
            qu.pop();
            target.push_back(node->val);
            if (node->left != nullptr)
                qu.push(node->left);
            if (node->right != nullptr)
                qu.push(node->right);
        }
        return target;
    }
};