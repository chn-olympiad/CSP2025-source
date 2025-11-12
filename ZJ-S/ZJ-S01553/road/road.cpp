#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, ans;
int fa[10005];
bool f;
int c[20];
struct node{
    int u, v, w;
}e[1100006];
vector<pair<int, int> >g[20];

bool cmp(node a, node b){
    return a.w < b.w;
}

int find(int x){
    if(x == fa[x]) return fa[x];
    else fa[x] = find(fa[x]);
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    f = 0;
    ans = 0;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i]. v >> e[i].w;
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        if(c[i] != 0) f = 1;
        for(int j = 1;j <= n;j++){
            int x;
            cin >> x;
            g[i].push_back({j, x});
        }
    }
    if(f == 0){
        for(int i = 1;i <= k;i++){
            for(int j = 1;j <= n;j++){
                e[m + (i - 1)*n + j].u = n + i;
                e[m + (i - 1)*n + j].v = g[i][j - 1].first;
                e[m + (i - 1)*n + j].w = g[i][j - 1].second;
            }
        }
        sort(e + 1, e + m + k * n, cmp);
        for(int i = 1;i <= n + k;i++) fa[i] = i;
        int cnt = 0;
        for(int i = 1;i <= m + k * n;i++){
            int xx = find(e[i].u);
            int yy = find(e[i].v);
            
            if(xx != yy){
                // cout<<e[i].u<<' '<<e[i].v<<' '<<xx<<' '<<yy<<'\n';
                cnt++;
                ans += e[i].w;
                fa[xx] = yy;
                fa[e[i].u] = find(e[i].v);
            }
            if(cnt >= n + k - 1) break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}