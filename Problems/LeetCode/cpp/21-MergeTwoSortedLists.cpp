class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* mergedLinkedListNode = new ListNode(); 
        ListNode* tailNode = mergedLinkedListNode;

        ListNode* l1NodePtr = list1;
        ListNode* l2NodePtr = list2;

        while(l1NodePtr != nullptr && l2NodePtr != nullptr)
        {
            if (l1NodePtr->val <= l2NodePtr->val)
            {
                tailNode->next = l1NodePtr;
                l1NodePtr = l1NodePtr->next;
            }
            else
            {
                tailNode->next = l2NodePtr;
                l2NodePtr = l2NodePtr->next;
            }
            tailNode = tailNode->next;
        }
        if (l1NodePtr != nullptr) tailNode->next = l1NodePtr;
        if (l2NodePtr != nullptr) tailNode->next = l2NodePtr;
        return mergedLinkedListNode->next; 
    }
};
