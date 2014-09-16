#include <vector>
using namespace std;

int getIndex(char c1, char c2) {
    if ((c1 == '1' || c1 == '2') && (c2 >= '0' && c2 <= '6')) {
        return (c1-'0')*10 + c2-'0';
    }
    else return -1;
}

vector<string> translate(string s, int start) {
    vector<string> ret;
    int len = s.length();
    if (start >= len) return ret;
    if (s[start] > '9' || s[start] < '1') return ret;
    char ch = s[start]-'1'+'A';
	if (start+1 < len)
	{
		vector<string> subs = translate(s, start+1);
		for (int i = 0; i < subs.size(); i++) {
			subs[i].insert(subs[i].begin(), 1, ch);
			ret.push_back(subs[i]);
		}
	}
	else {
		string str(1, ch);
		ret.push_back(str);
		return ret;
	}
    if (start+1 < len) {
        int alphaIndex = getIndex(s[start], s[start+1]);
        if (alphaIndex >= 1 && alphaIndex <= 26) {
            char ch = 'A'+ alphaIndex -1;
			if (start+2 < len)
			{
				vector<string> subs = translate(s, start+2);
				for (int i = 0; i < subs.size(); i++) {
					subs[i].insert(subs[i].begin(), 1, ch);
					ret.push_back(subs[i]);
				}
			}
			else {
				string str(1, ch);
				ret.push_back(str);
			}
        }
    }
    return ret;
}
int main(int argc, _TCHAR* argv[])
{
	vector<string> ret = translate("103", 0);
	return 0;
}
