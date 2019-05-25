class Solution {
public:
//TODO: 应该有不用写一个函数的简化方法， 而且题目中的从大到小排列根本就没有碰到？？？
    void find(vector<vector<int> > &res, vector<int> &tmp, TreeNode* root,int expectNumber)
    {
        if(root == nullptr)
            return;
        tmp.push_back(root->val);
        if(root->val != expectNumber)  {         
           
            vector<int> tmp1(tmp);
            vector<int> tmp2(tmp);
            find(res,tmp1, root->left,expectNumber-root->val);
            find(res,tmp2, root->right,expectNumber-root->val);
        }
        else{
            if(root->left == nullptr && root->right == nullptr)
                res.push_back(tmp);
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        vector<int> tmp;
        find(res, tmp, root, expectNumber);
        return res;
    }
};