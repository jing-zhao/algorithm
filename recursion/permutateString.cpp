#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> permutate(string& str, int n, vector<bool>& visited) {
    vector<string> ret;
    if (n <= 0) return ret;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (!visited[i]) {
            if (i-1 >= 0 && !visited[i-1] && str[i-1] == str[i]) continue;
            visited[i] = true;
            if (n > 1) {
                vector<string> subs = permutate(str, n-1, visited);
                for (int j = 0; j < subs.size(); j++) {
					subs[j].push_back(str[i]);
                    ret.push_back(subs[j]);
                }
            }
            else {
                string s(1, str[i]);
                ret.push_back(s);
            }
            visited[i] = false;
        }
    }
    return ret;
}
vector<string> permutate(string str) {
    vector<string> ret;
    if (str.length() == 0) return ret;
    sort(str.begin(), str.end());
    vector<bool> visited(str.length(), 0);
    return permutate(str, str.length(), visited);
}
int main(int argc, _TCHAR* argv[])
{
	vector<string> ret = permutate("aab");
	return 0;
}
