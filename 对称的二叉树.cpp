class Solution {
public:
    bool is_(TreeNode* pRoot_left, TreeNode* pRoot_right)
    {
        if(pRoot_left==nullptr&&pRoot_right!=nullptr)
            return false;
        if(pRoot_left!=nullptr&&pRoot_right==nullptr)
            return false;
        if(pRoot_left==nullptr&&pRoot_right==nullptr)
            return true;
        if(pRoot_left->val != pRoot_right->val)
            return false;
        return is_(pRoot_left->left, pRoot_right->right) && is_(pRoot_left->right, pRoot_right->left);
        
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return true; // 奇葩啊
        return is_(pRoot->left, pRoot->right);
        
    }

};