#include <string>
#include <stack>
using namespace std;

int treeDepth(string str) {
    int len = str.length();
    if (len == 0) return -1;
    if (str == "0") return 0;    
    stack<char> st;
    int maxDep = INT_MIN, curDep = -1;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch == '(') {
            st.push(ch);
            curDep++;
            maxDep = max(maxDep, curDep);
        }
        else if (ch == '0') {
            if (st.empty()) return -1;
            st.push(ch);
        }
        else if (ch == ')') {
            if (st.empty() || st.top() != '0') return -1;
            st.pop();
            if (st.empty() || st.top() != '0') return -1;
            st.pop();
            if (st.empty() || st.top() != '(') return -1;
            st.pop();
			if (!st.empty()) st.push('0');
            curDep--;
        }
        else {
            return -1;
        }
    }
    return st.empty() ? maxDep : -1;
}

int main(int argc, _TCHAR* argv[])
{
	int d = treeDepth("((00)(0(0(00))))");
	return 0;
}
