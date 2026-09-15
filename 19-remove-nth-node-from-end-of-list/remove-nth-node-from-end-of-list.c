/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* prev=NULL, *curr=head, *afternext=NULL,*ptr,*preptr;
    if(head == NULL)
    {
        return head;
    }

    if(head->next == NULL)
    {
        return NULL;
    }
    while(curr!=NULL)
    {
        afternext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = afternext;

        //curr = curr->next;
    }

    head = prev;
     if(n==1)
        {
            head = head->next;
        }
    ptr = head;
    preptr = ptr;
    int c=0;
    while(ptr!=0)
    {
       
        c=c+1;
       
        if(c==n)
        {
            preptr->next = ptr->next;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    curr = head;
    afternext = NULL;
    prev = NULL;
    while(curr!=NULL)
    {
        afternext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = afternext;

        //curr = curr->next;
    }
    head = prev;

    return head;
}