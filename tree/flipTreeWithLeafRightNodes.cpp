TreeNode* flip(TreeNode* root, TreeNode*& rightMost) {
    rightMost = root;
    if (!root) return root;
    if (!root->left && !root->right) return root;
    if (!root->left) {
        TreeNode* newRoot = root->right;
        root->right->left = root;
        root->right = 0;
        return newRoot;
    }
    TreeNode* leftRightMost;
    TreeNode* leftRoot = flip(root->left, leftRightMost);
    leftRightMost->left = root->right;
    leftRightMost->right = root;
	  root->left = root->right = 0;
    return leftRoot;
}
