#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forl(i, j, k) for(int (i) = (j); (i) <= (k); (i)++)
#define forr(i, j, k) for(int (i) = (j); (i) >= (k); (i)--)
#define er(a) cout << "err: " << (a) << '\n';
#define pii pair<int, int>
const int N = 1e4+5, INF = 0x3f3f3f3f;
int T;
int n, m, k, ans;

//priority_queue<node> e;
bool vis[N];
//int maxn;
vector<pii> e[N];
priority_queue<pii> q;

void solve() {
	cin >> n >> m >> k;
	forl(i, 1, m) {
		int u, v, k;
		cin >> u >> v >> k;
		if (u > v) swap(u, v);
		e[u].emplace_back({k, v});
		e[v].emplace_back({k, u});
	}
	forl(i, 1, k) {
		int c;
		cin >> c;
		forl(j, 1, n) {
			int t;
			cin >> t;
		}
	}
	q.push({0, 1});
	vis[1] = 1;
	while (!q.empty()) {
		pii t = q.top();
		q.pop();
		ans += t.first;
		for(pii s: e[t.second]) {
			if (vis[s.second]) continue;
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

/*
dp
tree
贪心
二分
线段树
数学 
*/
