#include <bits/stdc++.h>

#define N 10004

using namespace std;

typedef long long ll;

// 变量定义
ll n, m, k;

ll ans = LONG_LONG_MAX;
ll qwq = 0;
ll cnt = 0;
ll need_go;
ll c[N];

struct edge {
    ll to;
    ll value;
    ll build_v;
    ll ind;
};
vector<edge> edges[N];

struct edge2 {
    ll from;
    ll to;
    ll value;
    ll build_v;
};
vector<edge2> edges2;

bool visited[N], built[N * 2 + 10], citied[N];
bool ungo[N];
bool or_city[N];

void dfs(ll now, ll now_ans, ll now_cnt, ll or_cnt) {
    // cout << "dfs(" << now << ", " << now_ans << ", " << now_cnt << ", " << or_cnt << ")" << endl;
    if (built[now]) return ;
    built[now] = 1;

    now_ans += edges2[now].value;

    if (or_cnt == n) {
        ans = min(ans, now_ans);
        return ;
    }

    for (ll i=1; i <= cnt; i++) {
        auto tmp = edges2[i];
        if (!ungo[tmp.from]) continue;

        bool o1, o2, o3;
        o1 = o2 = o3 = 0;
        ll tmp_or_cnt = or_cnt;
        ll tmp_now_ans = now_ans;
        if (!ungo[tmp.to]) {
            ungo[tmp.to] = 1;
            o3 = 1;
        }
        if (!ungo[tmp.to] && or_city[tmp.to]) {
            tmp_or_cnt++;
            ungo[tmp.to] = 1;
        }
        if (!ungo[tmp.from] && !citied[tmp.from]) {
            tmp_now_ans += c[tmp.from];
            o1 = true;
            citied[tmp.from] = 1;
        }
        if (!ungo[tmp.to] && !citied[tmp.to]) {
            tmp_now_ans += c[tmp.to];
            o2 = true;
            citied[tmp.to] = 1;
        }

        if (o1) {
            citied[tmp.from] = 0;
        }
        if (o2) {
            citied[tmp.to] = 0;
        }
        if (o3) {
            ungo[tmp.to] = 0;
        }
    }

    built[now] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("road.in", "r", stdin);
    // freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    need_go = n;

    edges2.push_back({0, 0, 0, 0});

    for (ll i=1; i <= n; i++) {
        citied[++qwq] = 1;
        or_city[qwq] = 1;
    }

    for (ll i=1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w, 0, ++cnt});
        edges[v].push_back({u, w, 0, cnt});
        edges2.push_back({u, v, w, 0});
    }
    for (ll j=1; j <= k; j++) {
        ll now_i = ++qwq;
        cin >> c[now_i];
        for (ll i=1; i <= n; i++) {
            ll a;
            cin >> a;
            edges[now_i].push_back({i, a, c[now_i], ++cnt});
            edges[i].push_back({now_i, a, c[now_i], cnt});
            edges2.push_back({i, now_i, a, c[now_i]});
        }
    }

    // for (auto j : edges[1]) {
    //     cout << j.to << " " << j.value << " " << j.build_v << " " << j.ind << endl;
    // }

    for (ll i=1; i <= qwq; i++) {
        ungo[i] = 1;
        ll now_ans = 0;
        if (!or_city[i]) {
            citied[i] = 1;
            now_ans += c[i];
        }
        dfs(i, now_ans, 0, or_city[i]);
        if (!or_city[i]) {
            citied[i] = 0;
        }
        ungo[i] = 0;
    }

    cout << ans;

    return 0;
}
