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

int countNodes(struct TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void traversal(struct TreeNode* root, int* arr, int* index){
    if(root==NULL)
    {
        return;
    }
    arr[*index] = root->val;
    (*index)++;
    traversal(root->left,arr,index);
    traversal(root->right,arr,index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int index =0;
    traversal(root,result,&index);

    return result;
}