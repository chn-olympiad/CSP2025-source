#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k;
vector<pair<int, ll> > tr[11000];
ll c[20];
ll a[10010];
ll ans;
int vis[11000];

void dfs(int u, int cnt, ll sum) {
    if (cnt == n) {
        ans = max(ans, sum);
        return ;
    }
    for (int i = 0; i < (int)tr[u].size(); i++) {
        int v = tr[u][i].first;
        int w = tr[u][i].second;
        if (!vis[v]) {
            if (v <= n) {
                vis[v] = 1;
                dfs(v, cnt + 1, sum + w);
                vis[v] = 0;
            }else {
                vis[v] = 1;
                dfs(v, cnt, sum + w);
                vis[v] = 0;
            }
        }
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int x, y;
        ll w;
        scanf("%d%d%lld", &x, &y, &w);
        tr[x].push_back(make_pair(y, w));
        tr[y].push_back(make_pair(x, w));
    }
    for (int i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j++) {
        	ll w;
            scanf("%lld", &w);
            tr[n + i].push_back(make_pair(j, w));
            tr[j].push_back(make_pair(n + i, w));
        }
    }
    vis[1] = 1;
    dfs(1, 1, 0);
    printf("%lld\n", ans);
    return 0;
}

/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/ 

