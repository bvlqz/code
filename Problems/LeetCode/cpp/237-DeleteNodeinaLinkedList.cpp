/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {        
        // Take the current node
        // Assing the value of the next node to the current node
        // We delete the FINAL node
        
        ListNode* lastModifiedNode = node;
        while (node->next != NULL)
        { 
            node->val = node->next->val;
            
            lastModifiedNode = node;
            node = node->next; 
        }
        lastModifiedNode->next = NULL;
        delete node; 
    }
};
