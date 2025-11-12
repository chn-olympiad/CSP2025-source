#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 10004, MAXM = 1000006, MAXK = 11;
ll ans, z;
int n, m, k, cnd, x, y;
int head[MAXN], edgecnt;
int ace[MAXN];
int cnt[MAXK];
ll val[MAXK], cnn[MAXK][MAXN];
pair<ll, int> tmp[MAXN];

struct E {
	int u, v, mo;
	ll w;
};
vector<E> es;

int find(int x) {
	if (ace[x] == x)
		return x;
	return (ace[x] = find(ace[x]));
}

inline void merge(int x, int y) {
	ace[find(x)] = find(y);
}

inline void init() {
	for (int i = 1; i <= n; ++i)
		ace[i] = i;
}

inline void calc(int k) {
	for (int i = 1; i <= n; ++i) {
		tmp[i].first = cnn[k][i];
		tmp[i].second = i;
	}
	sort(tmp + 1, tmp + n + 1);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= min(10, n); ++j) {
			if (i != tmp[j].second)
				es.push_back({i, tmp[j].second, k, tmp[j].first + cnn[k][i] + val[k]});
		}
	}
}

inline void solve() {
	init();
	sort(es.begin(), es.end(), [](E a, E b) {
		return a.w < b.w;
	});
	for (E e : es) {
		if (find(e.u) != find(e.v)) {
			merge(e.u, e.v);
			ans += e.w;
			++cnt[e.mo];
			++cnd;
			if (cnd == n - 1)
				return;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y >> z;
		es.push_back({x, y, 0, z});
	}
	
	for (int i = 1; i <= k; ++i) {
		cin >> val[i];
		for (int j = 1; j <= n; ++j)
			cin >> cnn[i][j];
	}
	
	for (int kk = 1; kk <= k; ++kk)
		calc(kk);
	solve();
	
	for (int i = 1; i <= k; ++i) {
		if (cnt[i] > 0)
			ans -= (cnt[i] - 1) * val[i];
	}
	cout << ans << '\n';
	return 0;
}
