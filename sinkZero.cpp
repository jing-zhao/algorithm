// Sink Zero in Binary Tree. Swap zero value of a node with non-zero value of one of its descendants 
// so that no node with value zero could be parent of node with non-zero

void sinkZero(TreeNode* root)
{
    if (!root) return;
    sinkZero(root->left);
    sinkZero(root->right);
    if (!root->val) {
        if (root->left && root->left->val) {
            swap(root->val, root->left->val);
            sinkZero(root->left);
        }
        else if (root->right && root->right->val) {
            swap(root->val, root->right->val);
            sinkZero(root->right);
        }
    }
}
