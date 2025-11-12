#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 10011;
int n, m, k, a[11][N], c[11];
vector<int> d;

inline void solve() {
	scanf("%d%d%d", &n, &m, &k);
	if (!k) {
		ll ans = 0;
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			ans += w;
		}
		printf("%lld\n", ans);
		return;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		d.push_back(w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	sort(d.begin(), d.end());
	ll ans = 0;
	int cnt = n * k, top = 0;	
	while (cnt <= m) {
		++cnt;
		ans += d[top++];
	}
	printf("%d\n", ans);
	return;
}


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int test = 1;
	while (test--) {	
		solve();
	}
	return 0;	
}
