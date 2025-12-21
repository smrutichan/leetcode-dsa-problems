/*
Problem: Same Tree

Approach:
- Use recursion to compare both trees node by node

Time Complexity: O(n)
Space Complexity: O(h)
*/

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // If both nodes are NULL, trees match here
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    // Check both left and right subtrees recursively
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
