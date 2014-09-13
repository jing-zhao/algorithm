class TreePostOrderIterator
{
    public:
        TreePostOrderIterator(TreeNode* root) {
            if (root) {
                m_stack.push(NULL);
                m_stack.push(root);
            }
            advance();
        }
        bool atEnd() {
            return !m_cur;
        }
        TreeNode* getCur() {
            return m_cur;
        }
        void advance() {
			m_cur = NULL;
            while (!m_stack.empty()) {
                TreeNode* n = m_stack.top();
                m_stack.pop();
                if (m_stack.empty() || m_stack.top()) {
                    m_cur = n;
                    break;
                }
                m_stack.pop();
                m_stack.push(n);
                if (n->right) {
                    m_stack.push(NULL);
                    m_stack.push(n->right);
                }
                if (n->left) {
                    m_stack.push(NULL);
                    m_stack.push(n->left);
                }
            }
        }
    private:
        TreeNode* m_cur;
        stack<TreeNode*> m_stack;
};

int main(int argc, _TCHAR* argv[])
{
	TreeNode* root = deSerialize(cin);
	TreePostOrderIterator it(root);
	while (1) {
		TreeNode* n = it.getCur();
		if (!n) break;
		cout << n->val << ' ';
		it.advance();
	}
	return 0;
}
