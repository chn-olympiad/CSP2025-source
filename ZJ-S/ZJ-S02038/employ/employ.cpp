#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int dp[1<<18][20],c[N],fact[N];
inline void add(int& x,int y){
    x+=y;
    if(x>=mod) x-=mod;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fact[0]=1;
    for(int i=1;i<N;++i) fact[i]=1ll*fact[i-1]*i%mod;
    int n,m;
    string s;
    cin >> n >> m >> s;
    for(int i=0;i<n;++i) cin >> c[i];
    if(n<=18){//1-5
        dp[0][0]=1;
        for(int S=0;S<(1<<n);++S){
            for(int j=0;j<=n;++j){
                for(int i=0;i<n;++i){
                    if((S>>i)&1) continue;
                    add(dp[S|(1<<i)][j+(j>=c[i] || s[__builtin_popcount(S)]=='0')],dp[S][j]);
                }
            }
        }
        int ans=0;
        for(int j=0;j<=n-m;++j) add(ans,dp[(1<<n)-1][j]);
        cout << ans << endl;
    }else if(m==1){//12-14
        sort(c,c+n);
        int pos=0,cnt=0,ans=1;
        for(int i=0;i<n;++i){
            if(s[i]=='1'){
                while(pos<n && c[pos]<=i) ++pos;
                ans=1ll*ans*(pos-cnt)%mod;
                ++cnt;
            }
        }
        cout << (fact[n]+mod-1ll*fact[n-cnt]*ans%mod)%mod << endl;
    }else if(m==n){//15
        if(find(s.begin(),s.end(),'0')!=s.end() || find(c,c+n,0)!=c+n) cout << "0\n";
        else cout << fact[n] << endl;
    }
    return 0;
}