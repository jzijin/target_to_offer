class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* current = pHead;
        ListNode* pnext = nullptr;
        ListNode* reversed = nullptr;
        while(current)
        {
            pnext = current->next;
            current->next = reversed;
            reversed = current;
            current = pnext;
        }
        return reversed;
    }
};