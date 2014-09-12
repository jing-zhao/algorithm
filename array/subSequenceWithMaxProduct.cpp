int maxProduct(int A[], int n) {
    int maxProd = INT_MIN, cur = 1, firstNegIndex = -1;
    if (n <= 0) return maxProd;
    for (int i = 0; i < n; i++) {
        cur *= A[i];
        maxProd = max(maxProd, cur);
        if (A[i] < 0 && firstNegIndex == -1) firstNegIndex = i;
        if (cur == 0) {
            if (firstNegIndex != -1 && firstNegIndex < i-1) {
                int prod = 1, index = firstNegIndex +1;
                while (index < i) prod *= A[index++];
                maxProd = max(maxProd, prod);
            }
            cur = 1;
            firstNegIndex = -1;
        }
    }
    if (firstNegIndex != -1 && firstNegIndex < n-1) {
        int prod = 1, index = firstNegIndex +1;
        while (index < n) prod *= A[index++];
        maxProd = max(maxProd, prod);
    }
    return maxProd;
}

int main(int argc, _TCHAR* argv[])
{
	int A[] = {4, 7, 2, -3, 1, 0, 7 , -5, 6, -1, 2};
	// int A[] = {-3, -1, -4, -2, -10};
	// int A[] = {4, 7, 2, 3, 1};
	// int A[] = {-1};
	int ret = maxProduct(A, sizeof(A)/sizeof(int));
	return 0;
}
