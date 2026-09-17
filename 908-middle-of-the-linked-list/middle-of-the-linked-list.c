/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp = head; 
    int count = 0;
    
    
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    int target = count / 2; 
    
    temp = head;
    int current = 0;
    
    
    while(temp != NULL) {
        if(current == target) {
            return temp; 
        }
        current++;
        temp = temp->next;
    }
    
    return NULL;

}