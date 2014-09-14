#include <vector>
using namespace std;
// There is two dimensional array where each sub array (row) is sorted, i.e.
// [1 10000 2000]
// [20 10001 5000]
// [55 10002 222222]]
// Find a minimum range contain a number from each row. For above array it should be    (10000-10002) range

vector<int> minRange(vector<vector<int>>& matrix) {
  vector<int> range;
  int row = matrix.size();
  if (row == 0) return range;
  int col = matrix[0].size();
  if (col == 0) return range;
  vector<int> indexes(row, 0);
  int minRange = INT_MAX;
  while (1) {
      int minVal = INT_MAX, minRow = 0, maxVal = INT_MIN;
      for (int i = 0; i < row; i++) {
          if (indexes[i] >= col) return range;
          if (matrix[i][indexes[i]] < minVal) {
              minVal = matrix[i][indexes[i]];
              minRow = i;
          }
          maxVal = max(maxVal, matrix[i][indexes[i]]);
      }
      if (maxVal - minVal < minRange) {
          minRange = maxVal - minVal;
          if (!range.size()) range.insert(range.end(), 2, 0);
          range[0] = minVal;
          range[1] = maxVal;
      }
      indexes[minRow]++;
  }
  return range;
}

int main(int argc, _TCHAR* argv[])
{
	vector<vector<int>> matrix;
	int r1[] = {1, 10000, 2000};
	int r2[] = {20, 10001, 5000};
	int r3[] = {55, 10002, 222222};
	vector<int> v1;
	for (int i = 0; i < sizeof(r1)/sizeof(int); i++) v1.push_back(r1[i]);
	matrix.push_back(v1);
	vector<int> v2;
	for (int i = 0; i < sizeof(r2)/sizeof(int); i++) v2.push_back(r2[i]);
	matrix.push_back(v2);
	vector<int> v3;
	for (int i = 0; i < sizeof(r3)/sizeof(int); i++) v3.push_back(r3[i]);
	matrix.push_back(v3);
	vector<int> ret = minRange(matrix);
	return 0;
}
