#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
struct edge{
    int u, v, w;
}e[1000005], f[20050];
bool cmp(edge x, edge y){
    return x.w < y.w;
}
int fa[10050];
int find(int x){
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
int c[15];
int a[15][10050];
vector<edge> vec[1<<10], g[15];
int lowbit(int x){
    return x & -x;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)fa[i] = i;
    for(int i = 1; i <= m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++)cin >> a[i][j], g[i].emplace_back(edge{i+n, j, a[i][j]});
        sort(g[i].begin(), g[i].end(), cmp);
    }
    sort(e+1, e+1+m, cmp);
    int ans = 0;
    for(int i = 1; i <= m; i++){
        int x = find(e[i].u), y = find(e[i].v);
        if(x == y)continue;
        fa[x] = y;
        vec[0].emplace_back(e[i]);
        ans += e[i].w;
    }
    for(int i = 1; i < 1<<k; i++){
        int tot = 0;
        int z0 = 0, z1 = 0;
        int p1 = i^lowbit(i), p2 = __lg(lowbit(i))+1;
        while(z0 < vec[p1].size() && z1 < g[p2].size()){
            if(cmp(vec[p1][z0], g[p2][z1])){
                f[++tot] = vec[p1][z0++];
            }else{
                f[++tot] = g[p2][z1++];
            }
        }
        while(z0 < vec[p1].size())f[++tot] = vec[p1][z0++];
        while(z1 < g[p2].size())f[++tot] = g[p2][z1++];
        for(int j = 1; j <= n+k; j++)fa[j] = j;
        int cost = 0;
        for(int j = 1; j <= k; j++){
            if(i>>j-1&1)cost += c[j];
        }
        for(int j = 1; j <= tot; j++){
            auto [u, v, w] = f[j];
            int x = find(u), y = find(v);
            if(x == y)continue;
            fa[x] = y;
            vec[i].emplace_back(edge{u, v, w});
            cost += w;
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}