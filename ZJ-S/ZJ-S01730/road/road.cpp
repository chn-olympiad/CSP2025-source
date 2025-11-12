#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(nullptr); \
cout.tie(nullptr);
void fr() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}
ll n, m, k, u, v, w, ans = INT_MAX;
bool dis[10005];
vector <pair<ll, ll>> G[10005];
void bfs(ll x) {
	memset(dis, 0, sizeof dis);
	queue <ll> q;
	q.push(x);
	dis[x] = 1;
	ll p = 1, len = 0;
	while(q.size()) {
		ll now = q.front();
		q.pop();
		if (p == n) {
			break;
		}
		for (int i = 0; i < G[now].size(); i++) {
			ll op = G[now][i].first;
			if (!dis[op]) {
				dis[op] = 1;
				p++;
				len += G[now][i].second;
				q.push(op);
			}
		}
	}
	ans = (ans < len ? ans : len);
}
int main() {
	fr();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	cout << ans;
	return 0;
}

