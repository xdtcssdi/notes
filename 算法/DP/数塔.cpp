#include <iostream>
#include <algorithm>
using namespace std;
int map[5][5] = {{13},
                {11,8},
                {12,7,26},
                {6,14,15,8},
                {12,7,13,24,11}}; 
int res[5][5];
int f(int i,int j){
    if(res[i][j]){
        return res[i][j];
    }
    if (!map[i][j]){
        return 0;
    }
    if (i>4 || j>4){
        return 0;
    }
    res[i][j] = map[i][j] + max(f(i+1,j),f(i+1,j+1));
    return res[i][j];
}
int f1(int n,int m){
    
    for(int i=0;i<=m;++i){
        res[4][i] = map[4][i];
    }
    
    for(int i=n-1;i>=0;--i)
        for(int j=0;j<=i;++j)
        {    
            res[i][j] = map[i][j] + max(res[i+1][j],res[i+1][j+1]);
        }
    return res[0][0];
}
int main()
{
    cout<<f(0,0)<<endl;
    memset(res, 0, 5*5*5);
    cout<<f1(4,4)<<endl;;

}