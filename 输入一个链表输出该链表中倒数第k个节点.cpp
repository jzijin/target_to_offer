class Solution
{
  public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {

        if (pListHead == NULL || k == 0)
            return NULL;
        ListNode *pTail = pListHead, *pHead = pListHead;
        // TODO: 两个循环可以合成一个
        for (int i = 1; i < k; ++i)
        {
            if (pHead->next != NULL)
                pHead = pHead->next;
            else
                return NULL;
        }
        while (pHead->next != NULL)
        {
            pHead = pHead->next;
            pTail = pTail->next;
        }
        return pTail;
    }
};