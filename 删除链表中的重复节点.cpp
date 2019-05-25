/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        //新建一个节点，防止头结点要被删除
        ListNode* newHead=new ListNode(-1);
        newHead->next = pHead;
        ListNode* p3 = newHead;
        ListNode* p2 = pHead;
        ListNode* p1 = nullptr;
        while(p2 != nullptr && p2->next != nullptr)
        {
            p1 = p2->next;
            if(p1->val == p2->val)
            {
                 while(p1 != nullptr && p1->val == p2->val)
                    p1 = p1->next;
                p3->next = p1;
                p2 = p1;
            }
           else{//如果当前节点和下一个节点值不等，则向后移动一位
               p3 = p2;
               p2 = p2->next;
           }
                      
        }
        return newHead->next;
    }
};