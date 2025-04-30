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

/* Definition for a binary tree node */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Helper function for recursive traversal */
void dfs(struct TreeNode* root, int* result, int* idx) {
    if (!root) return;

    result[(*idx)++] = root->val;      // Visit root
    dfs(root->left, result, idx);      // Traverse left subtree
    dfs(root->right, result, idx);     // Traverse right subtree
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Allocate maximum possible size (at most 100 nodes)
    int* result = malloc(sizeof(int) * 100);
    int idx = 0;

    dfs(root, result, &idx);

    *returnSize = idx;
    return result; // Caller is expected to free this memory
}
    
