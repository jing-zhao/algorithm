// 三角形问题，输入一些线段的长度，找出能形成三角形的任一三条线段

vector<int> findTriangle(int A[], int n) {
    vector<int> ret;
    if (n < 3) return ret;
    sort(A, A+n);
    for (int i = n-1; i >= 2; i--) {
        if (A[i-1] + A[i-2] > A[i]) {
            ret.push_back(A[i-2]);
            ret.push_back(A[i-1]);
            ret.push_back(A[i]);
            return ret;
        }
    }
    return ret;
}
