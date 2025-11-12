#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define pb push_back
using namespace std;
const int Maxm = 1e6 + 10, Maxn = 1e4 + 10;
struct Edge{
    int u, v, w;
}e[Maxm];
int fa[Maxn];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int c[Maxn];
int a[11][Maxn];
PII ak[11][Maxn];
int nw[Maxm];
Edge ne[Maxm + 10 * Maxn + 10];
set<int> s;
int is[Maxn], f[Maxn];
void work(){
    int n, m, k;
    cin >> n >> m >> k;
    int u, v, w;
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    int fl = 1;
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        if(c[i] != 0) fl = 0;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            ak[i][j] = {a[i][j], j};
        }
        sort(ak[i] + 1, ak[i] + 1 + n);
    }
    int M = (1 << k);
    int ans = 1e18;
    if(fl){
        int i = M - 1;
        for(int j = 1; j <= n + k; j++) fa[j] = j;
        for(int j = 1; j <= m; j++) ne[j] = e[j];
        int cnt = m;
        int res = 0;
        int gs = 0;
        for(int j = 0; j < k; j++){
            if((i >> j) & 1){
                res += c[j + 1];
                gs++;
                for(int l = 1; l <= n; l++)
                    ne[++cnt] = {j + n + 1, l, a[j+1][l]};
            }
        }
        sort(ne + 1, ne + 1 + cnt, [](Edge a, Edge b){return a.w < b.w;});
        int p = 0;
        for(int j = 1; j <= cnt; j++){
            int fu = find(ne[j].u), fv = find(ne[j].v);
            if(fu != fv){
                fa[fu] = fv;
                res += ne[j].w;
                p++;
            }
            if(p == n + gs - 1){
                break;
            }
        }
        cout << res << endl;
        return ;
    }
    for(int i = 0; i < M; i++){
        for(int j = 1; j <= n + k; j++) fa[j] = j;
        for(int j = 1; j <= m; j++) ne[j] = e[j];
        int cnt = m;
        int res = 0;
        int gs = 0;
        for(int j = 0; j < k; j++){
            if((i >> j) & 1){
                res += c[j + 1];
                gs++;
                for(int l = 1; l <= n; l++)
                    ne[++cnt] = {j + n + 1, l, a[j+1][l]};
            }
        }
        sort(ne + 1, ne + 1 + cnt, [](Edge a, Edge b){return a.w < b.w;});
        int p = 0;
        for(int j = 1; j <= cnt; j++){
            int fu = find(ne[j].u), fv = find(ne[j].v);
            if(fu != fv){
                fa[fu] = fv;
                res += ne[j].w;
                p++;
            }
            if(p == n + gs - 1){
                break;
            }
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        work();
    }
}
/*

我要发动 名为『死亡回溯』的魔法 来解决这道题。

*/