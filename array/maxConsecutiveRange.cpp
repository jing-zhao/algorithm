struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};
struct IntervalCompare {
    bool operator()(Interval& a, Interval& b) {
        return a.start < b.start;
    }
};
int maxRange(Interval intervals[], int n) {
    if (n <= 0) return -1;
    sort(intervals, intervals+n, IntervalCompare());
    int curEnd, maxLen = INT_MIN, curLen = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            curLen = maxLen = intervals[i].end - intervals[i].start + 1;
            curEnd = intervals[i].end;
        }
        else {
            if (intervals[i].start > curEnd) {
                curLen = intervals[i].end - intervals[i].start + 1;
                curEnd = intervals[i].end;
            }
            else {
                int newEnd = max(curEnd, intervals[i].end);
                curLen += newEnd-curEnd;
                curEnd = newEnd;
            }
            maxLen = max(maxLen, curLen);
        }
    }
    return maxLen;
}

int main(int argc, _TCHAR* argv[])
{
	Interval i1(1, 3);
	Interval i2(2, 5);
	Interval i3(8, 9);
	// Interval intervals[] = {i1, i2, i3};
	Interval intervals[] = {i3, i2, i1};
	int ret = maxRange(intervals, sizeof(intervals)/sizeof(Interval));
	return 0;
}
