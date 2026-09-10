/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev=NULL, *curr=head, *curnext=NULL;

    while(curr!=NULL)
    {
        curnext=curr->next;
        curr->next=prev;
        prev = curr;
        curr = curnext;
    }
    head = prev;

    return head;
}