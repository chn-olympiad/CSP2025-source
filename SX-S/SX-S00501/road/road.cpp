#include <bits/stdc++.h>
using namespace std;
bool ma[1000][1000];
int w[1000010];
long long sum;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, cnt = 1;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v >> w[cnt++];
		ma[u][v] = 1;
		ma[v][u] = 1;
	}
	if (k == 0) {
		sort(w + 1, w + n + 1);
		for (int i = 1; i <= n; i++) {
			sum += w[i];
		}
		cout << sum;
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			w[cnt++] = a;
		}
	}
	sort(w + 1, w + n + 1);
	for (int i = 1; i <= n; i++) {
		sum += w[i];
	}
	cout << sum;
	return 0;
}
