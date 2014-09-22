bool isomorphic(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    char charMap[256];
	memset(charMap, 0, 256);
    for (int i = 0; i < s1.length(); i++) {
        char ch = s1[i];
        if (!charMap[ch]) {
            charMap[ch] = s2[i];
        }
        else {
            if (charMap[ch] != s2[i]) return false;
        }
    }
    return true;
}
