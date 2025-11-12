#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=19,M=(1<<N),mod=998244353;
ll n,m,c[N],dp[N][M][N],ans;
string s;
vector<ll> e[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;s=" "+s;dp[0][0][0]=1;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int j=0;j<(1<<n);j++) e[__builtin_popcount(j)].push_back(j);
    for(int i=1;i<=n;i++)
        for(auto j:e[i-1])
            for(int k=1;k<=n;k++){
                if((j>>(k-1))&1) continue;
                for(int p=0;p<i;p++)
                    (dp[i][j|(1<<(k-1))][p+(s[i]=='1'&&c[k]>i-1-p)]+=dp[i-1][j][p])%=mod;
            }
    for(int p=m;p<=n;p++) (ans+=dp[n][(1<<n)-1][p])%=mod;
    cout<<ans<<"\n";
    return 0;
}