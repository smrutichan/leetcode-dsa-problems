/*
Problem: Path Sum

Approach:
- Use depth-first search (DFS) recursion

Time Complexity: O(n)
Space Complexity: O(h) where h is height of tree
*/

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL)
        return false;

    // Subtract current node's value from targetSum
    targetSum -= root->val;

    // If it's a leaf node, check if targetSum becomes 0
    if (root->left == NULL && root->right == NULL) {
        return targetSum == 0;
    }

    // Recursively check left or right subtree
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
