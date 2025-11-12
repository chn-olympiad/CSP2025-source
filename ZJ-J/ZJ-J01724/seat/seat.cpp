#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;

const int N=1e6+10;
int id, n, m, p, c, r;
int tot, a[N];


signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    rep(i, 1, n) rep(j, 1, m) cin>>a[++tot];
    p=a[1]; sort(a+1, a+tot+1);
    id=lower_bound(a+1, a+tot+1, p)-a;
    id=tot-id+1;
    c=(id+n-1)/n; r=(id-1)%n+1;
    cerr<<id<<'\n';
    if(c&1^1) r=n-r+1;
    cout<<c<<' '<<r<<'\n';
    return 0;
}