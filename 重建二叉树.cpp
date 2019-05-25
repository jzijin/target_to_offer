/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
  public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
            if(vin.size() == 0)
                return nullptr;
            TreeNode* head = new TreeNode(pre[0]);
            int index = 0;
            while(index < vin.size())
            {
                        if(head->val == vin[index])
                            break;
                        index++;
             }
            vector<int> pre_left(pre.begin()+1, pre.begin()+index+1);
            vector<int> pre_right(pre.begin()+index+1, pre.end());
            vector<int> vin_left(vin.begin(), vin.begin() + index);
            vector<int> vin_right(vin.begin() + index + 1, vin.end());
            head->left = reConstructBinaryTree(pre_left, vin_left);
            head->right = reConstructBinaryTree(pre_right, vin_right);
            return head;
            
        }
};
