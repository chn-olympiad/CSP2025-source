#include <bits/stdc++.h>
using namespace std;

struct ui {
	int u, v, w;
} f[1100005];
int fa[10025], k1[11][10025];

bool cmp(ui xx, ui yy) {
	return xx.w < yy.w;
}

int we(int x) {
	if (fa[x] == x)
		return x;
	fa[x] = we(fa[x]);
	return fa[x];
}

void er(int x, int y) {
	fa[we(x)] = we(y);
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n + 10; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> f[i].u >> f[i].v >> f[i].w;
	}
	int op = 1;
	for (int i = 1; i <= k; i++) {
		cin >> k1[i][0];
		if (k1[i][0] != 0)
			op = 0;
		for (int j = 1; j <= n; j++) {
			cin >> k1[i][j];
		}
	}
	if (k == 0) {
		sort(f + 1, f + m + 1, cmp);
		int ans = 0, kl = 0;
		for (int i = 1; i <= m; i++) {
			if (we(f[i].u) != we(f[i].v)) {
				ans += f[i].w;
				er(f[i].u, f[i].v);
				kl++;
			}
			if (kl == n - 1)
				break;
		}
		cout << ans;
	} else if (op == 1) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				if (k1[i][j] == 0)
					er(i + n, j);
				else {
					m++;
					f[m].u = i + n;
					f[m].v = j;
					f[m].w = k1[i][j];
				}
			}
		}
		n += k;
		sort(f + 1, f + m + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			if (we(f[i].u) != we(f[i].v)) {
				ans += f[i].w;
				er(f[i].u, f[i].v);
			}
		}
		cout << ans;
	} else if (op == 0 && k == 1) {
		int ans = 0;
		for (int i = 1; i < n; i++) {
			ans += f[i].w;
		}
		cout << ans;
	}
	return 0;
}
