class Solution
{
public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        stack<TreeNode *> node;
        TreeNode *t = nullptr;
        TreeNode *head = nullptr;
        while (pRootOfTree || !node.empty())
        {
            while (pRootOfTree)
            {
                node.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }

            pRootOfTree = node.top();
            node.pop();
            if (t == nullptr)
            {
                t = pRootOfTree;
                head = pRootOfTree;
            }
            else
            {
                t->right = pRootOfTree;
                pRootOfTree->left = t;
                t = pRootOfTree;
            }
            pRootOfTree = pRootOfTree->right;
        }
        return head;
    }
};