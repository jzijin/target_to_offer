class Solution {
    public:
        // 递归加层序遍历的方法，但是效率不是很高
    int get_depth(TreeNode* root)
    {
            if(root == nullptr)
                return 0;
            int left = get_depth(root->left);
            int right = get_depth(root->right);
            return left > right ? left + 1 : right + 1;
        }
    bool IsBalanced_Solution(TreeNode* pRoot) {
            if(pRoot == nullptr)
                return true;
            queue<TreeNode*> q;
            TreeNode* t;
            q.push(pRoot);
            while(!q.empty())
            {
                        t = q.front();
                        q.pop();
                        int l_depth = get_depth(pRoot->left);
                        int r_depth = get_depth(pRoot->right);
                        if(abs(l_depth-r_depth) > 1)
                            return false;
                        if(t->left != nullptr)
                            q.push(t->left);
                        if(t->right != nullptr)
                            q.push(t->right);
                    }
            return true;


        }
};
// 这种做法有很明显的问题，在判断上层结点的时候，会多次重复遍历下层结点，
// 增加了不必要的开销。如果改为从下往上遍历，
// 如果子树是平衡二叉树，则返回子树的高度；
// 如果发现子树不是平衡二叉树，则直接停止遍历，
// 这样至多只对每个结点访问一次。
class Solution {
    public:
    int max(int a, int b)
    {
            return a>b ? a : b;
        }
    int get_depth(TreeNode* root)
    {
            if(root == nullptr)
                return 0;
            int left = get_depth(root->left);
            if(left == -1)
                return -1;
            int right = get_depth(root->right);
            if(right == -1)
                return -1;
            return abs(left - right) > 1 ? -1 : 1 + max(left, right);
        }
    bool IsBalanced_Solution(TreeNode* pRoot) {

                  return get_depth(pRoot) != -1;

        }
};
