/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    // 先储存起来 避免多次调用造成时间的浪费
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;
    //return maxDepth(root->left) > maxDepth(root->right) ? 1 + maxDepth(root->left) : 1 + maxDepth(root->right);
}
*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        int max_depth = 0;
        int tmp = 0;
        stack<TreeNode*> s;
        s.push(pRoot);
        while(!s.empty() or pRoot != nullptr)
        {
            while(pRoot != nullptr)
            {
                pRoot = pRoot->left;
                tmp++;
            }
            pRoot = s.top();
            s.pop();
            tmp--;
            max_depth = max_depth > tmp ? max_depth : tmp;
            if(pRoot->right != nullptr)
            {
                pRoot = pRoot->right;
                s.push(pRoot);
            }
            else{ // 强制退栈
                pRoot = nullptr;
            }
            
        }
        return max_depth;
    }
};