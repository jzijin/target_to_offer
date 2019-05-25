class Solution {
  public:
    vector<int> printListFromTailToHead(ListNode* head) {
             
            vector<int> arraylist;
            vector<int> target;
            if(head == nullptr)
            {
                        return arraylist;
                    }
            while(head != nullptr)
            {
                        arraylist.push_back(head->val);
                        head = head->next;
                    }
            while(!arraylist.empty())
            {
                        target.push_back(arraylist.back());
                        arraylist.pop_back();
                    }
            return target;
             
        }
};
