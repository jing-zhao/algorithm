vector<pair<int, int>> findDiff2(int A[], int n) {
    vector<pair<int, int>> ret;
    if (n < 2) return ret;
    int start = 0;
    for (int i = 1; i < n; i++) {
        while (A[i] - A[start] >= 2) {
            if (A[i] - A[start] == 2) {
                if (start == 0 || A[start] != A[start-1]) {
                    pair<int, int> p(A[start] ,A[i]);
                    ret.push_back(p);
                }
            }
            start++;
        }
    }
    return ret;
}
int main(int argc, _TCHAR* argv[])
{
	int A[] = {1, 3, 4, 6, 10, 10, 11, 11, 12, 13};
	vector<pair<int, int>> ret = findDiff2(A, sizeof(A)/sizeof(int));
	return 0;
}
