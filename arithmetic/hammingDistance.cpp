int hammingDistance(int n1, int n2)
{
    int n = n1 ^ n2;
    int cnt = 0;
    while (n) {
        cnt++;
        n &= n-1;
    }
    return n;
}
