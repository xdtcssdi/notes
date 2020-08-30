#include <iostream>
#include <algorithm>

using namespace std;
//abcd 4
//ac   2
int caches[100][100];
int f1(char* s1, char* s2, int len1, int len2, int i,int j) {
	
	if(i == len1 || j == len2){
		return 0;
	}
	if(caches[i][j] > -1){
		return caches[i][j];
	}
	
	if (s1[i] == s2[j]){
		caches[i+1][j+1] = f1(s1, s2, len1, len2, i+1, j+1) + 1;
		return caches[i+1][j+1]; 
	}
	
	caches[i+1][j] = f1(s1, s2, len1, len2, i+1, j);   
	caches[i][j+1] = f1(s1, s2, len1, len2, i, j+1);

	return max(caches[i+1][j], caches[i][j+1]);
}

int f2(char* s1, char* s2, int len1, int len2) {

	int res = 0;
	for (int i = 1; i <= len1; ++i){
		for (int j = 1; j <= len2; ++j) {
			if (s1[i-1] == s2[j-1]){
				caches[i][j] = caches[i-1][j-1] + 1;
			}else{
				caches[i][j] = max(caches[i-1][j], caches[i][j-1]);
			}
		}
	}
	return caches[len1][len2];
}

int main(int argc, char *argv[]) {
	char s1[100];
	scanf("%s",s1);
	char s2[100];
	scanf("%s",s2);
	
	memset(caches, -1, 100 *100* 4);
	
	int len1 =strlen(s1);
	int len2 =strlen(s2);
	
	cout << f1(s1, s2, len1, len2, 0, 0) << endl;
	memset(caches, 0, 100 *100* 4);
	cout << f2(s1, s2, len1, len2) << endl;
}