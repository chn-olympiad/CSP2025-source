#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
const int mod=998244353;
bool MBE;
int n,m;
int ans;
string s;
int c[N];
int dp[19][1<<18];
bool MED;
signed main(){
    // freopen("ex.in","r",stdin);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n==m){
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||c[i]==0){
                cout<<"0\n";
                return 0;
            }
        }
        int res=1;
        for(int i=1;i<=n;i++)res=res*i%mod;
        cout<<res<<"\n";
        return 0;
    }
    dp[0][0]=1;
    for(int S=1;S<(1<<n);S++){
        int i=__builtin_popcount(S);
        for(int j=1;j<=n;j++){
            if((S>>(j-1))&1){
                int pre=S^(1<<(j-1));
                for(int k=0;k<i;k++){
                    int cnt=i-1-k;//uemployed
                    if(s[i]=='0'||c[j]<=cnt)dp[k][S]=(dp[k][S]+dp[k][pre])%mod;
                    else dp[k+1][S]=(dp[k+1][S]+dp[k][pre])%mod;
                }
            }
        }
    }
    for(int i=m;i<=n;i++)ans=(ans+dp[i][(1<<n)-1])%mod;
    cout<<ans<<"\n";
    // cerr<<"Time : "<<1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    // cerr<<"Memory : "<<fixed<<setprecision(2)<<abs(&MBE-&MED)/1048576.0<<" MB\n";
    return 0;
}