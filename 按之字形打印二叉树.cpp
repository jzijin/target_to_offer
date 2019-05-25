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
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        // 应该要一个变量控制方向
        vector<vector<int> > res; // 返回目标
        if (pRoot == nullptr)
            return res;
        int l = 1;
        int r = 0;
        int direction = l;
        vector<int> mid; //中间变量
        list<TreeNode*> tmp;
        tmp.push_back(pRoot);
        TreeNode* q;
        while(!tmp.empty()) // 如果tmp 不空的画
        {
            int lo=0, len=tmp.size();
            
            if(direction == l)
            {
                while(lo++ < len)
                {
                    q = tmp.front();
                    mid.push_back(q->val);
                    tmp.pop_front();
                    if(q->left != nullptr)
                        tmp.push_back(q->left);
                    if(q->right != nullptr)
                        tmp.push_back(q->right);
                }      
            }
            else if(direction == r)
            {
                while(lo++ < len)
                {
                    q = tmp.back();
                    mid.push_back(q->val);
                    tmp.pop_back();
                    if(q->right != nullptr)
                        tmp.push_front(q->right);
                    if(q->left != nullptr)
                        tmp.push_front(q->left);
                    
                }
            }
            res.push_back(mid);
            mid.clear();
            direction = direction == l ? r : l;
        }
        return res;
        
    }
    
};