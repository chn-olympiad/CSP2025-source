#include<bits/stdc++.h>
int mod=998244353;
using namespace std;
int dp[5010][5010];
int n;
int a[5010];
int mi(int x){

    int ans=1;
    for(int i=1;i<=x;i++){
        ans*=2;
        ans%=mod;
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[n];j++){
            if(a[i]>j){
                dp[i][j]=(dp[i-1][j]+mi(i-1))%mod;
            }
            else{
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
            }

        }
    }
    int sum=0;
    for(int i=3;i<=n;i++){
        sum=(sum+dp[i-1][a[i]])%mod;
    }
    cout<<sum;
    return 0;
}
