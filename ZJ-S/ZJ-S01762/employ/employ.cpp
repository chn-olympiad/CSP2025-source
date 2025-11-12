#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N=20, P=998244353;
int f[(1<<N)][N], n, m, ans;
vector<int>t[21];

int a[N], s[N];
char c[N];

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    rep(i, 1, n) cin>>c[i];
    rep(i, 1, n) cin>>a[i];
    rep(i, 0, (1<<n)-1) t[__builtin_popcount(i)].push_back(i);
    f[0][0]=1;
    rep(i, 0, n-1) {
        rep(j, 0, n) {
            for(auto v:t[i]) {
                // cout<<v<<' ';
                rep(k, 1, n) {
                    if(v>>(k-1)&1) continue;
                    f[v|(1<<(k-1))][j+(c[i+1]=='1'&&a[k]>i-j)]=(f[v|(1<<(k-1))][j+(c[i+1]=='1'&&a[k]>i-j)]+f[v][j])%P;
                    // cerr<<v<<' '<<j<<'\n';
                    // cerr<<(v|(1<<(k-1)))<<' '<<(j+(c[i]=='1'&&a[k]>i-j))<<'\n';
                }
            }// cout<<'\n';
        }
    }
    rep(i, m, n) ans=(ans+f[(1<<n)-1][i])%P;
    cout<<ans<<'\n';
    return 0;
}