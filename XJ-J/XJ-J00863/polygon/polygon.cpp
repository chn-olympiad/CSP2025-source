#include <bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int arr[MAXN],dp[MAXN][MAXN]={0};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int _max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>_max) _max=arr[i];
    }
    sort(arr,arr+n);
    int m=_max+1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // arr[j] i
            if(j==0){
                dp[i][j]=arr[j]>=i?1:0;
                continue;
            }
            dp[i][j]=dp[i][j-1];
            int index=i>arr[j]?i-arr[j]:0;
            dp[i][j]=(dp[i][j]+dp[index][j-1])%998244353;
            if(arr[j]>=i) dp[i][j]=(dp[i][j]+1)%998244353;
            // cout<<i<<","<<j<<":"<<dp[i][j]<<"\n";
        }
    }
    cout<<dp[m-1][n-2]<<"\n";
    return 0;
}