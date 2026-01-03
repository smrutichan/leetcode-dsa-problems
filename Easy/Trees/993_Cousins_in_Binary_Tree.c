/*
Problem: Cousins in Binary Tree

Approach:
- Traverse the tree using DFS and record depth and parent of both nodes
- Nodes are cousins if they have the same depth but different parents

Time Complexity: O(n)
Space Complexity: O(h)
*/

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int xDepth = -1, yDepth = -1;
struct TreeNode* xParent = NULL;
struct TreeNode* yParent = NULL;

void dfs(struct TreeNode* root, struct TreeNode* parent, int depth, int x, int y) {
    if (root == NULL) {
        return;
    }
    if (root->val == x) {
        xDepth = depth;
        xParent = parent;
    }
    if (root->val == y) {
        yDepth = depth;
        yParent = parent;
    }

    dfs(root->left, root, depth + 1, x, y);
    dfs(root->right, root, depth + 1, x, y);
}

bool isCousins(struct TreeNode* root, int x, int y) {
    dfs(root, NULL, 0, x, y);
    return (xDepth == yDepth) && (xParent != yParent);
}
