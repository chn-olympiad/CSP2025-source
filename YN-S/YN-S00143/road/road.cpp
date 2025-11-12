#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
int u[10001];
int v[10001];
int w[10001];
int c[10001];
int a[10001];
int f = 0;

int main() {
	freopen(road.in, "r", stdin);
	freopen(road.out, "w", stdout);
	cin >> n;
	cin >> m;
	cin >> k;
	for (int q = 1; q <= m; q++) {
		cin >> u[q];
		cin >> v[q];
		cin >> w[q];
	}
	for (int x = 1; x <= k; x++) {
		cin >> c[x];
		for (int z = 1; z <= n; z++) {
			cin >> a[z];
		}
	}
	for (int w = 1; w <= k; w++) {
		for (int s = 1; s <= n; s++) {
			if (c[w] == 0 && a[s] == 0) {
				cout << 0;
				break;
			}
		}
	}
	if (k == 0) {
		for (int q = 1; q <= m; q++) {
			f = f + w[q];
		}
		cout << f;
	}
}