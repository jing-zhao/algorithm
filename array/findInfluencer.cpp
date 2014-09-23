int getInfluencer(vector<vector<bool>>& followingMatrix) {
    int n = followingMatrix.size();
    if (n == 0) return -1;
    int curId = 0;
    while (curId < n) {
        for (int i = curId+1; i < n; i++) {
            if (followingMatrix[curId][i]) break;
        }
        if (i >= n) break;
        else curId = i;
    }
    for (int i = 0; i < n; i++) {
        if (i != curId && followingMatrix[curId][i]) return -1;
        if (i != curId && !followingMatrix[i][curId]) return -1;
    }
    return curId;
}
