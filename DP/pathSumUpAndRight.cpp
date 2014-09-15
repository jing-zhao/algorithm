#include <vector>
using namespace std;

int pathSum(int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) return 0;
    if ((x1-x2)*(y1-y2) > 0) return 0;
    if (x1 == x2 || y1 == y2) return 1;
    int col = abs(y1-y2)+1, row = abs(x1-x2)+1;
    vector<int> pathCol(col, 0);
    vector<vector<int>> pathSums(row, pathCol);
    for (int i = 0; i < row; i++) pathSums[i][0] = 1;
    for (int i = 0; i < col; i++) pathSums[row-1][i] = 1;
    for (int i = row-2; i >= 0; i--) {
        for (int j = 1; j < col; j++) {
            pathSums[i][j] = pathSums[i+1][j] + pathSums[i][j-1];
        }
    }
    return pathSums[0][col-1];
}
int main(int argc, _TCHAR* argv[])
{
	// int ret = pathSum(3, 0, 0, 3);
	// int ret = pathSum(0, 3, 3, 0);
	// int ret = pathSum(1, 1, 4, 3);
	// int ret = pathSum(4, 3, 1, 1);
	// int ret = pathSum(1, 2, 1, 3);
	// int ret = pathSum(4, 3, 1, 1);
	int ret = pathSum(1, 2, 4, 2);
	return 0;
}
