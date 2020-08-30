#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n,int *nums){
	if (n < 0) {
		return 0;
	}
	return max(nums[n]+solve(n-2, nums)
			, solve(n-1, nums));
}
int main(){
	int arr[4] = {1,2,3,5};
	int ret = solve(3, arr);
	cout << ret;
}