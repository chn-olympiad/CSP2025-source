#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, pii> plpii;
const int MAXN = 1e4+55;

int fa[MAXN];
int n, m, k;
ll a[15][MAXN], c[15];
ll ans;
ll res = 0x3f3f3f3f3f3f3f3f;
vector<pil> e[MAXN];
ll minw[15];
ll maxww;
bool adde = true;

inline int Find(int x) { return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]); }

inline void merge(int x, int y)
{
    x = Find(x), y = Find(y);
    if(x == y) return;
    fa[x] = y;
}

priority_queue<plpii, vector<plpii>, greater<plpii> > q;
inline void zdl()
{
    for(; !q.empty(); )
    {
        plpii cur = q.top(); q.pop();
        int u = cur.second.first, v = cur.second.second;
        ll w = cur.first;
        if(Find(u) == Find(v)) continue;
        merge(u, v);
        if(adde) e[u].emplace_back(pil(v, w)); // , cout<<u<<' '<<v<<endl;
        // e[v].emplace_back(pil(u, w));
        ans += w;
    }
}

inline void solve1()
{
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++) q.emplace(plpii(a[i][j], pii(i+n, j)));
    }
    zdl();
    printf("%lld\n", ans);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(minw, 0x3f, sizeof minw);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n+15; i++) fa[i] = i;
    for(int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        // e[u].emplace_back(pil(v, (ll)w));
        // e[v].emplace_back(pil(u, (ll)w));
        q.emplace(plpii((ll) w, pii(u, v)));
    }
    for(int i = 1; i <= k; i++)
    {
        scanf("%lld", &c[i]);
        minw[0] = min(minw[0], c[i]);
        for(int j = 1; j <= n; j++) scanf("%lld", &a[i][j]), minw[i] = min(minw[i], a[i][j]);
        maxww = max(maxww, minw[i]);
        //, q.emplace(plpii(a[i][j], pii(i+n, j)));
    }
    if(minw[0] == 0 && maxww == 0)
    {
        solve1();
        return 0;
    }
    zdl(); adde = false;
    res = min(res, ans);
    for(int s = 1; s < (1<<k); s++)
    {
        for(int i = 1; i <= n+15; i++) fa[i] = i;
        ans = 0;

        for(int u = 1; u <= n; u++)
        {
            for(int i = 0; i < (int)e[u].size(); i++)
            {
                int v = e[u][i].first; ll w = e[u][i].second;
                q.emplace(plpii(w, pii(u, v)));
            }
        }
        for(int i = 1; i <= k; i++)
        {
            if(!(s & (1<<(i-1)))) continue;
            for(int j = 1; j <= n; j++) q.emplace(plpii(a[i][j], pii(i+n, j)));
            ans += c[i];
        }
        zdl();
        res = min(res, ans);
    }
    printf("%lld\n", res);

    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 100 100 100
0 0 100 100 100
*/