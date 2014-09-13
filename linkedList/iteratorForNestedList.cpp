struct NestedListNode
{
    int val;
    NestedListNode* next;
    NestedListNode* nestedNode;
    NestedListNode(int num) :val(num), next(0), nestedNode(0) {}
}
class NestedListIterator
{
    public:
        NestedListIterator(NestedListNode* head) : m_cur(head) {}
        NestedListNode* getCur() {
            return m_cur;
        }
        bool atEnd() {
            return !m_cur;
        }
        void advance() {
            if (m_cur->nestedNode) {
                if (m_cur->next) m_stack.push(m_cur->next);
                m_cur = m_cur->nestedNode;
            }
            else if (m_cur->next) {
                m_cur = m_cur->next;
            }
            else {
                if (m_stack.empty()) m_cur = NULL;
                m_cur = m_stack.top();
                m_stack.pop();
            }
        }
    private:
        NestedListNode* m_cur;
        stack<NestedListNode*> m_stack;
}
