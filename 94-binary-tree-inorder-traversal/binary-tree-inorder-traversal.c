/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countNode(struct TreeNode* root)
{
    if (root==NULL)
    {
        return 0;
    }

    return 1 + countNode(root->left) + countNode(root->right);
}

void traversal(struct TreeNode* root, int *arr, int *index)
{
    if(root==NULL)
    {
        return;
    }
    traversal(root->left,arr,index);
    arr[*index] = root->val;
    (*index)++;
    traversal(root->right,arr,index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNode(root);
    int* result = (int*)malloc((*returnSize)*sizeof(int));
    int index = 0;
    traversal(root,result,&index);

    return result;
}