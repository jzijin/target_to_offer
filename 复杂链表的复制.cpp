/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        RandomListNode *currentNode = pHead;
        //1、复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面；
        while (currentNode)
        {
            RandomListNode *currentNodeClone = new RandomListNode(currentNode->label);
            RandomListNode *nextNode = currentNode->next;
            currentNodeClone->next = nextNode;
            currentNode->next = currentNodeClone;
            currentNode = nextNode;
        }

        //2、重新遍历链表，复制老结点的随机指针给新结点，如A1->random = A->random->next;
        currentNode = pHead;
        while (currentNode)
        {
            currentNode->next->random = currentNode->random == nullptr ? nullptr : currentNode->random->next;
            currentNode = currentNode->next->next;
        }

        //3、拆分链表，将链表拆分为原链表和复制后的链表
        currentNode = pHead;
        RandomListNode *pCloneHead = currentNode->next;
        RandomListNode *tmp;
        while (currentNode->next)
        {
            tmp = currentNode->next;
            currentNode->next = tmp->next;
            currentNode = tmp;
        }
        return pCloneHead;
    }
};