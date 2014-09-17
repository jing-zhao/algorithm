struct Compare {
	bool operator() (int a, int b) {
		return a>b;
	}
};
struct Interval {
	int start;
	int end;
	Interval(int s, int e) : start(s), end(e) {}
};
int numOfMeetingRooms(vector<Interval>& meetings) {
	priority_queue<int, std::vector<int>, Compare> pq;
	for (int i = 0; i < meetings.size(); i++) {
		if (!pq.empty() && pq.top() <= meetings[i].start) {
			pq.pop();
		}
		pq.push(meetings[i].end);
	}
	return pq.size();
}
int main(int argc, _TCHAR* argv[])
{
	vector<Interval> v;
	Interval i1(7, 12);
	Interval i2(8, 9);
	Interval i3(8, 10);
	Interval i4(11, 12);
	v.push_back(i1);
	v.push_back(i2);
	v.push_back(i3);
	v.push_back(i4);
	int room = numOfMeetingRooms(v);
	return 0;
}
