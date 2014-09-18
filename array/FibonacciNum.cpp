void multiply(int m1[2][2], int m2[2][2]) {
    int x1 = m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0];
    int x2 = m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1];
    int x3 = m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0];
    int x4 = m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1];
    m1[0][0] = x1;
    m1[0][1] = x2;
    m1[1][0] = x3;
    m1[1][1] = x4;
}
void matrixPow(int matrix[2][2], unsigned int n) {
    if (n <= 1) return;
    matrixPow(matrix, n/2);
    multiply(matrix, matrix);
    if (n%2) {
        int m1[2][2] = {{1, 1}, {1, 0}};
        multiply(matrix, m1);
    }
}
int fab(int n) {
    if (n <=2) return 1;
    int m1[2][2] = {{1, 1}, {1, 0}};
    matrixPow(m1, n-1);
    return m1[0][0];
}

int main(int argc, _TCHAR* argv[])
{
	int n = fab(9);
	return 0;
}
