#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000005], v[1000005], w[1000005], c[15], a[15][10005], o, sum;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	o = m;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 1; j <= k; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
			o++;
			w[o] = a[j][i];
		}
	}
	sort(c + 1, c + 1 + k);
	sort(w + 1, w + 1 + o);
	for (int i = 1; i < k; i++) {
		sum += c[i];
	}
	for (int i = 1; i <= n; i++) {
		sum += w[i];
	}
	cout << sum;
	return 0;
}
