#include<bits/stdc++.h>
#define N 200005
#define M 2000005
#define K 15
using namespace std;

int n, m, k, c[K], a[K][N];

struct Edge {
    int u, v, w;
    inline bool operator<(const Edge &b) const {
        return w<b.w;
    }
} edg[M], tmp[M];

struct DisjointSetUnion {
    int par[N], siz[N];
    inline void reset(int n) {
        for(int i=1; i<=n; ++i)
            par[i]=i, siz[i]=1;
    }
    int find(int u) {
        if(par[u]==u) return u;
        return par[u]=find(par[u]);
    }
} dsu;

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    bool flag=1;
    for(int i=1; i<=m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[i]={u, v, w};
    }
    for(int i=1; i<=k; ++i) {
        cin >> c[i];
        for(int j=1; j<=n; ++j)
            cin >> a[i][j];
        if(c[i]) flag=0;
    }
    long long rsl=1e18;
    int rec[2]={n, m};

    for(int s=(1<<k)-1; s>=0; --s) {
        if(!flag && k>5 && __builtin_popcount(s)>3) continue;
        n=rec[0], m=rec[1];
        for(int i=1; i<=m; ++i)
            tmp[i]=edg[i];
        long long ans=0;
        for(int i=0; i<k; ++i) {
            if(!((s>>i)&1)) continue;
            ans+=c[i+1], ++n;
            for(int j=1; j<=rec[0]; ++j)
                tmp[++m]={j, n, a[i+1][j]};
        }

        sort(tmp+1, tmp+m+1);
        dsu.reset(n);

        for(int i=1; i<=m; ++i) {
            int u=tmp[i].u;
            int v=tmp[i].v;
            int w=tmp[i].w;
            int fu=dsu.find(u), fv=dsu.find(v);
            if(fu==fv) continue;
            if(dsu.siz[fu]>dsu.siz[fv]) swap(fu, fv);
            dsu.par[fu]=fv, dsu.siz[fv]+=dsu.siz[fu];
            ans+=w;
            if(ans>=rsl) break;
        }
        rsl=min(rsl, ans);
        if(flag) break;
    }

    cout << rsl << '\n';
    return 0;
}