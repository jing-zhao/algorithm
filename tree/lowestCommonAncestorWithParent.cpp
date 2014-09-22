// Find the lowest common ancestor given two nodes
TreeNode* lowestCommonAncestor(TreeNode* n1, TreeNode* n2) {
    if (!n1 || !n2) return NULL;
    TreeNode* last1 = n1, *last2 = n2;
    int len1 = getPath(n1, last1);
    int len2 = getPath(n2, last2);
    if (last1 != last2) return NULL;
    if (len1 > len2) n1 = advance(n1, len1-len2);
    if (len2 > len1) n2 = advance(n2, len2-len1);
    while (n1 != n2) {
        n1 = n1->parent;
        n2 = n2->parent;
    }
    return n1;
}
int getPath(TreeNode* n, TreeNode*& last) {
    last = n;
    int len = 0;
    while (last->parent) {
            len++;
            last = last->parent;
    }
    return len;
}
TreeNode* advance(TreeNode* node, int n) {
    for (int i = 0; i < n; i++) node = node->parent;
    return node;
}
