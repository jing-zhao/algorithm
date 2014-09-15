int getInfluencer(vector<vector<bool>>& followMatrix)
{
    int n = followMatrix.size();
    if (n == 0) return -1;
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j != i && !followMatrix[j][i]) break;
        }
        if (j == n) break;
    }
    if (i == n) return -1;
    for (j = 0; j < n; j++) {
        if (followMatrix[i][j]) return -1;
    }
    return i;
}
