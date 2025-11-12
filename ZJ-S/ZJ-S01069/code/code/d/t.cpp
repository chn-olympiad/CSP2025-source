#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); ++i)
#define per(i, j, k) for(int i=(j); i>=(k); --i)
using namespace std;
namespace DEBUG{
  template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
  template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d || *s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<",";
    _debug(s+1, nxt...);
  } 
  template<class T> ostream& operator<<(ostream &c, vector<T> v){
    c<<'[';
    for(auto x:v) c<<x<<", ";
    c<<']';
    return c;
  }
  #define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
} using namespace DEBUG;
const int N=503, mod=998244353;
int n, m, c[N], f[N][N], g[N][N], fac[N];
char s[N];

void pls(int &a, long long b){
  a=(a+b)%mod;
}

signed main(){
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  fac[0]=1;
  rep(i, 1, n) fac[i]=1ll*fac[i-1]*i%mod;
  rep(i, 1, n) cin>>s[i];
  rep(i, 1, n){
    int x; cin>>x;
    c[x]++;
  }
  rep(i, 1, n) c[i]+=c[i-1];
  f[0][0]=1;
  rep(i, 1, n){
    memcpy(g, f, sizeof g);
    memset(f, 0, sizeof f); 
    if(s[i]=='1'){
      rep(j, 0, i-1) rep(k, 0, i-1){
          //1. a(i)<=j, taotai
          pls(f[j+1][k+1], 1ll*g[j][k]*(c[j]-k));
          //2. a(i)>j, butaotai
          pls(f[j][k+1], -1ll*g[j][k]*(c[j]-k));
          pls(f[j][k], 1ll*g[j][k]);
        }
    } else{
      rep(j, 0, i-1) rep(k, 0, i-1){
        pls(f[j+1][k], g[j][k]);
      }
    }
  }
  int ans=0;
  rep(j, 0, n-m) rep(k, 0, n){
    pls(ans, 1ll*f[j][k]*fac[n-k]);
  }
  ans=(ans%mod+mod)%mod;
  cout<<ans;
}