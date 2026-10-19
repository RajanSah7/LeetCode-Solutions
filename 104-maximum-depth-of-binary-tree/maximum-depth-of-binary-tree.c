/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root==NULL)
    {
        return 0;
    }
    int leftht = maxDepth(root->left);
    int rightht = maxDepth(root->right);
    if(leftht>rightht)
    {
        return 1 + leftht;
    }
    return 1 + rightht;
}