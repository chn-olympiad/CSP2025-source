#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5,mod=998244353;
int n,m,dp[1<<18][19],a[N];
char s[N];
bool check(){
    for(int i=0;i<n;i++)if(s[i]=='0')return 0;
    for(int i=0;i<n;i++)if(a[i]=='0')return 0;
    return 1;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==n){
        int ans=check();
        for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
        cout<<ans<<'\n';
        return 0;
    }
    dp[0][0]=1;
    for(int i=0;i<1<<n;i++){
        int c=__builtin_popcount(i);
        for(int j=0;j<=c;j++){
            for(int k=0;k<n;k++){
                if((i>>k)&1)continue;
                if(s[c]=='0'||j>=a[k]){
                    dp[i^(1<<k)][j+1]+=dp[i][j];
                    if(dp[i^(1<<k)][j+1]>=mod)dp[i^(1<k)][j+1]-=mod;
                }
                else{
                    dp[i^(1<<k)][j]+=dp[i][j];
                    if(dp[i^(1<<k)][j]>=mod)dp[i^(1<k)][j]-=mod;
                }
            }
        }
        // for(int j=0;j<=c;j++)cout<<dp[i][j]<<' ';cout<<'\n';
    }
    int ans=0;
    for(int i=m;i<=n;i++){
        ans+=dp[(1<<n)-1][n-i];
        if(ans>=mod)ans-=mod;
    }
    cout<<ans<<'\n';
    return 0;
}