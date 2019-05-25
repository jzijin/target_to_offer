class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> model;
        int size = pushV.size(); // 得到pushV的大小
        int index = 0;
        for(int i=0; i<size; ++i)
        {
            model.push(pushV[i]);
            // 防止越界     如果相等 一直弹
            while(index < size && popV[index] == model.top())
            {
                model.pop();
                index++;
            }
        }        
        return model.empty() ? true : false;
    }
};