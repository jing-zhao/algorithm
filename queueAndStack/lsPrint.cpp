#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <sstream>
using namespace std;

vector<vector<string>> getSubDirs(string path)
{
	vector<vector<string>> ret;
	return ret;
}
vector<vector<string>> getSubDirs(vector<string> parts)
{
	return getSubDirs("");
}
string getPath(vector<string>& parts)
{
	return "";
}
bool isValidPath(vector<string>& parts)
{
	return true;
}
void printDir(vector<string>& parts)
{ }


void lsPrint(string& path)
{
    queue<vector<string>> q;
    unordered_set<string> visitedPaths;
    istringstream iss(path);
    string part;
    while (getline(iss, part, '/')) {
        if (part.length() == 0) continue;
        if (q.empty()) {
            if (part == "*") {
                vector<vector<string>> subDirs = getSubDirs("/");
                for (int i = 0; i < subDirs.size(); i++) q.push(subDirs[i]);
            }
            else if (part == "." || part == ".."){
                vector<string> v;
                q.push(v);
            }
            else {
                vector<string> v(1, part);
                q.push(v);
            }
        }
        else {
            if (part == ".") continue;
            visitedPaths.clear();
            for (int i = 0; i < q.size(); i++) {
                vector<string> pathVec = q.front();
                q.pop();
                if (part == "*") {
                    vector<vector<string>> subDirs = getSubDirs(pathVec);
                    for (int i = 0; i < subDirs.size(); i++) q.push(subDirs[i]);
                }
                else if (part == "..") {
                    if (pathVec.size() > 0) pathVec.pop_back();
                    string p = getPath(pathVec);
					if (visitedPaths.find(p) == visitedPaths.end()) {
                        visitedPaths.insert(p);
                        q.push(pathVec);
                    }
                }
                else {
                    pathVec.push_back(part);
                    if (isValidPath(pathVec)) q.push(pathVec);
                }
            }
            if (q.empty()) return;
        }
    }
    while (!q.empty()) {
        vector<string> pathVec = q.front();
        q.pop();
        printDir(pathVec);
    }
}
