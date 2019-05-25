/*
 * struct ListNode {
 *     int val;
 *         struct ListNode *next;
 *             ListNode(int x) :
 *                     val(x), next(NULL) {
 *                         }
 *                         };
 *                         */
class Solution {
  public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
            map<ListNode*, bool> m;
            while(pHead)
            {
                        if(m[pHead])
                            return pHead;
                        m[pHead] = true;
                        pHead = pHead->next;
                    }
            return nullptr;
        }
};
