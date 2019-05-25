/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    private:
    bool isthesame(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr && pRoot2==nullptr)
            return true;
        if(pRoot1 == nullptr && pRoot2 != nullptr)
            return false;
        if(pRoot1 != nullptr && pRoot2 == nullptr)
            return true;
        if(pRoot1->val != pRoot2->val)
            return false;
        return isthesame(pRoot1->left, pRoot2->left) && isthesame(pRoot1->right, pRoot2->right);
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if(isthesame(pRoot1, pRoot2))
            return true;
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};