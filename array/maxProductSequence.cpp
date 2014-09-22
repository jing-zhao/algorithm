int maxProduct(int A[], int start, int end) {
    int maxProd = INT_MIN, curProd = 1;
    for (int i = start; i <= end; i++) {
        curProd *= A[i];
        maxProd = max(maxProd, curProd);
    }
    return maxProd;
}
// Find the largest subsequence of the given array that yields the largest PRODUCT
int maxProduct(int A[], int n) {
    int maxProd = INT_MIN, curProd = 1, firstNeg = -1;
    for (int i = 0; i < n; i++) {
        curProd *= A[i];
        maxProd = max(maxProd, curProd);
        if (curProd < 0 && firstNeg == -1) firstNeg = i;
        if (curProd == 0) {
            if (firstNeg != -1) {
                maxProd = max(maxProd, maxProduct(A, firstNeg+1, i));
            }
            firstNeg = -1;
            curProd = 1;
        }
    }
    if (firstNeg != -1) maxProd = max(maxProd, maxProduct(A, firstNeg+1, n-1));
    return maxProd;
}
int main(int argc, _TCHAR* argv[])
{
	// int A[] = {4, 7, 2, -3, 1, 0, 7 , -5, 6, -1, 2};
	// int A[] = {-3, -1, -4, -2, -10};
	// int A[] = {4, 7, 2, 3, 1};
	// int A[] = {-1};
	// int A[] = {0, 0, 0, 0};
	// int A[] = {-1, -2, -3, -4, -5, 0, 2, -5, -1, -7};
	// int A[] = {-1, -2, -3, -4, 0, 2, -5, -1, -7};
	int A[] = {-1, -2, -3, 0, 2, -5, -1, -7};
	int ret = maxProduct(A, sizeof(A)/sizeof(int));
	return 0;
}
