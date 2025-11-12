#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int Max = 1e4+5;
int n, m, k, u, v;
ll w, x, y;
int a[Max][Max];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}
	for (int j = 1; j <= k; j++) {
		cin >> x;
		for (int tep = 1; tep <= m; tep++) {
			cin >> y;
			a[j][tep] = y;
			a[tep][j] = y;
		}
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += a[i][j];
		}
	}
	ll ans = sum / 2;
	cout << ans;
	return 0;
}
