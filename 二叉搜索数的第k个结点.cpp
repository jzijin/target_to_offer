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
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {

        stack<TreeNode *> myStack;
        int index = 0;
        while (pRoot || !myStack.empty())
        {
            while (pRoot)
            {
                myStack.push(pRoot);
                pRoot = pRoot->left;
            }
            pRoot = myStack.top();
            myStack.pop();
            index++;
            if (index == k)
                return pRoot;
            if (pRoot->right != nullptr)
                pRoot = pRoot->right;
            else
                pRoot = nullptr;
        }
        return nullptr;
    }
};