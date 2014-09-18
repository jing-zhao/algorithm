pair<int, int> largestAscSeq(int A[], int n) {
    pair<int,int> ret(-1, -1);
    if (n <= 0) return ret;
    int maxLen = INT_MIN, start = 0;
    for (int i = 0; i < n; i++) {
        if (i == n-1 || A[i+1] <= A[i]) {
            if (i-start+1 > maxLen) {
                maxLen = i-start+1;
                ret.first = start;
                ret.second = i;
            }
            start = i+1;
        }
    }
    return ret;
}
