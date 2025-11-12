#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N=5e3+10, P=998244353;
int f[2][N<<1], n, m, ans;
int a[N];

void amod(int& a, int b) {
    a+=b; if(a>=P) a-=P;
}

signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n;
    rep(i, 1, n) cin>>a[i];
    sort(a+1, a+n+1); m=a[n]<<1|1;
    f[0][0]=1;
    rep(i, 1, n) {
        rep(j, 0, m) f[i&1][j]=f[i&1^1][j];
        rep(j, 0, m) {
            int to=min(m, j+a[i]);
            amod(f[i&1][to], f[i&1^1][j]);
            if(to>(a[i]<<1)) amod(ans, f[i&1^1][j]);
        }
    } cout<<ans<<'\n';
    return 0;
}