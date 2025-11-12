#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1E6 + 5;
int n,a[N],fa[N],m,k,c,u,v,w,vis[N],f[11][N],co[N]; vector<tuple<int,int,int,int,int>> g;
int fd(int x){return x == fa[x] ? x : fa[x] = fd(fa[x]);}
bool mg(int u,int v){
    if(u = fd(u),v = fd(v),u == v) return 0;
    return fa[u] = v,1;
}int main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    iota(fa+1,fa+n+k+1,1);
    vector<tuple<int,int,int>> g,rg;
    for(int i = 1;i <= m;i ++) cin >> u >> v >> w,g.emplace_back(w,u,v);
    for(int i = 1;i <= k;i ++){
        cin >> co[i];
        for(int j = 1;j <= n;j ++) cin >> f[i][j];
    }ll ans = 0;
    sort(g.begin(),g.end());
    for(auto [w,u,v] : g) if(mg(u,v)) ans += w,rg.emplace_back(w,u,v);
    g = rg;
    // for(auto [w,u,v] : g) cerr << w << " " << u << " " << v << "\n";
    for(int i = 0;i < (1 << k);i ++){
        ll c = 0; vector<tuple<int,int,int>> gr,rg;
        iota(fa+1,fa+n+k+1,1);
        for(int j = 1;j <= k;j ++) if((i >> (j - 1)) & 1){
            c += co[j];
            for(int k = 1;k <= n;k ++) rg.emplace_back(f[j][k],j+n,k);
        }sort(rg.begin(),rg.end());
        gr.resize(rg.size() + g.size());
        merge(g.begin(),g.end(),rg.begin(),rg.end(),gr.begin());
        for(auto [w,u,v] : gr) if(mg(u,v)) c += w;
        ans = min(ans,c);
    }cout << ans << "\n";
    // return 0;
    // for(int i = 1;i <= m;i ++) cin >> u >> v >> w,g.emplace_back(w,u,v,0,0);
    // for(int i = 1;i <= k;i ++){
    //     cin >> c;
    //     for(int j = 1;j <= n;j ++) cin >> w,g.emplace_back(w + c,u,v,i,c);
    // }sort(g.begin(),g.end());
    // ll as = 0;
    // for(int i = 1;i <= k;i ++){
    //     for(auto [w,u,v,id,c] : g){
    //         if(mg(u,v)){
    //             as += w;
    //             if(id && !vis[id]){
    //                 vis[id] = 1;
    //                 for(auto &[w,u,v,iid,c] : g) if(iid == id) w -= c;
    //                 sort(g.begin(),g.end());
    //                 break;
    //             }
    //         }
    //     }
    // }
    // cout << as << "\n";
}
