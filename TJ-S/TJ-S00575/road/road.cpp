#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, m, k;
vector<vector<pair<ll,ll>>> t(10100);
vector<pair<ll,pair<ll,ll>>> E;
ll c[20], a[20][10100];

struct Dsu {
    void init(ll len) {
        f.resize(len + 10);
        sz.resize(len + 10);
        for (int i = 1; i <= len; i++)
        {
            f[i] = i;
            sz[i] = 1;
        }
    }
    ll find(ll x) {
        if (f[x] == x) return x;
        f[x] = find(f[x]);
        return f[x];
    }
    void u(ll x, ll y)
    {
        ll fx = find(x), fy = find(y);
        if (fx != fy) {
            if (sz[fx] > sz[fy]) swap(fx, fy);
            f[fx] = fy;
            sz[fy] += sz[fx];
        }
    }
    vector<ll>f, sz;
};

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        scanf("%ld%ld%ld", &u, &v, &w);
        t[u].push_back({v, w});
        t[v].push_back({u, w});
        E.push_back({w, {u,v}});
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            E.push_back({a[i][j], {j,n+i}});
        }
    }
    sort(E.begin(), E.end());
    /*
    if (k == 0 || m <= 200000) {
        ll ans = 1e18;
        for (ll x = 0; x < (1 << k); x++) {
            vector<vector<pair<ll,ll>>> G = t;
            ll sum = 0;
            for (int j = 1; j <= k; j++) {
                if ((x >> (j - 1)) & 1) {
                    sum += c[j];
                    for (int i = 1; i <= n; i++) {
                        G[i].push_back({n + j, a[j][i]});
                        G[n + j].push_back({i, a[j][i]});
                    }
                }
            }
            ll sz = n;
            vector<ll> f(n + 10);
            priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
            pq.push({0,1});
            while (!pq.empty() && sz) {
                ll p = pq.top().second;
                if (f[p]) {
                    pq.pop();
                    continue;
                }
                sum += pq.top().first;
                pq.pop();
                f[p] = 1;
                if (p <= n) sz--;
                if (!sz) break;
                for (auto i : G[p]) {
                    if (!f[i.first]) {
                        pq.push({i.second, i.first});
                    }
                }
            }
            ans = min(ans, sum);
        }
        cout << ans << "\n";
    }
    else */if (k <= 5) {
        ll ans = 1e18;
        for (ll x = 0; x < (1 << k); x++) {
            ll sum = 0;
            for (int j= 1; j <= k; j++)
            if ((x >> (j - 1)) & 1) {
                sum += c[j];
            }
            Dsu d;
            d.init(n + k);
            ll sz = n - 1;
            for (auto i : E) {
                    if (!sz) break;
                if (i.second.second > n && !((x >> (i.second.second - n - 1)) & 1)) continue;
                ll g = i.first;
                ll _0 = i.second.first, _1 = i.second.second;
                if (d.find(_0) != d.find(_1)) {
                    d.u(_0, _1);
                    sum += g;
                    if (_1 <= n) sz--;
                }
            }
            ans = min(ans, sum);
        }

        cout << ans << "\n";
    }
    return 0;
}
