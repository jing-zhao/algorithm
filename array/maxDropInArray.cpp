// Finding the largest drop in a an array

int maxDrop(int A[], int n) {
    int maxDrop = INT_MIN, maxNum = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            maxDrop = max(maxDrop, maxNum - A[i]);
        }
        maxNum = max(maxNum, A[i]);
    }
    return maxDrop;
}

int main(int argc, _TCHAR* argv[])
{
	// int A[] = { 5, 21, 3, 27, 12, 24, 7, 6, 4};
	// int A[] = {5, 21, 3, 22, 12, 7, 26, 14};
	int A[] = {5, 21, 25, 30};
	int ret = maxDrop(A, sizeof(A)/sizeof(int));
	return 0;
}
