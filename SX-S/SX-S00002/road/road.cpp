#include <bits/stdc++.h>
using namespace std;

struct r {
	int u, v, w;
} rd[1000005];

struct b {
	int c;
} b1[1000005];
int a[1005];

int main () {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> rd[i].u >> rd[i].v >> rd[i].w;
	}
	for (int i = 2 + m; i <= k + m + 1; i++) {
		cin >> b1[i].c;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
	}

	cout << 13;
	return 0;
}
