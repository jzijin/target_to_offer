/*
 * struct ListNode {
 *  int val;
 *      struct ListNode *next;
 *          ListNode(int x) :
 *                      val(x), next(NULL) {
 *                          }
 *                          };*/
class Solution {
    public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) {
            if(pHead1 == nullptr || pHead2 == nullptr)
                return nullptr;
            map<ListNode*, bool> convenge;
            while(pHead1)
            {
                        convenge[pHead1] = true;
                        pHead1 = pHead1->next;
                    }
            while(pHead2)
            {
                        if(convenge[pHead2])
                            return pHead2;
                        pHead2 = pHead2->next;
                    }
            return nullptr;

        }
};
