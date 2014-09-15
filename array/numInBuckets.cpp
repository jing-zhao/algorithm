#include <math.h>
#include <iostream>
using namespace std;
// Given an array of numbers, they are arranged so that the a[0] is in the 1st bucket, a[1]a[2] are in the 2nd bucket, a[3]a[4]a[5] is in the 3rd bucket and so on. Numbers in bucket i are greater than numbers in bucket i-1. The question is then: given a number, you need to return if it is in any bucket or not

bool exist(int A[], int len, int target)
{
    if (len <= 0) return false;
    int buckets = sqrt((double)len*2);
    int l = 0, r = buckets-1;
    while (l <= r) {
        int mid = (l+r)/2;
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 0; i <= mid; i++) {
            int val = A[mid*(mid+1)/2+i];
            if (val == target) return true;
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
        }
        if (target > minVal && target < maxVal) return false;
        else if (target < minVal) r = mid-1;
        else l = mid+1;
    }
    return false;
}

int main(int argc, _TCHAR* argv[])
{
	int A[] = {1, 2, 3, 5, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < sizeof(A)/sizeof(int); i++) {
		bool ret = exist(A, sizeof(A)/sizeof(int), A[i]);
		if (!ret) cout<<"error"<<endl;
	}
	return 0;
}
