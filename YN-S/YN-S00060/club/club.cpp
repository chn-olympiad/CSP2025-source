#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int x1, y11, z1, n, x, y, t, z, k, a[maxn], b[maxn], c[maxn], vis[maxn];

bool cmp(int a, int b) {
	if (a > b) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);

	while (t--) {
		x = 0, y = 0, z = 0, k = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {

			scanf("%d %d %d", &a[i], &b[i], &c[i]);
		}

		int l = n / 2;

		for (int i = 1; i <= n; i++) {

			if (a[i] > x) {
				x = a[i], x1 = i;
			}

			if (b[i] > y) {
				y = b[i], y11 = i;
			}

			if (c[i] > z) {
				z = c[i], z1 = i;
			}
		}

		if (c[1] == 0) {
			sort(a + 1, a + n + 1, cmp);
			sort(b + 1, b + n + 1, cmp);
			sort(c + 1, c + n + 1, cmp);

			if (b[1] == 0) {
				for (int i = 1; i <= l; i++) {

					k += a[i];
				}

				for (int i = 1; i <= n; i++) {

					vis[i] = 1;
				}

				printf("%d\n", k);
				continue;
			} else {
				for (int i = 1; i <= n; i++) {

					vis[i] = 1;

					if (a[i] > b[i]) {
						k += a[i];
					} else {
						k += b[i];
					}
				}

				printf("%d\n", k);
			}
		}

		for (int i = 1; i <= n; i++) {

			if (vis[i]) {
				continue;
			} else {
				if (a[i] > b[i] && a[i] > c[i]) {
					x++;
					k += a[i];
					vis[i] = 1;
				}

				if (b[i] > a[i] && b[i] > c[i]) {
					y++;
					k += b[i];
					vis[i] = 1;
				}

				if (c[i] > a[i] && c[i] > b[i]) {
					z++;
					k += c[i];
					vis[i] = 1;
				}
			}

		}

		printf("%d\n", k);
	}

	return 0;
}