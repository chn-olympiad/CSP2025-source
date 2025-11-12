#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N = 1.2e4 + 3;
int n, m, k;
int c[N];

struct Edge{
    int u, v, w;
};
vector<Edge> s, tmp;

// bool used[]

namespace ufs{
    int f[N], siz[N];
    void init(){
        for(int i = 1; i <= n + k; i++)
            f[i] = i, siz[i] = 1;
    }
    int find(int x){
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    int merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v)return 0;
        if(siz[u] > siz[v])swap(u, v);
        f[u] = v, siz[v] += siz[u];
        return 1;
    }
}

int solve(int S){
    int cnt = 0, tgt = n + __builtin_popcount(S) - 1, res = 0;
    for(int i = 1; i <= k; i++)
        if((S >> i) & 1)res += c[i];
    ufs::init();
    for(const auto &[u, v, w]: s){
        if(u > n && (!((S >> (u - n)) & 1)))continue;
        int val = ufs::merge(u, v);
        res += val * w, cnt += val;
        if(cnt == tgt)break;
    }
    return res;
}

main(){
    freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;cin >> u >> v >> w;
        tmp.push_back({u, v, w});
    }
    sort(tmp.begin(), tmp.end(), [&](const auto &x, const auto &y){
        return x.w < y.w;
    });
    ufs::init();
    for(const auto &[u, v, w]: tmp)
        if(ufs::merge(u, v))s.push_back({u, v, w});
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int v = 1; v <= n; v++){
            int w;cin >> w;
            s.push_back({i + n, v, w});
        }
    }
    sort(s.begin(), s.end(), [&](const auto &x, const auto &y){
        return x.w < y.w;
    });
    int U = (1 << k) - 1;
    int ans = inf;
    for(int S = 0; S <= U; S++)
        ans = min(ans, solve(S));
    printf("%lld\n", ans);
}