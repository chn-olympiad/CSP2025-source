#include<bits/stdc++.h>
#define int long long
#define N 10010
using namespace std;
int head[N], nex[2 * N], edge[2 * N][2], to[2 * N], tot = 0;
int c[N], vis[15], fa[N];
struct node{
    int w, x, y, f;
}a[N * 100];
bool cmp(node a, node b){return a.w < b.w;}
int find(int x){
    if(fa[x] == x)return fa[x];
    return fa[x] = find(fa[x]);
}
void add(int x, int y, int z1, int z2){
    to[++tot] = y;
    edge[tot][0] = z1;
    edge[tot][1] = z2;
    nex[tot] = head[x];
    head[x] = tot;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w, 0);
        add(v, u, w, 0);
        a[++cnt] = {w, u, v, 0};
    }
    for(int i = 1; i <= k; i++){
        cin >> c[i + n];
        int w;
        for(int j = 1; j <= n; j++){
            cin >> w;
            add(i + n, j, w, i);
            a[++cnt] = {w + c[i + n], i + n, j, i};
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for(int i = 1; i <= n + k; i++)fa[i] = i;
    int ans = 0;
    for(int i = 1; i <= cnt; i++){
        int x = a[i].x, y = a[i].y;
        int fx = find(x), fy = find(y);
        if(fx != fy){
            fa[fx] = fy;
            ans += a[i].w - c[a[i].f + n];
            vis[a[i].f]++;
        }
    }
    for(int i = 1; i <= k; i++){
        if(vis[i] != 0)ans += c[i + n];
    }
    cout << ans;
    return 0;
}
