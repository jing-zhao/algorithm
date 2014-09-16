void markCountOnes(int n, int* countOnes) {
    for (int i = 0; i < sizeof(int); i++) {
        if (n & 1) countOnes[i]++;
        n >>= 1;
    }
}
int getSum(int n, int* countOnes, int prevCount) {
    int sum = 0;
    for (int i = 0; i < sizeof(int); i++) {
        if (n & 1) {
            sum += prevCount-countOnes[i];
        }
        else {
            sum += countOnes[i];
        }
        n >>= 1;
    }
    return sum;
}
int hammingSum(int A[], int n)
{
    int countOnes[sizeof(int)];
    memset(countOnes, 0, sizeof(int)*sizeof(int));
    int sum = 0;
    if (n <= 1) return 0;
    markCountOnes(A[0], countOnes);
    for (int i = 1; i < n; i++) {
        int distSum = getSum(A[i], countOnes, i);
        sum += distSum;
        markCountOnes(A[i], countOnes);
    }
    return sum;
}
int hammingDistance(int n1, int n2)
{
    int n = n1 ^ n2;
    int cnt = 0;
    while (n) {
        cnt++;
        n &= n-1;
    }
    return cnt;
}
int main(int argc, _TCHAR* argv[])
{
	int A[] = {0, 1, 2 , 3, 4, 5};
	int ret = hammingSum(A, sizeof(A)/sizeof(int));
	int sum = 0, n = sizeof(A)/sizeof(int);
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			sum += hammingDistance(A[i], A[j]);
		}
	}
	return 0;
}
