#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;

int L[9];
int map[9][9]={ {0,7,5,0,0,0,0,0,0},
				{0,0,0,5,8,7,0,0,0},
				{0,0,0,6,7,5,0,0,0},
				{0,0,0,0,0,0,3,7,0},
				{0,0,0,0,0,0,3,5,0},
				{0,0,0,0,0,0,7,8,0},
				{0,0,0,0,0,0,0,0,5},
				{0,0,0,0,0,0,0,0,2},
				{0,0,0,0,0,0,0,0,0}
			  };
int f(int v){
	if (L[v]) return L[v];
	if (v==8) return 0;
	int min =INF;
	for (int i=v+1;i<9;++i){
		if(map[v][i]){
			int temp = map[v][i] + f(i);
			if (min>temp){
				min = temp;	
			}
		}
	}
	L[v] = min;
	return L[v];
}
void f1(){
	for(int v=1;v<9;v++){
		int min =INF;
		for (int i=0;i<v;++i){
			if(map[i][v]){
				int temp = map[i][v] + L[i];
				if (min>temp){
					min = temp;	
				}
			}
		}
		L[v] = min;
	}
}
int main(){
 	f1();
	cout<<"to start:";
	for (int i=0;i<9;++i){
		cout<<" "<< L[i];
		L[i]=0;
	}
	cout<<endl;
	f(0);
	cout<<"to end:";
	for (int i=0;i<9;++i){
		cout<<" "<< L[i];
	}
}