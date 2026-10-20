/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getLength(struct ListNode* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct TreeNode* sortedListToBSTHelper(struct ListNode** headRef, int left, int   right) {
    if (left > right) {
        return NULL;
    }
    
    int mid = left + (right - left) / 2;
    
    struct TreeNode* leftChild = sortedListToBSTHelper(headRef, left, mid - 1);
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = (*headRef)->val;
    root->left = leftChild;
    
    *headRef = (*headRef)->next;
    
    root->right = sortedListToBSTHelper(headRef, mid + 1, right);
    
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int len = getLength(head);
    return sortedListToBSTHelper(&head, 0, len - 1);
}