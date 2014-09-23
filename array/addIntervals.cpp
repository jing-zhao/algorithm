int compare(Interval& i1, Interval& i2) {
    if (i1.end < i2.start) return -1;
    else if (i1.start > i2.end) return 1;
    else return 0;
}
int getLength(Interval& i) {
    return i.end - i.start;
}
class Intervals {
    public:
        Intervals() : m_totalCovered(0) {}
        void addInterval(Interval interval) {
            int lastIndex = 0;
            for (int i = 0; i < m_intervals.size(); i++) {
                int compare = compare(interval, m_intervals[i]);
                if (compare < 0) {
                    Interval tmpInterval = m_intervals[i];
                    m_intervals[lastIndex++] = interval;
                    m_totalCovered += getLength(interval);
                    interval = tmpInterval;
                }
                else if (compare > 0) {
                    m_intervals[lastIndex++] = m_intervals[i];
                    m_totalCovered += getLength(m_intervals[i]);
                }
                else {
                    interval = merge(interval, m_intervals[i]);
                }
            }
            if (lastIndex == m_intervals.size()) {
                m_intervals.push_back(interval);
            }
            else {
                m_intervals[lastIndex++] = interval;
                m_intervals.resize(lastIndex);
            }
            m_totalCovered += getLength(interval);
        }
    int getTotalCoveredLength() {
        return m_totalCovered;
    }
    private:
        vector<Interval> m_intervals;
        int m_totalCovered;
}
