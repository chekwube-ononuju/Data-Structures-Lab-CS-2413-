#include <stdlib.h>

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Helper function to perform inorder traversal and store values */
void inorder(struct TreeNode* root, int* result, int* idx) {
    if (!root) return;

    inorder(root->left, result, idx);
    result[(*idx)++] = root->val;
    inorder(root->right, result, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100); // Max size 100 based on constraints
    int idx = 0;

    inorder(root, result, &idx);
    *returnSize = idx;
    return result; // Caller must free this
}