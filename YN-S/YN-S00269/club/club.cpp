#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;

struct node {
	int id, v, na;
} a[N], b[N], c[N];

int t, n, sum, pfb, pfc;
int vis[N];

bool cmp1(node x, node y) {
	if (x.na != y.na)
		return x.na < y.na;
	else
		return x.v > y.v;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].v >> b[i].v  >> c[i].v ;
			a[i].id = b[i].id = c[i].id = i;
			if (a[i].v >= b[i].v && a[i].v >= c[i].v)
				a[i].na = 1;
			if (b[i].v >= a[i].v && b[i].v >= c[i].v)
				b[i].na = 1;
			if (c[i].v >= b[i].v && c[i].v >= a[i].v)
				c[i].na = 1;
			if (a[i].v >= b[i].v && a[i].v <= c[i].v)
				a[i].na = 2;
			if (a[i].v <= b[i].v && a[i].v >= c[i].v)
				a[i].na = 2;
			if (b[i].v >= a[i].v && b[i].v <= c[i].v)
				b[i].na = 2;
			if (b[i].v <= a[i].v && b[i].v >= c[i].v)
				b[i].na = 2;
			if (c[i].v >= b[i].v && c[i].v <= a[i].v)
				c[i].na = 2;
			if (c[i].v <= b[i].v && c[i].v >= a[i].v)
				c[i].na = 2;
			if (a[i].v <= b[i].v && a[i].v <= c[i].v)
				a[i].na = 3;
			if (b[i].v <= a[i].v && b[i].v <= c[i].v)
				b[i].na = 3;
			if (c[i].v <= b[i].v && c[i].v <= a[i].v)
				c[i].na = 3;
			if (b[i].v == 0)
				pfb++;
			if (c[i].v == 0)
				pfc++;
		}

		if (pfc == n) {

			if (pfb == n) {
				sort(a + 1, a + n + 1, cmp1);
				for (int i = 1; i <= n / 2; i++) {
					sum += a[i].v;
				}
				cout << sum;
				continue;
			} else {
				sort(a + 1, a + n + 1, cmp1);
				sort(b + 1, b + n + 1, cmp1);
				int x = 1, y = 1;
				while (1) {
					if (x >= n && y >= n )
						break;
					if (vis[a[x].id]) {
						x++;
						continue;
					}
					if (vis[b[y].id]) {
						y++;
						continue;
					}
					if (a[x].v >= b[y].v && x <= n / 2) {
						sum += a[x].v;
						vis[a[x].id] = 1;
						x++;
						continue;
					} else  {
						sum += b[y].v;
						vis[b[y].id] = 1;
						y++;
						continue;
					}

				}
				memset(vis, 0, sizeof(vis));
				cout << sum;
				sum = 0;
				continue;
			}
		}
		sort(a + 1, a + n + 1, cmp1);
		sort(b + 1, b + n + 1, cmp1);
		sort(c + 1, c + n + 1, cmp1);
		int x = 1, y = 1, z = 1;
		while (1) {
			if (x >= n && y >= n && z >= n)
				break;
			if (vis[a[x].id]) {
				x++;
				continue;
			}
			if (vis[b[y].id]) {
				y++;
				continue;
			}
			if (vis[c[z].id]) {
				z++;
				continue;
			}
			if (a[x].v >= b[y].v && a[x].v >= c[z].v && x <= n / 2) {
				sum += a[x].v;
				vis[a[x].id] = 1;
				x++;
				continue;
			}
			if (x > n / 2)
				x = n + 1;
			if (b[y].v >= a[x].v && b[y].v >= c[z].v && y <= n / 2) {
				sum += b[y].v;
				vis[b[y].id] = 1;
				y++;
				continue;
			}
			if (y > n / 2)
				y = n + 1;
			if (c[z].v >= b[y].v && c[z].v >= a[x].v && z <= n / 2) {
				sum += c[z].v;
				vis[c[z].id] = 1;
				z++;
			}
			if (z > n / 2)
				z = n + 1;

		}
		memset(vis, 0, sizeof(vis));
		cout << sum;
		sum = 0;
	}
	return 0;
}
