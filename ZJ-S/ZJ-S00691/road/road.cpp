#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+15;
const int M=1e6+15;
struct E{int t,nxt,w;}e[M*2];
struct node{int u,v,w;}ed[M*2],ed0[M];
int cnted,cnted0;
bool cmp(node a, node b) { return a.w < b.w; }
int h[N], cnte;
void add(int u,int v,int w){
    e[++cnte].t=v;
    e[cnte].nxt=h[u];
    e[cnte].w = w;
    h[u] = cnte;
}
int hs[N], cntes;
int n, m, k;
int a[11][N];
int fa[N], ans = 1e9;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x] = find(fa[x]);
}
void work(int x){
    for(int i=1;i<=n;i++)
        ed[++cnted] = {x, i, a[x-n][i]};
}
void solve(int x){
    cnted = cnted0;
    for (int i = 1; i <= cnted;i++)
        ed[i] = ed0[i];
    int res = 0;
    for (int i = 1; i <= n+k;i++)
        fa[i] = i;
    for (int i = 0; i < k; i++)
        if ((x >> i) & 1){
            work(i+1+n), res += a[i+1][0];
            if(res>ans) return;
        }
    sort(ed + 1, ed + 1 + cnted, cmp);
    for (int i = 1; i <= cnted; i++)
    {
        int u = ed[i].u, v = ed[i].v, w = ed[i].w;
        int fu = find(ed[i].u), fv = find(ed[i].v);
        if(fu==fv) continue;
        res += w;
        if(res>=ans) return ;
        fa[fu] = fv;
    }
    // cout << res << '\n';
    ans = min(ans, res);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1,u,v,w;i<=m;i++){
        cin >> u >> v >> w;
        // add(u, v, w), add(v, u, w);
        ed0[++cnted0] = {u, v, w};
    }
    int fl = 1;
    for(int i=1;i<=k;i++){
        for (int j = 0; j <= n;j++){
            cin >> a[i][j];
            if (a[i][j]!=0)
                fl = 0;
        }
            
        // a[i][i] = 0;
    }
    if(k&&fl){
        return cout << 0, 0;
    }
    for (int i = 0; i < (1 << k); i++)
        solve(i);
    cout << ans;
    return 0;
}
/*

*/
