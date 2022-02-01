/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (nullptr == head) return head; 
        
        ListNode* currentNode = head;

        while(nullptr != currentNode->next)
        {
            if (currentNode->val != currentNode->next->val){
                currentNode = currentNode->next;
                continue; 
            } 
            else {
                if (nullptr != currentNode->next->next) {
                    currentNode->next = currentNode->next->next;
                } else {
                    currentNode->next = nullptr;
                }
            }
        }
        return head;
    }
};
