#include <iostream>
#include <algorithm>

using namespace std;

int *values;
int *weights;
int caches[4000][500];
int w;
	
int f(int n, int sw) {
	
	if ( n == -1 ){
		return 0;
	}
	if ( weights[n] > sw ){
		return 0;
	}
	if (caches[n][sw] > -1){
		return caches[n][sw];
	}
	
	caches[n][sw] = max( (values[n] + f(n - 1, sw - weights[n])), 
							f(n - 1, sw));
	return caches[n][sw];
}
int f1(int n, int sw) {
	
	for(int i=0;i<n;++i){
		for(int j=0;j<sw;++j){
			caches[n][sw] = max( (values[n] + f[n - 1][sw - weights[n]]), f[n - 1, sw]);
		}
	}
}
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	cin >> w;
	values = new int[n];
	weights = new int[n];
	for(int i=0;i < n;++i) {
		cin >> weights[i];
		cin >> values[i];
	}
	memset(caches, -1, 4000 * 500 * sizeof(int));
	cout << f(n - 1, w) <<endl;
	delete values;
	delete weights;
}