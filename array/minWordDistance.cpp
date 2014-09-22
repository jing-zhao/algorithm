int minDistance(string strs[], int n, string s1, string s2) {
    string next;
    int minDist = INT_MAX, firstIndex = -1;
    for (int i = 0; i < n; i++) {
        if (firstIndex != -1) {
            if (strs[i] == next) {
                minDist = min(minDist, i-firstIndex);
                firstIndex = i;
                next = (next == s1 ? s2 : s1);
            }
            else if (strs[i] == strs[firstIndex]) {
                firstIndex = i;
            }
        }
        else {
            if (strs[i] == s1 || strs[i] == s2) {
                firstIndex = i;
                next = strs[i] == s1 ? s2 : s1;
            }
        }
    }
    return minDist;
}

int main(int argc, _TCHAR* argv[])
{
	string strs[] = {"the", "quick", "brown", "fox", "quick", "fox"};
	// int ret = minDistance(strs, sizeof(strs)/sizeof(string), "quick", "fox");
	// int ret = minDistance(strs, sizeof(strs)/sizeof(string), "fox", "the");
	// int ret = minDistance(strs, sizeof(strs)/sizeof(string), "fox", "fox");
	// int ret = minDistance(strs, sizeof(strs)/sizeof(string), "brown", "brown");
	int ret = minDistance(strs, sizeof(strs)/sizeof(string), "brown", "quick");
	return 0;
}
