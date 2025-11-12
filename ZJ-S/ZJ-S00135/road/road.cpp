#include<bits/stdc++.h>
#define int long long
#define FL(i, a, b) for(int i = (a), i##end = (b); i <= i##end; ++i)
#define FR(i, a, b) for(int i = (a), i##end = (b); i >= i##end; --i)
#define vt vector
#define eb emplace_back
using namespace std;
constexpr int N = 1e4 + 10, M = 1e6 + 10;
struct edge{int u, v, w;}e[M];
vt<edge>e1, e2;
int n, m, k, c[12], vis[12], fa[N], ans;
pair<int, int>a[12][N];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
inline void cmin(int&a, int b){if(a > b)a = b;}
void ___(){
    cin >> n >> m >> k;
    FL(i, 1, n + 1)fa[i] = i;
    FL(i, 1, m)cin >> e[i].u >> e[i].v >> e[i].w;
    FL(i, 1, k){
        cin >> c[i];
        FL(j, 1, n)cin >> a[i][j].first, a[i][j].second = j;
        sort(a[i] + 1, a[i] + 1 + n);
    }
    sort(e + 1, e + 1 + m, [](edge&a, edge&b){return a.w < b.w;});
    FL(i, 1, m){
        int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
        if(u == v)continue;
        fa[v] = u, e1.push_back(e[i]), ans += w;
        if(e1.size() == n - 1)break;
    }
    FL(S, 1, (1 << k) - 1){
        int res = 0, f = n;e2.clear();
        FL(i, 1, n + k)fa[i] = i;
        FL(i, 1, k)if((S >> i - 1) & 1){
            res += c[i], f++;
            FL(j, 1, n)if(a[i][j].first <= e1.back().w || j <= 1)
            e2.push_back({a[i][j].second, i + n, a[i][j].first});
        }
        if(res > ans)continue;
        sort(e2.begin(), e2.end(), [](edge&a, edge&b){return a.w < b.w;});
        int l = 0, r = 0, cnt = 1;
        while(l < e1.size() || r < e2.size()){
            edge a;
            if(l == e1.size())a = e2[r], r++;
            else if(r == e2.size())a = e1[l], l++;
            else if(e2[r].w < e1[l].w)a = e2[r], r++;
            else a = e1[l], l++;
            
            int u = find(a.u), v = find(a.v);
            if(u == v)continue;
            fa[v] = u, res += a.w;
            if((++cnt) == f || res > ans)break;
        }
        cmin(ans, res); 
    }
    cout << ans;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)___();
    return 0;
}