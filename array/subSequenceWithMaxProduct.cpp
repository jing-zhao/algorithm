int maxProduct(int A[], int n) {
    int maxProd = INT_MIN, cur = 1, negIndex = -1;
    if (n <= 0) return maxProd;
    for (int i = 0; i < n; i++) {
        cur *= A[i];
        maxProd = max(maxProd, cur);
        if (cur < 0) {
            if (A[i] < 0) negIndex = i;
        }
        else if (cur == 0) {
            if (negIndex != -1 && negIndex < cur-1) {
                int prod = 1, index = negIndex+1;
                while (index < cur) prod *= A[index++];
                maxProd = max(maxProd, prod);
            }
            negIndex = -1;
            cur = 1;
        }
        else {
            negIndex = -1;
        }
    }
    if (negIndex != -1 && negIndex < n-1) {
        int index = negIndex+1, prod = 1;
        while (index < n) prod *= A[index++];
        maxProd = max(maxProd, prod);
    }
    return maxProd;
}
