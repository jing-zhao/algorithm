int findInfluencer(vector<vector<bool>>& followMatrix)
{
    int n = followMatrix.size();
    if (n <= 0) return -1;
    int curId = 0;
    while (curId < n-1) {
        int i = curId+1;
        for (; i < n; i++) {
            if (followMatrix[curId][i]) {
                curId = i;
                break;
            }
        }
        if (i == n) break;
    }
    for (int i = 0; i < n; i++) {
        if (i != curId && !followMatrix[i][curId]) return -1;
        if (i != curId && followMatrix[curId][i]) return -1;
    }
    return curId;
}
