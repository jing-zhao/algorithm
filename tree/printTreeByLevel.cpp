void printByLevel(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        if (n) {
            cout<<n->val;
            if (q.front()) cout<<' ';
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        else {
            cout<<endl;
            if (!q.empty()) q.push(NULL);
        }
    }
}
