/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    struct ListNode *head1 = NULL;
    struct ListNode *temp = head;
    
    while (temp != NULL) {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = temp->val;
        newnode->next = head1; 
        head1 = newnode;       
        temp = temp->next;
    }

    struct ListNode *t1 = head;
    struct ListNode *t2 = head1;
    
    while (t1 != NULL && t2 != NULL) {
        if (t1->val != t2->val) {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    
    return true;
}