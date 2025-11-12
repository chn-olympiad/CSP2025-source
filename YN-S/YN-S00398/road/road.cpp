#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int u[maxn], v[maxn], w[maxn];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, b, ans = 0;
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++)

		cin >> u[i] >> v[i] >> w[i];

	for (int i = 1; i <= m + 1; i++)

		cin >> b;

	for (int i = 1; i <= m; i++)

		ans += w[i];
	cout << ans;
	return 0;
}