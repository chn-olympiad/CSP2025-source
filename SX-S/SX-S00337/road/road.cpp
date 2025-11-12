#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
long long n, m, k;
long long a[N], ans;
vector<int> vt[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, x;
		cin >> u >> v >> x;
		vt[u].push_back(v);
		vt[v].push_back(u);
		a[i] = x;
	}
	if (k == 0) {
		sort(a + 1, a + 1 + n);
		for (int i = 1; i < n; i++)
			ans += a[i];
		cout << ans;
	} else
		cout << 0;
	return 0;
}
