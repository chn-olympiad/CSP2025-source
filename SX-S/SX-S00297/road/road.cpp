#include <bits/stdc++.h>
using namespace std;
int e[1000010], ne[1000010], h[1000010], idx = 0, w[1000010], c[1000010], a[20][100010];
bool f[100010];

void add(int x, int y, int z) {
	e[idx] = y;
	ne[idx] = h[x];
	w[idx] = min(w[idx], z);
	h[x] = idx++;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, l;
	cin >> n >> m >> l;
	memset(h, -1, sizeof h);
	memset(w, 0x3f, sizeof w);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 1; i <= l; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				int x = c[i] + a[i][j] + a[i][k];
				add(j, k, x);
				add(k, j, x);
			}
		}
	}
	int wm = 0;
	for (int i = 1; i <= n; i++) {
		int x = 0x3f, y;
		for (int k = h[i]; k != -1; k = ne[k]) {
			if (f[y] == false) {
				x = min(w[k], x);
				y = k;
			}
		}
		wm += x;
		f[y] = true;
	}
	cout << wm;
	return 0;
}