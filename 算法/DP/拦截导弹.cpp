#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int n, m;
    cin>>n;
    while(n--){
        cin>>m;
        int arr[m];
        int dp[m];
        for(int i=0;i<m;++i)
            cin>>arr[i];
        for (int i=0;i<m;++i){
            dp[i]=1;
            for(int j=0;j<i;++j){
                if(arr[i]>arr[j])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }

        for(int i=0;i<m;++i)
            cout<< dp[i]<<" ";
    }
}