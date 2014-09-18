vector<pair<int, int>> findRanges(int A[], int n) {
    vector<pair<int,int>> ret;
    if (n <= 0) return ret;
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (i == n-1 || A[i+1]-A[i] > 1) {
            pair<int, int> p(A[start], A[i]);
            ret.push_back(p);
            start = i+1;
        }
    }
    return ret;
}

int main(int argc, _TCHAR* argv[])
{
	// int A[] = {0, 1, 2, 4, 6, 7, 8};
	// int A[] = {2, 3, 3, 4, 6, 7,7, 9};
	// int A[] = {1, 1, 1, 1};
	int A[] = {1,3,5,7};
	vector<pair<int,int>> ret = findRanges(A, sizeof(A)/sizeof(int));
	return 0;
}
