#include<bits/stdc++.h>
#define int long long
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int M=2e6+10, N=1e5+10;

struct EDGE{int x, y, z;}edge[M], b[N], t[M];

bool operator<(const EDGE& a, const EDGE& b) {return a.z<b.z;}

int fa[N], h[N];

int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
bool merge(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return 0;
    if(h[x]>h[y]) swap(x, y);
    fa[x]=y;
    h[y]=max(h[y], h[x]+1);
    return 1;
}

int n, k, m, ans, tot, all, a[11][N], c[11];

int run() {
    int ans=0;
    rep(i, 1, n+k) fa[i]=i, h[i]=1;
    sort(t+1, t+tot+1);
    rep(i, 1, tot)
        if(merge(t[i].x, t[i].y)) ans+=t[i].z;//, b[++tot]=edge[i];
    return ans;
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    rep(i, 1, m) cin>>edge[i].x>>edge[i].y>>edge[i].z;
    rep(i, 1, n+k) fa[i]=i, h[i]=1;
    sort(edge+1, edge+m+1);
    rep(i, 1, m)
        if(merge(edge[i].x, edge[i].y)) ans+=edge[i].z, b[++tot]=edge[i];
    rep(i, 1, tot) edge[i]=b[i]; m=tot; tot=0;
    rep(_, 1, k) {
        cin>>c[_];
        rep(i, 1, n) cin>>a[_][i];
    }
    rep(v, 0, (1<<k)-1) {
        int sum=0;
        rep(i, 1, m) t[++tot]=edge[i];
        rep(i, 1, k) if(v>>(i-1)&1) {
            rep(j, 1, n) t[++tot]=(EDGE){j, i+n, a[i][j]};
            sum+=c[i];
        }
        sum+=run(); tot=0;
        ans=min(ans, sum);
    }
    cout<<ans<<'\n';
    return 0;
}