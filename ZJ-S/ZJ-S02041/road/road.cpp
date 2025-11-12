#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 2e4 + 7, M = 2e6;
int n, m, k, u[M], v[M], w[M];
int Min[N];
struct Node {
	int fri;
	int w;
};
void IOS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	return ;
}
void file() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	return ;
}
void __init() {
	file(), IOS();
	return ;
}
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> u[i] >> v[i] >> w[i];
		Min[u[i]] = min(Min[u[i]], w[i]);
		Min[v[i]] = min(Min[v[i]], w[i]);
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += Min[i];
	}
	cout << ans << '\n';
	return ;
}
int main(void) {
	__init();
	LL _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}
