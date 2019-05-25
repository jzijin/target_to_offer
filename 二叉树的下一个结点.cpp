/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; // 指向父节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution
{
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (pNode == nullptr)
            return nullptr;
        if (pNode->right != nullptr) // 如果有右子树 找右子树的最左边的结点
        {
            pNode = pNode->right;
            while (pNode->left != nullptr)
                pNode = pNode->left;
            return pNode;
        }
        // 如果没有右子树. 这边的while循环画个图会更清楚
        while (pNode->next != nullptr)
        {
            if (pNode->next->left == pNode)
                return pNode->next;
            pNode = pNode->next;
        }
        return nullptr;
    }
};