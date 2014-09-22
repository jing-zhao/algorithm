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

TreeNode* flipTree(TreeNode* root) {
    if (!root) return root;
    stack<TreeNode*> st;
    while (root) {
        st.push(root);
        root = root->left;
    }
    TreeNode* prev = 0;
	root = 0;
    while (!st.empty()) {
        TreeNode* n = st.top();
        st.pop();
        if (!prev) {
            root = n;
        }
        else {
            prev->left = n->right;
            prev->right = n;
        }
        prev = n;
    }
    prev->left = prev->right = 0;
    return root;
}
