class SlideWindow {
    public:
            SlideWindow(unsigned int wLen) : m_wLen(wLen), m_sum(0), m_curIndex(0) {}
            void put(int num) {
                if (!m_wLen) return;
                if (m_window.size() < m_wLen) {
                    m_window.push_back(num);
                    m_sum += num;
                }
                else {
                    m_sum += num - m_window[m_curIndex];
                    m_window[m_curIndex] = num;
                }
                m_curIndex = (m_curIndex+1)%m_wLen;
            }
            int getAvg() {
                if (!m_window.size()) return 0;
                return m_sum/m_window.size();
            }
    private:
        vector<int> m_window;
        unsigned int m_wLen;
        int m_sum;
        int m_curIndex;
};

int main(int argc, _TCHAR* argv[])
{
	SlideWindow window(3);
	for (int i = 1; i <=7; i++) {
		window.put(i);
		cout<<window.getAvg()<<endl;
	}
	return 0;
}
