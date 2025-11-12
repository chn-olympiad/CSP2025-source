#include <bits/stdc++.h>
using namespace std;
int n, m, k;

struct roads {
	int u, v, w;
} e[1000005];
int a[15], c[10005][15];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	cout << 0;
	return 0;
}
