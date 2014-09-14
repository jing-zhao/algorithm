#include <vector>
using namespace std;

//给个sorted array， 只包含不重复整数，数值范围在 ［0，99］中间， 按格式打印其余数值：
//输入： ［0，1，3，50，75］
//输出： ［2，4-49，51-74，76-99］
//请写出程序，及 testing cases

vector<vector<int>> missingRanges(int A[], int n)
{
    vector<vector<int>> ret;
    int expected = 0;
    for (int i = 0; i < n; i++) {
        if (expected < A[i]) {
            vector<int> range;
            for (int j = expected; j < A[i]; j++) range.push_back(j);
            ret.push_back(range);
        }
        expected = A[i] + 1;
        if (expected > 99) break;
    }
    if (expected <= 99) {
        vector<int> range;
        for (int i = expected; i <= 99; i++) range.push_back(i);
        ret.push_back(range);
    }
    return ret;
}

int main(int argc, _TCHAR* argv[])
{
	// int A[] = {0, 1, 3, 50, 75};
	// int A[] = {0, 1, 3, 50, 75, 99, 99, 99};
	// int A[] = {3, 50, 75, 99, 99, 99};
	// int A[] = {3, 50, 50, 75, 99, 99, 99};
	int A[] = {0};
	vector<vector<int>> ret = missingRanges(A, sizeof(A)/sizeof(int));
	// vector<vector<int>> ret = missingRanges(A, 0);
	return 0;
}
