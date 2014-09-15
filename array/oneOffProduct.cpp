#include <vector>
using namespace std;

vector<int> oneOffProduct(vector<int>& nums)
{
    vector<int> prodsFrom(nums.size(), 0);
    vector<int> prodsTo(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) prodsTo[i] = nums[i];
        else prodsTo[i] = prodsTo[i-1]*nums[i];
    }
    for (int i = nums.size()-1; i >= 0; i--) {
        if (i == nums.size() - 1) prodsFrom[i] = nums[i];
        else prodsFrom[i] = prodsFrom[i+1]*nums[i];
    }
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++) {
        int prod = 1;
        if (i > 0) prod *= prodsTo[i-1];
        if (i < nums.size()-1) prod *= prodsFrom[i+1];
        ret.push_back(prod);
    }
    return ret;
}

vector<int> getVector(int A[], int len)
{
	vector<int> ret;
	for (int i = 0; i < len; i++) ret.push_back(A[i]);
	return ret;
}

int main(int argc, _TCHAR* argv[])
{
	// int A[] = {1, 2, 3 , 4};
	int A[] = {4};
	vector<int> nums = getVector(A, sizeof(A)/sizeof(int));
	// vector<int> nums = getVector(A, 0);
	vector<int> ret = oneOffProduct(nums);
	return 0;
}
