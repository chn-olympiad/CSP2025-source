#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;

const int N=5e5+10;
int t[(1<<20)+10];
int s[N], n, f, k;


signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    rep(i, 1, n) cin>>s[i];
    rep(i, 1, n) s[i]^=s[i-1];
    rep(i, 0, (1<<20)-1) t[i]=-1;
    rep(i, 0, n) {
        f=max(f, t[s[i]]+1);
        t[s[i]^k]=f;
    }
  //  cerr<<'\n';
    cout<<f<<'\n';
    return 0;
}