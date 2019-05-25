class Solution
{
  public:
    // TODO: 这个效率可能并不是很高
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1)
        {
            return pHead2;
        }
        if (!pHead2)
        {
            return pHead1;
        }
        vector<int> lists;
        while (pHead1)
        {
            lists.push_back(pHead1->val);
            pHead1 = pHead1->next;
        }
        while (pHead2)
        {
            lists.push_back(pHead2->val);
            pHead2 = pHead2->next;
        }
        sort(lists.begin(), lists.end());
        ListNode *head = new ListNode(lists.front());
        ListNode *p = head;
        for (auto i = lists.cbegin() + 1; i != lists.cend(); ++i)
        {
            ListNode *q = new ListNode(*i);
            p->next = q;
            p = q;
        }
        return head;
    }
};

class Solution
{
  public:
    ListNode *Merge(ListNode *l1, ListNode *l2)
    {
        struct ListNode *last = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *start = (struct ListNode *)malloc(sizeof(struct ListNode));
        start = last;
        start->next = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                last->next = l1;
                last = last->next;
                l1 = l1->next;
            }
            else
            {
                last->next = l2;
                last = last->next;
                l2 = l2->next;
            }
        }
        if (l1 == NULL && l2 != NULL)
        {
            last->next = l2;
        }
        if (l2 == NULL && l1 != NULL)
        {
            last->next = l1;
        }
        return start->next;
    }
};