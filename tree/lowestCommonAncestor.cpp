```c++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2, int& covered) {
  covered = 0;
  if (!root) return NULL;
  if (root == n1 || root == n2) covered = 1;
  int lCovered = 0, rCovered = 0;
  TreeNode* lCommon = lowestCommonAncestor(root->left, n1, n2, lCovered);
  if (lCommon) return lCommon;
  TreeNode* rCommon = lowestCommonAncestor(root->right, n1, n2, rCovered);
  if (rCommon) return rCommon;
  covered += lCommon + rCommon;
  if (covered == 2) return root;
  else return NULL;
}
```


