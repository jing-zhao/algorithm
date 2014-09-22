int commonCharCount(vector<string>& strs) {
    if (strs.size() == 0) return 0;
    int charCounts[256];
    memset(charCounts, 0, sizeof(int)*256);
    bool charVisted[256];
    for (int i = 0; i < strs.size(); i++) {
        memset(charVisited, 0, sizeof(int)*256);
        for (int j = 0; j < strs[i].length(); j++) {
            char ch = strs[i][j];
            if (!charVisited[ch]) {
                charVisited[ch] = true;
                charCounts[ch]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 256; i++) {
        if (charCounts[i] == strs.size()) cnt++;
    }
    return cnt;
}
