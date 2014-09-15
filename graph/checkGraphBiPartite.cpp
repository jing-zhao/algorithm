#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

bool isBiPartite(vector<vector<int>>& edges)
{
    unordered_map<int, int> vIdToColor;
    queue<int> q;
    for (int i = 0; i < edges.size(); i++) {
        if (vIdToColor.find(i) != vIdToColor.end()) continue;
        vIdToColor[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int vId = q.front();
            q.pop();
            for (int j = 0; j < edges[vId].size(); j++) {
                if (vIdToColor.find(edges[vId][j]) == vIdToColor.end()) {
                    vIdToColor[edges[vId][j]] = vIdToColor[vId] ^1;
                    q.push(edges[vId][j]);
                }
                else if (vIdToColor[edges[vId][j]] ^ vIdToColor[vId] == 0) return false;
            }
        }
    }
    return true;
}

vector<int> getVector(int A[], int len)
{
	vector<int> ret;
	for (int i = 0; i < len; i++) ret.push_back(A[i]);
	return ret;
}

int main(int argc, _TCHAR* argv[])
{
	/*vector<vector<int>> edges;
	int r0[] = {1, 3};
	vector<int> v0 = getVector(r0, sizeof(r0)/sizeof(int));
	edges.push_back(v0);
	int r1[] = {2};
	vector<int> v1 = getVector(r1, sizeof(r1)/sizeof(int));
	edges.push_back(v1);
	int r2[] = {3};
	vector<int> v2 = getVector(r2, sizeof(r2)/sizeof(int));
	edges.push_back(v2);
	int r3[] = {0};
	vector<int> v3 = getVector(r3, sizeof(r3)/sizeof(int));
	edges.push_back(v3);*/
	vector<vector<int>> edges;
	int r0[] = {1, 4};
	vector<int> v0 = getVector(r0, sizeof(r0)/sizeof(int));
	edges.push_back(v0);
	int r1[] = {2};
	vector<int> v1 = getVector(r1, sizeof(r1)/sizeof(int));
	edges.push_back(v1);
	int r2[] = {3};
	vector<int> v2 = getVector(r2, sizeof(r2)/sizeof(int));
	edges.push_back(v2);
	int r3[] = {4};
	vector<int> v3 = getVector(r3, sizeof(r3)/sizeof(int));
	edges.push_back(v3);
	int r4[] = {0};
	vector<int> v4 = getVector(r4, sizeof(r4)/sizeof(int));
	edges.push_back(v4);
	bool ret = isBiPartite(edges);
	return 0;
}
