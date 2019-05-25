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
// TODO: 还是有点问题
    char* Serialize(TreeNode *root) {
        // 然后再把s 转成char *
        string s("");
        if(root == nullptr)
        {
           s += '#';
          char * cstr = new char [s.length()+1];
          strcpy (cstr, s.c_str());
          return cstr;
        }
        stack<TreeNode *> myStack;
        while(root || !myStack.empty())
        {
            while(root)
            {
                s += to_string(root->val);
                s += ","; // 加入逗号分割。
                myStack.push(root);
                root = root->left;
            }
                root = myStack.top();
                myStack.pop();
            
            
            if(root->right != nullptr)
            {
                root = root->right;
            }
            else 
            {
                root = nullptr; // 强迫退栈
            }
        }
            s += '#'; // 加入结束符
          char * cstr = new char [s.length()+1];
          strcpy (cstr, s.c_str());
          return cstr;
            
        
        
    }
TreeNode* decode(char *&str) {
        if(*str=='#'){
            str++;
            return nullptr;
        }
    string s("");
    while(*str != ',')
        s += *str++;
    str++;
    int node_val = stoi(s);
    TreeNode *root = new TreeNode(node_val);
        root->left = decode(str);
        root->right = decode(str);
        return root;
        
}
    TreeNode* Deserialize(char *str) {
        return decode(str);
    }
};

// 别人用递归写的
typedef TreeNode node;
typedef TreeNode* pnode;
typedef int* pint;
class Solution {
    vector<int> buf;
    void dfs(pnode p){
        if(!p) buf.push_back(0x23333);
        else{
            buf.push_back(p -> val);
            dfs(p -> left);
            dfs(p -> right);
        }
    }
    pnode dfs2(pint& p){
        if(*p == 0x23333){
            ++p;
            return NULL;
        }
        pnode res = new node(*p);
        ++p;
        res -> left = dfs2(p);
        res -> right = dfs2(p);
        return res;
    }
public:
    char* Serialize(TreeNode *p) {
        buf.clear();
        dfs(p);
        int *res = new int[buf.size()];
        for(unsigned int i = 0; i < buf.size(); ++i) res[i] = buf[i];
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*)str;
        return dfs2(p);
    }
};
